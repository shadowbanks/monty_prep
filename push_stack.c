#include "monty.h"

/**
 * push_stack - Add to the top of a stack
 * @n: data to be stored
 *
 * Return: nothing
 */
void push_to_stack(s_node *stack, int line_num)
{
	s_node new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;
	new_node->n = data;

	if (top == NULL)
		new_node->prev = NULL;
	else
		new_node->prev = top;
}
