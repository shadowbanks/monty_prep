#include "monty.h"

/**
 * pint_stack - Print value of a top of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 *
 * Return: Nothing
 */
void pint_stack(s_node *stack, unsigned int line_num)
{
	s_node temp = NULL;

	(void)line_num;

	if (stack == NULL || *stack == NULL)
		return;
	temp = (*stack)->next;
	while (temp->next != NULL)
		temp = temp->next;
	printf("%d\n", temp->n);
}
