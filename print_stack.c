#include "monty.h"

/**
 * pall_stack - print elements of a stack
 * @stack - pointer to the stack
 * @line_num: line number
 *
 * Return: number of nodes
 */
void pall_stack(s_node *stack, unsigned int line_num)
{
	s_node temp = NULL;
	int nodes = 0;

	(void)line_num;

	if (stack)
	{
		temp = (*stack)->next;
		nodes++;
		while (temp->next != NULL)
			temp = temp->next;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
			nodes++;
		}
	}
}
