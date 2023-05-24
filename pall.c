#include "monty.h"

/**
 * pall - this prints the stack
 * @stack: stack
 * @line_cnt: number of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
