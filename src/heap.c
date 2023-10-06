#include "heap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define HEAP_GROWTH_FACTOR 2
#define HEAP_INIT_CAPACITY 10

void heap_init(heap *hp) {
  hp->count = 0;
  hp->capacity = 0;
  hp->nums = NULL;
}

static void fix_heap_up(heap *hp, int idx) {
  if (idx > 0) {
    int par_idx = (idx - 1) / 2;
    if (hp->nums[idx] < hp->nums[par_idx]) {
      int temp = hp->nums[idx];
      hp->nums[idx] = hp->nums[par_idx];
      hp->nums[par_idx] = temp;
      fix_heap_up(hp, par_idx);
    }
  }
}

void heap_add(heap *hp, int num) {
  if (hp->count + 1 > hp->capacity) {
    size_t new_cap = hp->capacity == 0 ? HEAP_INIT_CAPACITY
                                       : hp->capacity * HEAP_GROWTH_FACTOR;
    hp->nums = realloc(hp->nums, sizeof(int) * new_cap);
    hp->capacity = new_cap;
  }
  hp->nums[hp->count++] = num;
  fix_heap_up(hp, hp->count - 1);
}

int heap_peek(heap *hp) { return *hp->nums; }

static void fix_heap_down(heap *hp, int idx) {
  int len = hp->count - 1;
  int child_idx = -1;
  int dbl_idx = 2 * idx + 1;
  if (dbl_idx > len) {
    return;
  } else if (dbl_idx < len) {
    int left = hp->nums[dbl_idx];
    int right = hp->nums[dbl_idx + 1];
    child_idx = left < right ? dbl_idx : dbl_idx + 1;
  } else {
    child_idx = dbl_idx;
  }
  if (hp->nums[idx] > hp->nums[child_idx]) {
    int temp = hp->nums[idx];
    hp->nums[idx] = hp->nums[child_idx];
    hp->nums[child_idx] = temp;
    fix_heap_down(hp, child_idx);
  }
}

void heap_remove(heap *hp, int idx) {
  hp->nums[idx] = hp->nums[--hp->count];
  fix_heap_up(hp, idx);
  fix_heap_down(hp, idx);
}

void heap_free(heap *hp) {
  if (hp->nums != NULL) {
    free(hp->nums);
  }
}
