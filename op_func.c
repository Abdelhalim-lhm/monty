#include "monty.h"
/**
 * op_func - summon the function associed to the opcode given
 * @stack: head of the stack
 * @opcode: the opcode instruction
 * @argument: value of the opcode
 * @ln: line number executed
 * Return: 0 on success
 */
int op_func(stack_t **stack, char *opcode,
	__attribute__((unused))char *argument, int ln)
{
	int i = 0;
	instruction_t operation[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{NULL, NULL},
		};

	if (opcode != NULL)
	{
		while (operation[i].opcode != NULL)
		{
			if (strcmp(opcode, operation[i].opcode) == 0)
			{
				operation[i].f(stack, ln);
				return (0);
			}
		i++;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
	exit(EXIT_FAILURE);
}
