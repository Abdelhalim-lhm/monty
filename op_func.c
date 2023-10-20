#include "monty.h"
/**
 * op_func - summon the function associed to the opcode given
 * @stack: head of the stack
 * @opcode: the opcode instruction
 * @line: getline allocation
 * @fn: file name
 * @ln: line number executed
 * Return: 0 on success
 */
int op_func(stack_t **stack, char *opcode,
	char *line, FILE *fn, int ln)
{
	int i = 0;
	instruction_t operation[] = {
		{"push", push_func}, {"pall", pall_func},
		{"pint", pint_func}, {"pop", pop_func},
		{"swap", swap_func}, {"add", add_func},
		{"nop", nop_func}, {"sub", sub_func},
		{"div", div_func}, {"mul", mul_func},
		{"mod", mod_func}, {"pchar", pchar_func},
		{"pstr", pstr_func}, {NULL, NULL},
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
	if (opcode && operation[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
		free_stack(stack);
		free(line);
		fclose(fn);
		exit(EXIT_FAILURE);
	}
	free_stack(stack);
	free(line);
	fclose(fn);
	return (1);
}
