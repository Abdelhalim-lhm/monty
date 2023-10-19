#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
extern char *argument;
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
int op_func(stack_t **stack, char *opcode, char *line,FILE *fn, int ln);
void push_func(stack_t **stack, unsigned int ln);
void pall_func(stack_t **stack, unsigned int ln);
void pint_func(stack_t **stack, unsigned int ln);
void free_stack(stack_t **stack);
void pop_func(stack_t **stack, unsigned int ln);
void swap_func(stack_t **stack, unsigned int ln);
void add_func(stack_t **stack, unsigned int ln);
void nop_func(stack_t **stack, unsigned int ln);
void sub_func(stack_t **stack, unsigned int ln);
void div_func(stack_t **stack, unsigned int ln);
void mul_func(stack_t **stack, unsigned int ln);
#endif
