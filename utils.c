#include <string.h>
#include <ctype.h>
#include "monty.h"


/* trim a string inplace */
void trim(char *str)
{
  char *iter = str;
  int len = strlen(str);

  if (len == 0)
    return;

  while (isspace(iter[len - 1]))
    iter[--len] = 0;

  while (*iter && isspace(*iter))
  {
    ++iter;
    --len;
  }

  memmove(str, iter, len + 1);
}
