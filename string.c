#include "string.h"

String_array_ptr init_string_array(size_t length)
{
  String_array_ptr string_array = malloc(sizeof(String_array));
  string_array->length = length;
  string_array->strings = malloc(sizeof(Char_ptr) * length);

  return string_array;
}

String_array_ptr string_array_from(Char_ptr *strings, size_t length)
{
  String_array_ptr string_array = init_string_array(length);

  for (size_t i = 0; i < length; i++)
  {
    string_array->strings[i] = strings[i];
  }

  return string_array;
}

void print_strings(Char_ptr message, String_array_ptr strings)
{
  printf("%s\n", message);
  for (size_t i = 0; i < strings->length; i++)
  {
    printf("%s\n", strings->strings[i]);
  }
  printf("\n");
}

size_t count_chars(Char_ptr string)
{
  size_t count = 0;

  while (string[count] != '\0')
  {
    ++count;
  }

  return count;
}

Char_ptr slice(Char_ptr string, size_t from, size_t to)
{
  Char_ptr sliced_string = malloc((to - from) + 1);
  size_t slice_index = 0;

  for (size_t i = from; i < to; i++)
  {
    sliced_string[slice_index] = string[i];
    ++slice_index;
  }
  sliced_string[slice_index] = '\0';

  return sliced_string;
}

String_array_ptr split(Char_ptr string, char delimiter)
{
  size_t length_of_string = count_chars(string);
  Char_ptr result[length_of_string];
  size_t prev_index = 0, result_index = 0;

  for (size_t i = 0; i < length_of_string; i++)
  {
    if (string[i] == delimiter)
    {
      result[result_index] = slice(string, prev_index, i);
      prev_index = i + 1;
      ++result_index;
    }
  }

  result[result_index] = slice(string, prev_index, length_of_string);
  ++result_index;

  return string_array_from(result, result_index);
}
