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
	int  ln = 0;
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
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fn) > 0)
	{
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		ln++;
		opcode = strtok(line, " \n\t");
		argument = strtok(NULL, " \n\t");
		op_func(&stack, opcode, argument, ln);
	}
	free(line);
	fclose(fn);
	return (0);
}
