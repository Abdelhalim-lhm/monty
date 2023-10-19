#include "monty.h"

/**
 * swap_func - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @ln: Line number (used for error messages).
 */
void swap_func(stack_t **stack, unsigned int ln)
{
	stack_t *top1, *top2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = top1->next;

	top1->next = top2->next;
	if (top2->next)
		top2->next->prev = top1;

	top2->prev = NULL;
	top2->next = top1;
	top1->prev = top2;

	*stack = top2;
}
