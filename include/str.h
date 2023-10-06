#ifndef str_h
#define str_h

#include <stdint.h>

typedef struct {
  uint32_t length;
  char *chars;
} str;

typedef struct {
  uint8_t size;
  char *bytes;
} rune;

str init_str(const char *chars);
str add_chars(const char *a, const char *b);
str add_strs(str a, str b);
void print_runes(str string);
rune get_rune(str string);
void free_str(str string);

#endif
