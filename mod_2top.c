#include "monty.h"

/**
 * mod_2top - Divide the 2 topmost element of a stack
 * @stack: pointer to stack
 * @line_num: Line number of command passed
 */
void mod_2top(s_node *stack, unsigned int line_num)
{
	int node_num = 0;
	s_node temp = NULL;

	(void)stack;
	node_num = node_count();

	if (node_num > 1)
	{
		temp = my_node->current->next;
		if (my_node->current->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_num);
			free_stack();
			fclose(my_node->fd);
			free(my_node);
			exit(EXIT_FAILURE);
		}
		temp->n = temp->n % my_node->current->n;
		free(my_node->current);
		my_node->current = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		free_stack();
		fclose(my_node->fd);
		free(my_node);
		exit(EXIT_FAILURE);
	}
}
