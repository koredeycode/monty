#include "monty.h"
box_t box = {NULL, NULL, NULL, 0};
/**
 * main - the entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: always zero
 */
int main(int ac, char **av)
{
	FILE *stream;
	char *line_content;
	size_t len = 0;
	ssize_t nread = 1;
	unsigned int line_no = 0;
	stack_t *stck = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(av[1], "r");
	box.file = stream;
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (nread > 0)
	{
		line_content = NULL;
		nread = getline(&line_content, &len, stream);
		box.content = line_content;
		line_no++;
		if (nread > 0)
		{
			exec(line_content, &stck, line_no, stream);
		}
		free(line_content);
	}
	free_stack(stck);
	fclose(stream);
	return (0);
}
