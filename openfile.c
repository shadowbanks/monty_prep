#include "monty.h"

void handle_opcode(int str_len, char *op, char *code, int *);
/**
 * blank_line - check if string is empty
 * @str: string to check
 *
 * Return: 1 (if empty), 0 (if not)
 */
int blank_line(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int main(int ac, char **av)
{
	FILE *fd;
	char *op = NULL, *code = NULL;
	int line_num = 0;
	int str_len = 0;
	char line[LINE_LENGTH];

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
		handle_opcode(str_len, op, code, &line_num);
	}

	return (0);
}

void handle_opcode(int str_len, char *op, char *code, int *line_num)
{
	if (str_len && !blank_line(op))
	{
		if (!strcmp(op, "push"))
		{
			++(*line_num);
			code = strtok(NULL, " ");
			if (code[strlen(code) - 1] == '\n')
				code[strlen(code) - 1] = '\0';
			printf("op: %s, code: %s\n", op, code);
		}
		else if (!strcmp(op, "pall"))
		{
			++(*line_num);
			printf("op: %s\n", op);
		}
		else if (op)
		{
			if (op[strlen(op) - 1] == '\n')
				op[strlen(op) - 1] = '\0';
			fprintf(stderr, "L%d: unknown instruction %s\n", ++(*line_num), op);
			exit(EXIT_FAILURE);
		}
	}
}
