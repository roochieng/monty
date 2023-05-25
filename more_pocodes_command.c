#include "monty.h"

/**
 * _pchar - prints the int at top of list as char, followed by a new line;
 * failure if int is not a printable ASCII value, or list is empty
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if ((*stack)->n >= ' ' && (*stack)->n <= '~')
		{
			printf("%c\n", (*stack)->n);
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
			cleanup(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - prints the int values in the list, starting at the top, as chars,
 * followed by a new line; ends if list is empty, or when int is not a
 * printable ASCII value
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		if (temp->n == '\0')
			break;
		if (temp->n >= ' ' && temp->n <= '~')
			putchar(temp->n);
		else
			break;
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotates top element of list to bottom of list, 2nd becomes top
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *temp;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tail = *stack;
		*stack = (*stack)->next;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = tail;
		tail->prev = temp;
		tail->next = NULL;
	}
}

/**
 * _rotr - rotates bottom element of list to top of list
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->prev->next = NULL;
		(*stack)->prev = temp;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
