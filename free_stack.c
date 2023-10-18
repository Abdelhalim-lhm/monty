#include "monty.h"
/**
 * free_stack - fuction that free's the stack
 * @stack: head of my stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
