#include "monty.h"

/**
 * mod_func - Computes the rest of the division
 * of the second top element by the top element.
 * @stack: A pointer to the stack.
 * @ln: Line number.
 */
void mod_func(stack_t **stack, unsigned int ln)
{
	stack_t *top1, *top2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = top1->next;

	if (top1->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top2->n %= top1->n;

	pop_func(stack, ln);
}
