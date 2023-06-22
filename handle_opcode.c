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

/**
 * handle_opcode - Determine which function to handle each command
 * @stack: pointer to stack
 * @str_len: length of command
 * @op: command passed
 * @line_num: line number of command
 *
 * Return: Nothing
 */
void handle_opcode(s_node *stack, int str_len, char *op, int *line_num)
{
	int i = 0;

	instruction_t oper[] = {
		{"push", push_to_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap},
		{"add", add_2top},
		{"nop", nop},
		{"sub", sub_2top},
		{"div", div_2top},
		{"mul", mul_2top},
		{"mod", mod_2top},
		{NULL, NULL}
	};

	/*Check if Line is empty*/
	if (str_len && !blank_line(op))
	{
		/*Line number*/
		++(*line_num);
		/*Remove newline if it exist from the opcode read*/
		if (op[strlen(op) - 1] == '\n')
			op[strlen(op) - 1] = '\0';
		/*Loop to find the command to execute*/
		for (i = 0; oper[i].opcode != NULL; i++)
		{
			if (strncmp(oper[i].opcode, op, strlen(oper[i].opcode)) == 0)
			{
				oper[i].f(stack, *line_num);
				return;
			}
		}
		unknown(op, line_num);
	}
}
