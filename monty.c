#include "monty.h"

/**
 * main - Monty interpreter
 * @ac: argument counter
 * @av: argument variables
 *
 * Return: 0 (on success)
 */
int main(int ac, char **av)
{
	FILE *fd;
	char *op = NULL;
	int line_num = 0;
	int str_len = 0;
	char line[LINE_LENGTH];
	s_node stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fd) != NULL)
	{
		op = strtok(line, " ");
		str_len = strlen(op);
		handle_opcode(&stack, str_len, op, &line_num);
	}

	return (0);
}
