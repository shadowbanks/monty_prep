#include "monty.h"

/**
 * push_to_stack - Add to the top of a stack
 * @stack: pointer to stack
 * @line_num: Line number
 *
 * Return: nothing
 */
void push_to_stack(s_node *stack, unsigned int line_num)
{
	s_node new_node = NULL;
	char *code = NULL, *conv_num = NULL;

	code = strtok(NULL, " ");
	if (code == NULL)
		code_err(line_num);
	if (code[strlen(code) - 1] == '\n')
		code[strlen(code) - 1] = '\0';
	my_node->data = strtol(code, &conv_num, 10);
	if (*conv_num != '\0')
		code_err(line_num);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_err();

	new_node->prev = NULL;
	new_node->n = my_node->data;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
		my_node->current = new_node;
		my_node->head = new_node;
		return;
	}
	new_node->next = my_node->current;
	my_node->current = new_node;
}
