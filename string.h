#include <stdio.h>
#include <stdlib.h>

#ifndef __STRING_H_
#define __STRING_H_

#define NO_MEMORY_ERROR printf("Insufficient memory\n")

typedef char *Char_ptr;

typedef struct
{
  size_t length;
  Char_ptr *strings;
} String_array;

typedef String_array *String_array_ptr;

String_array_ptr init_string_array(size_t);

String_array_ptr resize_array(String_array_ptr, size_t);

String_array_ptr get_custom_string_array(Char_ptr *, size_t);

void print_strings(Char_ptr, String_array_ptr);

size_t count_chars(Char_ptr);

Char_ptr slice(Char_ptr, size_t, size_t);

String_array_ptr split(Char_ptr, char);

#endif // !__STRING_H_