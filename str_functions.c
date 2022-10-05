#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num;
	int b;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	b = num >= 0 && num <= 127;
	if (!b)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(box.file);
		free(box.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar('\n');
}
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: head pointer of the stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	line_number = line_number;
	while (h != NULL && h->n != 0 && h->n >= 0 && h->n <= 127)
	{
		putchar(h->n);
		h = h->next;
	}
	putchar('\n');
}
