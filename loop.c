#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
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
  int status;
  unsigned int line_number;
  size_t n;

  line_number = 1;

  while (1)
  {
    status = getline(&line, &n, bytecode);

    /* TODO: make distinction between EOF and error */
    if (status == -1)
      break;

    if (line == NULL || strcmp(line, "\n") == 0)
      continue;

    trim(line);

    if (line != NULL && strlen(line) > 0)
      parse(line, line_number);

  	line_number++;
  }
}

void parse(char *line, unsigned int line_number)
{
  char *opcode = NULL, __attribute__((__unused__)) *arg = NULL;
  
  /*int bufsize, pos;*/
  /* bufsize = INITIAL_BUF_SIZE;*/
  /* pos = line_number;*/


  opcode = strtok(line, ARGS_DELIM);
  arg = strtok(NULL, ARGS_DELIM);
  
  if (strcmp(opcode, "push") == 0)
  {
    printf("This is a push code\n");
  }
  else if (strcmp(opcode, "pall") == 0)
  {
    printf("pall code\n");
  }
  else
  {
    fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
  }
}

