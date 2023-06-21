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
	s_node new_node = NULL, temp = NULL;

	(void)line_num;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;
	new_node->n = data;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;
}
