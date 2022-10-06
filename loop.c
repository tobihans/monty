#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "monty.h"


/**
 * loop - Loop over each line of bytecode and execute it
 *
 * @bytecode: The opened stream of bytecode
 *
 * Return: void, always
 */
void loop(FILE *bytecode)
{
  char *line;
  int status, line_number;
  size_t n;

  line_number = 1;

  while (1)
  {
    status = getline(&line, &n, bytecode);

    /* TODO: make distinction between EOF and error */
    if (status == -1)
    	exit(EXIT_SUCCESS);

    printf("%s", line);

  	line_number++;
  }
}
