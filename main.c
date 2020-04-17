#include <stdio.h>
#include "string.h"

int main(void)
{
  String_array_ptr string_array = init_string_array(3);

  string_array->strings[0] = "this";
  string_array->strings[1] = "is";
  string_array->strings[2] = "it";

  print_strings("Strings Array", string_array);

  return 0;
}