#include "monty.h"

/**
 * _swap - swaps the top two elements of the list; failure if
 * < 2 elements in list
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp_n;

	if (*stack && (*stack)->next)
	{
		temp_n = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp_n;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _add - finds sum of top two elements in the list; failure if
 * < 2 elements in list
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;

	if (*stack && (*stack)->next)
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _nop - "no operation," line skipped
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
