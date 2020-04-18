#include "string.h"

String_array_ptr init_string_array(size_t length)
{
  String_array_ptr string_array = malloc(sizeof(String_array));
  string_array->length = length;
  string_array->strings = malloc(sizeof(Char_ptr) * length);

  return string_array;
}

String_array_ptr resize_array(String_array_ptr string_array, size_t length)
{
  String_array_ptr resized_array = malloc(sizeof(String_array));
  resized_array->length = length;
  resized_array->strings = realloc(string_array->strings, length);

  if (resized_array->strings == NULL)
  {
    NO_MEMORY_ERROR;
    exit(1);
  }

  free(string_array->strings);
  free(string_array);
  return resized_array;
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

  while (1)
  {
    if (string[count] == '\0')
    {
      break;
    }
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
