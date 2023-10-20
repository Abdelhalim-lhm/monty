#include "monty.h"
/**
 * pchar_func - function that prints the char at the top of the stack
 * @stack: head of the stack
 * @ln: number of the line executed
 */
void pchar_func(stack_t **stack, unsigned int ln)
{
	int top;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	if ((top >= 65 && top <= 90) || (top >= 97 && top <= 122))
	{
		printf("%c\n", top);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
