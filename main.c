#include <stdio.h>
#include "string.h"

int main(void)
{
  char name[] = "Bernard Nehal Dcunha";

  printf("Slice name is -%s-\n", slice(name, 7));

  return 0;
}