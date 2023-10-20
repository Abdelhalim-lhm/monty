#include "monty.h"
/**
 * pstr_func - function that prints the string starting
 * at the top of the stack
 * @stack: head of the stack
 * @ln: line number executed
 */
void pstr_func(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	int val;

	tmp = *stack;

	if (tmp == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp)
	{
		val = tmp->n;
		if (val == 0)
		{
			printf("\n");
			return;
		}
		if ((val >= 65 && val <= 90) || (val >= 97 && val <= 122))
		{
			printf("%c", val);
			tmp = tmp->next;
		}
		else
		{
			printf("\n");
			return;
		}
	}
	printf("\n");
}
