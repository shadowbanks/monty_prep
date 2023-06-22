#include "monty.h"

my_struct *my_node = NULL;

/**
 * main - Monty interpreter
 * @ac: argument counter
 * @av: argument variables
 *
 * Return: 0 (on success)
 */
int main(int ac, char **av)
{
	FILE *fd;
	char *op = NULL, line[LINE_LENGTH];
	int line_num = 0, str_len = 0;
	s_node stack = NULL;

	if (ac != 2)
		monty_usage_err();

	fd = fopen(av[1], "r");

	if (fd == NULL)
		open_file_err(av[1]);

	my_node = malloc(sizeof(my_struct));

	if (my_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	my_node->data = 0;
	my_node->head = NULL;
	my_node->current = NULL;
	my_node->fd = fd;

	while (fgets(line, sizeof(line), fd) != NULL)
	{
		op = strtok(line, " ");
		str_len = strlen(op);
		handle_opcode(&stack, str_len, op, &line_num);
	}
	free_stack();
	free(my_node);

	fclose(fd);
	return (0);
}
