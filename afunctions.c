#include "monty.h"
/**
 * swap - swap the first two elements of the stack
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int a, b, len = 0;
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len += 1;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	(*stack)->n = b;
	(*stack)->next->n = a;
}
/**
 * nop - do nothing
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
