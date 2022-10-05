#include <stdlib.h>
#include <stdio.h>
#include "main.h"

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
  printf("%d %s", argc, argv[0]);
  printf("Hello world");

  return (0);
}

