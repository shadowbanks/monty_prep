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

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	printf("Here\n");
	printf("%d\n", temp->n);
}
