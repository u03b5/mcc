#include <stdlib.h>

#include "mcc/hashmap.h"
#include "mcc/util.h"

#define _HASHMAP_INITIAL 32

struct entry {
  const char* key;
  void* value;
};

Hashmap* hashmap_create(void) {}

void hashmap_destroy(Hashmap* hashmap) {}
int hashmap_load(Hashmap* hashmap, const Entry** buffer) {}
int hashmap_insert(Hashmap* hashmap, const char* key, void* value) {}
int hashmap_remove(Hashmap* hashmap, const char* key) {}
void* hashmap_retrieve(Hashmap* hashmap, const char* key) {}
int hashmap_resize(Hashmap* hashmap) {}
int hashmap_purge(Hashmap* hashmap) {}
#ifdef _MCC_DEBUG
void hashmap_dump(Hashmap* hashmap) {}
void hashmap_test(void) {
  Hashmap* hashmap = hashmap_create();


  hashmap_destroy(hashmap);
  return;
}
#endif // _MCC_DEBUG
