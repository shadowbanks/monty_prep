#include "monty.h"

/**
 * swap - swap the data of the top two node
 * @stack: Pointer to a stack
 * @line_num: Line number where the command is
 */
void swap(s_node *stack, unsigned int line_num)
{
	int node_num = 0, temp2 = 0;
	s_node temp = NULL;

	(void)stack;
	node_num = node_count();

	if (node_num > 1)
	{
		temp = my_node->current->next;
		temp2 = temp->n;
		temp->n = my_node->current->n;
		my_node->current->n = temp2;
	}
	else
	{
		free_stack();
		fclose(my_node->fd);
		free(my_node);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * node_count - Count the amount of element in a stack
 *
 * Return: number of elements
 */
size_t node_count(void)
{
	s_node temp = NULL;
	int i = 0;

	if (my_node->current)
	{
		temp = my_node->current;
		while (temp)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}
