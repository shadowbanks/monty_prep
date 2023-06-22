#include "monty.h"

/**
 * pop_stack - Remove the top element of a stack
 * @stack: pointer to a stack
 * @line_num: Line number where the command was found
 */
void pop_stack(s_node *stack, unsigned int line_num)
{
	s_node temp = NULL;

	(void)stack;
	temp = my_node->current;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_stack();
		fclose(my_node->fd);
		free(my_node);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	free(my_node->current);
	my_node->current = temp;
}
