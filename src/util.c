#include <stdlib.h>
#include <string.h>

#include "mcc/util.h"

void* memdup(const void* src, size_t size) {
  return memcpy(malloc(size), src, size);
}

