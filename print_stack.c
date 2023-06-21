#include "monty.h"

/**
 * pall_stack - print elements of a stack
 * @stack - pointer to the stack
 * @line_num: line number
 *
 * Return: number of nodes
 */
size_t pall_stack(s_node *stack, unsigned int line_num)
{
	s_node temp = NULL;
	int nodes = 0;

	if (stack)
	{
		temp = (*stack)->next;
		node++;
		while (temp->next != NULL)
			temp = temp->next;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
			nodes++;
		}
	}

	return (nodes);
}
