#include "monty.h"

/**
 * pall_stack - print elements of a stack
 * @stack: pointer to the stack
 * @line_num: line number
 *
 * Return: number of nodes
 */
void pall_stack(s_node *stack, unsigned int line_num)
{
	s_node temp = NULL;

	(void)line_num;
	(void)stack;

	if (my_node->current == NULL)
		return;

	temp = my_node->current;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
