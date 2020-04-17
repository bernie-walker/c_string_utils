#include "string.h"

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

Char_ptr slice(Char_ptr string, size_t count)
{
  Char_ptr sliced_string = malloc(count + 1);

  for (size_t i = 0; i < count; i++)
  {
    sliced_string[i] = string[i];
  }
  sliced_string[count + 1] = '\0';

  return sliced_string;
}