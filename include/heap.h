#ifndef heap_h
#define heap_h

#include <stdarg.h>

typedef struct {
  int capacity;
  int count;
  int *nums;
} heap;

void heap_init(heap *hp);
void heap_add(heap *hp, int num);
int heap_peek(heap *hp);
void heap_remove(heap *hp, int idx);
void heap_free(heap *hp);

#endif
