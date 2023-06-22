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
	char *code = NULL, *conv_num = NULL;
	int i = 0;

	instruction_t oper[] = {
		{"push", push_to_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
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
				if (!strcmp(op, "push"))
				{
					code = strtok(NULL, " ");
					if (code == NULL)
						code_err(line_num);
					if (code[strlen(code) - 1] == '\n')
						code[strlen(code) - 1] = '\0';
					my_node->data = strtol(code, &conv_num, 10);
					if (*conv_num != '\0')
						code_err(line_num);
				}
				oper[i].f(stack, *line_num);
				return;
			}
		}
		unknown(op, line_num);
	}
}