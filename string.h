#include <stdio.h>
#include <stdlib.h>

#ifndef __STRING_H_
#define __STRING_H_

typedef char *Char_ptr;

typedef struct
{
  size_t length;
  Char_ptr *strings;
} String_array;

typedef String_array *String_array_ptr;

String_array_ptr init_string_array(size_t);

size_t count_chars(Char_ptr);

Char_ptr slice(Char_ptr, size_t);

void print_strings(Char_ptr, String_array_ptr);

#endif // !__STRING_H_