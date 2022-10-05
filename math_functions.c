#include "monty.h"
/**
 * _add - add first two element and return them
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	pop(stack, line_number);
	pop(stack, line_number);
	add_stack(stack, a + b);
}
/**
 * _sub - substract first two element and return them
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	pop(stack, line_number);
	pop(stack, line_number);
	add_stack(stack, b - a);
}
/**
 * _div - divides first two element and return them
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	pop(stack, line_number);
	pop(stack, line_number);
	add_stack(stack, b / a);
}
/**
 * _mul - multiplies first two element and return them
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	pop(stack, line_number);
	pop(stack, line_number);
	add_stack(stack, b * a);
}
/**
 * _mod - divides first two element and return them
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	b = (*stack)->next->n;
	pop(stack, line_number);
	pop(stack, line_number);
	add_stack(stack, b % a);
}
