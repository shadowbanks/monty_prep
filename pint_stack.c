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
	(void)stack;

	if (my_node->current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_stack();
		fclose(my_node->fd);
		free(my_node);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", my_node->current->n);
}
