#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

#define KANA_ENCODE_LENGTH 0x000E
#define HIRAGANA_START 0x3041
#define HIRAGANA_END 0x3096
#define KATAKANA_START 0x30A1
#define KATAKANA_END 0x30FC

bool is_kana(char *string, size_t length) {
  if (length < 1) {
    return false;
  }
  size_t idx = 0;
  while (idx < length) {
    unsigned char first_byte = string[idx];
    uint8_t encode_length = first_byte >> 4;
    if (encode_length != KANA_ENCODE_LENGTH) {
      return false;
    }
    unsigned int unicode = 0;
    unsigned char second_byte = string[++idx];
    unsigned char third_byte = string[++idx];
    // Grab the leftmost two bits of the first byte,
    // and the rightmost six bits of the other two bytes.
    unicode += (unsigned int)(first_byte << 28) >> 16;
    unicode += (unsigned int)(second_byte << 26) >> 20;
    unicode += (unsigned int)(third_byte << 26) >> 26;
    if ((unicode < HIRAGANA_START || unicode > HIRAGANA_END) &&
        (unicode < KATAKANA_START || unicode > KATAKANA_END)) {
      return false;
    }
    idx++;
  }
  return true;
}
