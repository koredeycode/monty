#include "monty.h"
/**
 * exec - execute the function needed
 * @l_content: the line content of the file
 * @stack: the file stack
 * @l_number: line number for errors
 * @stream: the file stream
 * Return: an integer
 */
int exec(char *l_content, stack_t **stack, unsigned int l_number, FILE *stream)
{
	instruction_t operations[] = {
		{"pop", pop}, {"push", push}, {"pint", pint},
		{"pall", pall}, {"swap", swap}, {"add", _add},
		{"sub", _sub}, {"mul", _mul}, {"div", _div}, {"mod", _mod},
		{"nop", nop}, {"pchar", pchar}, {"pstr", pstr},
		{NULL, NULL},
	};
	unsigned int i = 0;
	char *tok;

	tok = strtok(l_content, " \n\t");
	if (tok && tok[0] == '#')
		return (0);
	box.arg = strtok(NULL, " \n\t");

	while (operations[i].opcode && tok)
	{
		if (strcmp(tok, operations[i].opcode) == 0)
		{
			operations[i].f(stack, l_number);
			return (0);
		}
		i += 1;
	}
	if (tok && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_number, tok);
		fclose(stream);
		free(l_content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
