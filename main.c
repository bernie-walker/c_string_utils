#include <stdio.h>
#include "string.h"

int main(void)
{
  String_array_ptr x = split_no_realloc("this,is,i,t", ',');
  print_strings("Split string", x);
  printf("%ld\n", x->length);
  return 0;
}