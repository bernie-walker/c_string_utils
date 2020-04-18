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
  resized_array->strings = realloc(string_array->strings, (8 * length));

  if (resized_array->strings == NULL)
  {
    NO_MEMORY_ERROR;
    exit(1);
  }

  // free(string_array->strings);
  free(string_array);
  return resized_array;
}

String_array_ptr get_custom_string_array(Char_ptr *strings, size_t length)
{
  String_array_ptr custom_string_array = malloc(sizeof(String_array));
  custom_string_array->length = length;
  custom_string_array->strings = realloc(strings, length);

  if (custom_string_array->strings == NULL)
  {
    NO_MEMORY_ERROR;
    exit(1);
  }

  free(strings);
  return custom_string_array;
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

String_array_ptr split(Char_ptr string, char delimiter)
{
  size_t length_of_string = count_chars(string);
  String_array_ptr result = init_string_array(length_of_string);
  size_t prev_index = 0, result_index = 0;

  for (size_t i = 0; i < length_of_string; i++)
  {
    if (string[i] == delimiter)
    {
      result->strings[result_index] = slice(string, prev_index, i);
      prev_index = i + 1;
      ++result_index;
    }
  }

  result->strings[result_index] = slice(string, prev_index, length_of_string);
  ++result_index;

  return resize_array(result, result_index);
}
