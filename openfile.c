#include "monty.h"

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

void handle_opcode(s_node *stack, int str_len, char *op, int *line_num)
{
	char *code = NULL;
	int i = 0;

	instruction_t oper[] = {
		{"push", push_to_stack},
		{"pall", pall_stack},
		{NULL, NULL}
	};

	/*Check if Line is empty*/
	if (str_len && !blank_line(op))
	{
		++(*line_num);/*Line number*/
		/*Remove newline if it exist from the opcode read*/
		if (op[strlen(op) - 1] == '\n')
			op[strlen(op) - 1] = '\0';
		/*Loop to find the command to execute*/
		for (;, oper[i].opcode != NULL; i++)
		{
			if (!strcmp(oper[i].opcode, op))
			{
				if (!strcmp(op, "push"))
				{
					code = strtok(NULL, " ");
					if (code == NULL)
						code_err(*line_num, op);
					if (code[strlen(code) - 1] == '\n')
						code[strlen(code) - 1] = '\0';
					data = atoi(code);
					if (data == 0 && strcmp(code, "0"))
						code_err(*line_num, op);
				}
				oper[i].f(stack, *line_num);
				return;
			}
		}
		unknown(line_num, op);
	}
	/*
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
		*/
}
void code_err(char *op, int *line_num)
{
	fprintf(stderr, "L%d: usage: push integer\n", *line_num);
	exit(EXIT_FAILURE);
}
void unknown(char *op, int *line_num)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", *line_num, op);
	exit(EXIT_FAILURE);
}
