#include "monty.h"

/**
 * add_func - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @ln: Line number (used for error messages).
 */
void add_func(stack_t **stack, unsigned int ln)
{
	stack_t *top1, *top2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = top1->next;

	top2->n += top1->n;

	pop_func(stack, ln);
}
