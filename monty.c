#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
* main - Monty program entrypoint
*
* @argc: number of arguments
* @argv: command line arguments
*
* Return: 0, or non zero code for errors
*/
int main (int argc, char *argv[])
{
  FILE *bytecode;

  if (argc < 2)
  {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
  }

  bytecode = fopen(argv[1], "r");

  if (bytecode == NULL)
  {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  loop(bytecode);

  return (0);
}

