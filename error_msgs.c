#include "monty.h"

/**
 * code_err - Print error message for failed push
 * @line_num: line number of command
 */
void code_err(unsigned int line_num)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	free_stack();
	fclose(my_node->fd);
	free(my_node);
	exit(EXIT_FAILURE);
}

/**
 * unknown - Print error message for incorrect command
 * @op: command
 * @line_num: line number of command
 */
void unknown(char *op, int *line_num)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", *line_num, op);
	free_stack();
	fclose(my_node->fd);
	free(my_node);
	exit(EXIT_FAILURE);
}

/**
 * monty_usage_err - Error message when monty usage is wrong
 */
void monty_usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	fclose(my_node->fd);
	free(my_node);
	exit(EXIT_FAILURE);
}

/**
 * open_file_err - Error message when file can't be opened
 * @file_name: name of file that failed to open
 */
void open_file_err(char *file_name)
{
	fprintf(stderr, "Can't open file %s\n", file_name);
	free_stack();
	fclose(my_node->fd);
	free(my_node);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err - Error message when malloc fails
 */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_stack();
	fclose(my_node->fd);
	free(my_node);
	exit(EXIT_FAILURE);
}
