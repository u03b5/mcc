#include "mcc/arena.h"

static void arena_populate(Arena* arena) {
  for (int i = arena->no_in_use; i < arena->capacity; ++i) {
    arena->bottom->next = (void *)arena->bottom + arena->size;
    arena->bottom = arena->bottom->next;
  }
  return;
}

Arena* arena_create(unsigned int usable, size_t capacity) {
  Arena* arena = malloc(sizeof(Arena));
  arena->size = sizeof(Chunk *) + usable;
  arena->capacity = capacity - 1;
  arena->no_in_use = 0;
  arena->current = arena->top = arena->bottom = calloc(capacity, arena->size);
  arena_populate(arena);
  return arena;
}

void arena_destroy(Arena* arena) {
  free(arena->top);
  free(arena);
  return;
}

void* arena_alloc(Arena* arena) {
  Chunk* chunk;
  if (arena->current != arena->bottom) {
    chunk = (void *)&arena->current->data;
    arena->current = arena->current->next;
    ++arena->no_in_use;
    return chunk;
  }
  return ARENA_ALLOC_ERROR_;
}

void arena_free(Arena* arena, void* ptr) {
  Chunk* chunk;
  if (ptr) {
    chunk = (void *)ptr - 8;
    chunk->next = arena->current;
    arena->current = chunk;
    --arena->no_in_use;
  }
  return;
}

void arena_grow(Arena* arena, size_t capacity) {
  arena->capacity *= capacity;
  arena->top = realloc(arena->top, arena->capacity * arena->size);
  arena_populate(arena);  
  return;
}

#ifdef _MCC_DEBUG
void arena_dump(Arena* arena) {
  for (Chunk* tmp=arena->top; tmp!=arena->bottom; tmp=tmp->next)
    printf("Chunk @ %#lx: [Next: %#lx]\n", tmp, tmp->next);
  printf("Arena @ %#lx:\n[Top: %#lx]\n[Bottom: %#lx]\n[Current: %#lx]\nSize: %d\nCapacity: %d\n",
    arena,
    arena->top,
    arena->bottom,
    arena->current,
    arena->size,
    arena->capacity);
  return;
}
#endif // _MCC_DEBUG
