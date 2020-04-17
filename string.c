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