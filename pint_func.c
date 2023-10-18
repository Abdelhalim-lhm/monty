#include "monty.h"
/**
 * pint_func - function prints the value at the top of the stack
 * @stack: head of the stack
 * @ln: line number executed
 * Return nothing
 */
void pint_func(stack_t **stack, unsigned int ln)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
