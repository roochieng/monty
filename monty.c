#include "monty.h"

FILE *files;
char *line_buf;
int is_queue;

/**
 * main - entry point for "monty," and interprets .m files
 * @argc: number of command line arguments
 * @argv: array of strings containing command line arguments
 * Return: 0 on success. all failure cases handled with exit()
 * directly from functions.
 */
int main(int argc, char **argv)
{
	files = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	files = fopen(argv[1], "r");
	if (!files)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_loop(files);
	return (0);
}
