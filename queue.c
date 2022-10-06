#include "monty.h"
/**
 * add_queue - add node to the head stack in queue mode
 * @stack: head of the stack
 * @n: new_value
*/
void add_queue(stack_t **stack, int n)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	tmp = *stack;
	if (tmp == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		new->n = n;
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
	}
}
/**
 * queue - change the DS mode to stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void queue(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
	box.flag = 1;
}
