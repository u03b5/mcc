#ifndef HASHMAP_H_
#define HASHMAP_H_

#include "mcc/arena.h"

typedef struct entry Entry;

typedef struct hashmap Hashmap;
struct hashmap {
  Arena* arena;
  Entry* buffer;
  int size;
  int no_in_use;
};

Hashmap* hashmap_create(void);
void hashmap_destroy(Hashmap* hashmap);
int hashmap_load(Hashmap* hashmap, const Entry** buffer);
int hashmap_insert(Hashmap* hashmap, const char* key, void* value);
int hashmap_remove(Hashmap* hashmap, const char* key);
void* hashmap_retrieve(Hashmap* hashmap, const char* key);
int hashmap_resize(Hashmap* hashmap);
int hashmap_purge(Hashmap* hashmap);
#ifdef _MCC_DEBUG
void hashmap_dump(Hashmap* hashmap);
void hashmap_test(void);
#endif // _MCC_DEBUG
#endif // HASHMAP_H_
