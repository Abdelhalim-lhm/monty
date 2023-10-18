#include "monty.h"
/**
 * push_func - function that add node
 * @stack : head of the stack
 * @ln: line number executed
 * Return : pointer to the new node
 */
void push_func(stack_t **stack, unsigned int ln)
{
	int i = 0;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (argument[0] == '-')
	{
		i++;
	}
	for (; argument[i] != '\0' ; i++)
	{
		if (isdigit(argument[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	new_node->n = atoi(argument);
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
