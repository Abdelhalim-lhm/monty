#include "monty.h"
/**
 * pall_func - function that prints
 * all the values on the stack
 * @stack : head of the stack
 * @ln: line number executed
 * Return : nothing
 */
void pall_func(stack_t **stack, unsigned int ln)
{
	(void)ln;
	if (*stack == NULL)
		return;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
