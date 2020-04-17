#include <stdio.h>
#include <stdlib.h>

#ifndef __STRING_H_
#define __STRING_H_

typedef char *Char_ptr;

size_t count_chars(Char_ptr);

Char_ptr slice(Char_ptr, size_t);

#endif // !__STRING_H_