#include "monty.h"

/**
 * _sub - subtracts the top element of the list from the second top
 * element of the list; failure if < 2 elements in list
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int diff;

	if (*stack && (*stack)->next)
	{
		diff = (*stack)->next->n - (*stack)->n;
		(*stack)->next->n = diff;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divides the second top element of the list by the top element
 * of the stack; failure if < 2 elements in list, or top element is 0
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int quot;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			cleanup(stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			quot = (*stack)->next->n / (*stack)->n;
			(*stack)->next->n = quot;
			*stack = (*stack)->next;
			free(temp);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mul - multiplies the second top element of the list by the top element
 * of the list; failure if < 2 elements in list
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int prod;

	if (*stack && (*stack)->next)
	{
		prod = (*stack)->next->n * (*stack)->n;
		(*stack)->next->n = prod;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod - finds modulo of the second top element of the list divided by the
 * top element; failure if < 2 elements in list, or top element is 0
 * @stack: first element of a doubly linked list of integers
 * @line_number: current line of monty text file
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mod;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			cleanup(stack);
			exit(EXIT_FAILURE);
		}
		else
		{
			mod = (*stack)->next->n % (*stack)->n;
			(*stack)->next->n = mod;
			*stack = (*stack)->next;
			free(temp);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}
