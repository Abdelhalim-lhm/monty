#include "monty.h"
char *argument = NULL;
/**
 * main - entry point
 * @argc: number of argument
 * @argv: arguments vectors
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int  ln;
	char *line = NULL, *opcode;
	size_t len = 0;
	stack_t *stack = NULL;
	FILE *fn;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fn = fopen(argv[1], "r");

	if (fn == NULL || argv[1] == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (ln = 1 ; getline(&line, &len, fn) > 0; ln++)
	{
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line);
			free_stack(&stack);
			fclose(fn);
			exit(EXIT_FAILURE);
		}
		if (line[0] == '#')
			continue;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || (opcode != NULL && opcode[0] == '#'))
			continue;
		argument = strtok(NULL, " \n\t");
		if (strcmp(opcode, "mod") == 0)
		{
			mod_func(&stack, ln);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			mul_func(&stack, ln);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			div_func(&stack, ln);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			sub_func(&stack, ln);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop_func(&stack, ln);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add_func(&stack, ln);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap_func(&stack, ln);
		}
		else
		{
			op_func(&stack, opcode, line, fn, ln);
		}
	}
	free(line);
	free_stack(&stack);
	fclose(fn);
	return (0);
}
