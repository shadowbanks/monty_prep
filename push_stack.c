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

	(void)line_num;

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
