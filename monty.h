#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

#define LINE_LENGTH 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef stack_t *s_node;

/**
 * struct my_struct - Store some specific data
 * @data: push value
 * @head: Beginning of the doubly linked list
 * @current: The current node
 * @fd: The current file descriptor
 *
 * Description: Structure to hold current and start node,
 * also the value to be push
 */
typedef struct my_struct
{
	int data;
	s_node head;
	s_node current;
	FILE *fd;
} my_struct;

extern my_struct *my_node;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int blank_line(const char *str);
void handle_opcode(s_node *stack, int str_len, char *op, int *line_num);
void unknown(char *op, int *line_num);
void code_err(unsigned int line_num);
void push_to_stack(s_node *stack, unsigned int line_num);
void pall_stack(s_node *stack, unsigned int line_num);
void pint_stack(s_node *stack, unsigned int line_num);
void pop_stack(s_node *stack, unsigned int line_num);
void swap(s_node *stack, unsigned int line_num);
void add_2top(s_node *stack, unsigned int line_num);
void nop(s_node *stack, unsigned int line_num);
void sub_2top(s_node *stack, unsigned int line_num);
void div_2top(s_node *stack, unsigned int line_num);
void mul_2top(s_node *stack, unsigned int line_num);
void mod_2top(s_node *stack, unsigned int line_num);
size_t node_count(void);
void malloc_err(void);
void open_file_err(char *);
void monty_usage_err(void);
void free_stack(void);

#endif /*MONTY_H*/
