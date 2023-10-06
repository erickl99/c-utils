#include "str.h"
#include "heap.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  str en = init_str("hello world");
  str jap = init_str("こんにちは");
  print_runes(en);
  print_runes(jap);
  free_str(en);
  free_str(jap);
  printf("\n");
  return 0;
}
