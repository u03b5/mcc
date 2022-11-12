#ifndef UTIL_H_
#define UTIL_H_

#include <stddef.h>

#define MIN(x, y) \
  ((x < y) ? x : y)

#define MAX(x, y) \
  ((x < y) ? y : x)

#define ALLOC_(type, ...) \
  (type *)memdup((type []){__VA_ARGS__}, sizeof(type))

void* memdup(const void* src, size_t size);
#endif // UTIL_H_
