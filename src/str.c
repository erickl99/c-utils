#include "str.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

str init_str(const char *raw_chars) {
  size_t length = strlen(raw_chars);
  char *chars = malloc(length + 1);
  memcpy(chars, raw_chars, length);
  chars[length] = '\0';
  str new_str = {.length = length, .chars = chars};
  return new_str;
}

str add_chars(const char *a, const char *b) {
  str new_str = {.length = 0, .chars = NULL};
  size_t a_len = strlen(a);
  size_t b_len = strlen(b);
  size_t length = a_len + b_len;
  if (length < a_len || length < b_len || length + 1 < length) {
    return new_str;
  }
  char *chars = malloc(length + 1);
  memcpy(chars, a, a_len);
  memcpy(chars + a_len, b, b_len);
  chars[length] = '\0';
  new_str.length = length;
  new_str.chars = chars;
  return new_str;
}

str add_strs(str a, str b) {
  str new_str = {.length = 0, .chars = NULL};
  size_t a_len = a.length;
  size_t b_len = b.length;
  size_t length = a_len + b_len;
  if (length < a_len || length < b_len || length + 1 < length) {
    return new_str;
  }
  char *chars = malloc(length + 1);
  memcpy(chars, a.chars, a_len);
  memcpy(chars + a_len, b.chars, b_len);
  chars[length] = '\0';
  new_str.length = length;
  new_str.chars = chars;
  return new_str;
}

void print_runes(str string) {
  uint32_t i = 0;
  while (i < string.length) {
    switch ((uint8_t)string.chars[i] >> 4) {
    case 15: {
      printf("Here is the rune: %.*s\n", 4, string.chars + i);
      i += 3;
      break;
    }
    case 14: {
      printf("Here is the rune: %.*s\n", 3, string.chars + i);
      i += 2;
      break;
    }
    case 13:
    case 12: {
      printf("Here is the rune: %.*s\n", 2, string.chars + i);
      i += 1;
      break;
    }
    default: {
      printf("Good old american ascii: %c\n", string.chars[i]);
    }
    }
    i++;
  }
}

void free_str(str string) { free(string.chars); }
