#include "mcc/hashmap.h"
#include "mcc/arena.h"
#include "mcc/util.h"

typedef struct foo {
  int x;
  int y;
  int z;
} Foo;

int main(int argc, char** argv) {
  Arena* arena = arena_create(sizeof(Foo), 256);
  while (arena_alloc(arena) != ARENA_ALLOC_ERROR_);
  arena_grow(arena, 500);
  while (arena_alloc(arena) != ARENA_ALLOC_ERROR_);
  arena_dump(arena);
  return 0;
}

