#include "monty.h"

/**
 * parse_loop - main loop of monty file interpreter, reads file stream line
 * by line, converting text strings into mainpulations of a doubly linked
 * list of ints
 * @file: file being parsed by interpreter
 */
void parse_loop(FILE *file)
{
	char *line = NULL, *uncomment = NULL, *opcode = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	is_queue = 0;
	do {
		line_number++;
		line = get_line(file, stack);
		if (line[0] == '#')
		{
			free(line_buf);
			continue;
		}
		else
			uncomment = strtok(line, "#");
		opcode = strtok(uncomment, " ");
		if (line[0] == '\0' || !opcode)
		{
			free(line_buf);
			continue;
		}
		if (opcode_select(opcode, &stack, line_number) == 1)
			break;
		free(line_buf);
	} while (line);
	cleanup(&stack);
	exit(EXIT_FAILURE);
}
