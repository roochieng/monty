#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

FILE *files;
char *line_buf;
int is_queue;
/**
 * _stack - sets flag to treat linked list as LIFO stack
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	is_queue = 0;
}

/**
 * _queue - sets flag to treat linked list as FIFO queue
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	is_queue = 1;
}

/**
 * cleanup - uses global variables FILE *file_s and char *line_buf plus arg
 * stack_t **stack to free allocated memory before any conditional exit().
 * @stack: double pointer to top element in stack
 */
void cleanup(stack_t **stack)
{
	stack_t *temp;

	if (line_buf)
		free(line_buf);
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	fclose(files);
}

/**
 * opcode_select - checks opcode string against list of opcode names,
 * calling a function if matched
 * @opcode: first ' ' delimited token of input line from parse_loop()
 * @stack: double pointer to top element in stack
 * @line_number: current line of monty file seen by interpreter
 * Return: 0 on success, 1 on failure (no match found)
 */
int opcode_select(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t codes[] = {
		{"push", (*_push)},
		{"pall", (*_pall)},
		{"pint", (*_pint)},
		{"pop", (*_pop)},
		{"swap", (*_swap)},
		{"add", (*_add)},
		{"nop", (*_nop)},
		{"sub", (*_sub)},
		{"div", (*_div)},
		{"mul", (*_mul)},
		{"mod", (*_mod)},
		{"pchar", (*_pchar)},
		{"pstr", (*_pstr)},
		{"rotl", (*_rotl)},
		{"rotr", (*_rotr)},
		{"stack", (*_stack)},
		{"queue", (*_queue)},
		{NULL, NULL}
	};

	for (i = 0; codes[i].opcode; i++)
	{
		if (!strcmp(opcode, codes[i].opcode))
		{
			codes[i].f(stack, line_number);
			return (0);
		}
	}
	if (!codes[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
		return (1);
	}
	return (0);
}

/**
 * get_line - wrapper for getline() to handle errors and EOF exit
 * @file: file stream currently being parsed by interpreter
 * @stack: single pointer to top element in stack
 * Return: buffer read by getline(), with terminal, replace '\n' with '\0'
 */
char *get_line(FILE *file, stack_t *stack)
{
	size_t buf_bytes = 0;
	ssize_t read_bytes;

	read_bytes = getline(&line_buf, &buf_bytes, file);
	if (read_bytes == -1)
	{
		if (errno == 0)
		{
			cleanup(&stack);
			exit(EXIT_SUCCESS);
		}
		else
		{
			fprintf(stderr, "t:getline failure\n");
			cleanup(&stack);
			exit(EXIT_FAILURE);
		}
	}
	if (line_buf)
		line_buf[read_bytes - 1] = '\0';
	return (line_buf);
}
