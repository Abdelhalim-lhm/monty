#include "monty.h"
/**
 * push_func - function that add node
 * @stack : head of the stack
 * @ln: line number executed
 * Return : pointer to the new node
 */
void push_func(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	new_node->n = atoi(argument);
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
