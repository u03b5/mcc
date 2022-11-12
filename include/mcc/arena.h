#ifndef ARENA_H_
#define ARENA_H_

#include <stdlib.h>

#define ARENA_ALLOC_ERROR_ ((void *) -1)

typedef struct chunk Chunk;
struct chunk {
  Chunk* next;  // next chunk pointer
  void* data;   // data field
};

typedef struct arena Arena;
struct arena {
  Chunk* top;
  Chunk* bottom;
  Chunk* current;
  unsigned int size;  // chunk size
  size_t capacity;    // current chunk capacity of arena
  size_t no_in_use;   // number of chunks in use
};

Arena* arena_create(unsigned int size, size_t capacity);
void arena_destroy(Arena* arena);
void* arena_alloc(Arena* arena);
void arena_free(Arena* arena, void* ptr);
void arena_grow(Arena* arena, size_t capacity);
#ifdef _MCC_DEBUG
void arena_dump(Arena* arena);
#endif // _MCC_DEBUG
#endif // ARENA_H_
