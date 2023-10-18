#include "monty.h"
/**
 * pop_func - function that removes the top element of the stack
 * @stack: head of the stack
 * @ln: line number executed
 * Return: nothing
 */
void pop_func(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
