#include "monty.h"
/**
 * pall_func - function that prints
 * all the values on the stack
 * @stack : head of the stack
 * @ln: line number executed
 * Return : nothing
 */
void pall_func(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	tmp = *stack;

	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
