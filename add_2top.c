#include "monty.h"

/**
 * add_2top - swap the data of the top two node
 * @stack: Pointer to a stack
 * @line_num: Line number where the command is
 */
void add_2top(s_node *stack, unsigned int line_num)
{
	int node_num = 0, temp2 = 0;
	s_node temp = NULL;

	(void)stack;
	node_num = node_count();

	if (node_num > 1)
	{
		temp = my_node->current->next;
		temp2 = temp->n;
		temp->n = temp2 + my_node->current->n;
		free(my_node->current);
		my_node->current = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_stack();
		fclose(my_node->fd);
		free(my_node);
		exit(EXIT_FAILURE);
	}
}
