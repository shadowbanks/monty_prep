#include "monty.h"

/**
 * sub_2top - Add the 2 topmost element of a stack
 * @stack: pointer to stack
 * @line_num: Line number of command passed
 */
void sub_2top(s_node *stack, unsigned int line_num)
{
	int node_num = 0;
	s_node temp = NULL;

	(void)stack;
	node_num = node_count();

	if (node_num > 1)
	{
		temp = my_node->current->next;
		temp->n = temp->n - my_node->current->n;
		free(my_node->current);
		my_node->current = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_stack();
		fclose(my_node->fd);
		free(my_node);
		exit(EXIT_FAILURE);
	}
}
