#include "monty.h"
/**
 * add_stack - add node to the head stack
 * @stack: head of the stack
 * @n: new_value
*/
void add_stack(stack_t **stack, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (*stack)
		(*stack)->prev = new;
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
/**
 * _stack - change the DS mode to stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void _stack(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
	box.flag = 0;
}
