#include "monty.h"
/**
 * push - put an integer to stack
 * @stack: pointer to the head pointer
 * @line_number: integer to be pushed to the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, trap = 0;

	if (box.arg)
	{
		if (box.arg[0] == '-')
			j++;
		for (; box.arg[j] != '\0'; j++)
		{
			if (box.arg[j] > 57 || box.arg[j] < 48)
				trap = 1;
		}
		if (trap == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(box.file);
			free(box.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(box.arg);
	if (box.flag == 0)
		add_stack(stack, n);
	else
		add_queue(stack, n);
}
/**
 * pop - remove the top of the stack
 * @stack: pointer to the head pointer
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = (*stack)->next;
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
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
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

	line_number = line_number;
	if ((*stack) == NULL)
		return;
	h = *stack;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * free_stack - totally free the stack
 * @stack: pointer to the head pointer
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
