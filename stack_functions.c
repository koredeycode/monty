#include "monty.h"
/**
 * push - put an integer to stack
 * @stack: pointer to the head pointer
 * @line_number: integer to be pushed to the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL)
	{
		new->n = atoi(box.arg)/*line_number*/;
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->n = atoi(box.arg)/*line_number*/;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}
/**
 * pop - remove the top of the stack
 * @stack: pointer to the head pointer
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (*stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(h);
}
/**
 * pint - print the top of the stack
 * @stack: pointer to the head pointer
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		printf("\n");
	else
		printf("%d\n", (*stack)->n);
}
/**
 * pall - print all the elements of the stack
 * @stack: pointer to the head pointer
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if ((*stack) == NULL)
		printf("Stack is Empty\n");
	else
	{
		h = *stack;
		while (h != NULL)
		{
			printf("%d\n", h->n);
			h = h->next;
		}
	}
}
/**
 * free_stack - totally free the stack
 * @stack: pointer to the head pointer
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	if ((*stack) == NULL)
		exit(EXIT_SUCCESS);
	tmp = *stack;
	while (tmp)
	{
		*stack = (*stack)->next;
		free(tmp);
		tmp = *stack;
	}
}
