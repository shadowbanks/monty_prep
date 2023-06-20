#include "monty.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	FILE *fd;
	ssize_t nread;
	size_t n = 0;
	char *line = NULL, *op = NULL, *code = NULL;
	int line_num = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", av[1]);
		exit (EXIT_FAILURE);
	}

	while (nread = getline(&line, &n, fd) != -1)
	{
		op = strtok(line, " ");
		if (!strcmp(op, "push"))
		{
			++line_num;
			code = strtok(NULL, " ");
			printf("op: %s, code: %s\n", op, code);
		}
		else if (!strcmp(op, "pall"))
		{
			++line_num;
			printf("op: %s\n", op);
		}
		else if (op)
			fprintf(stderr, "L%d: unknown instruction %s\n", ++line_num, op);
	}

	return (0);
}	
