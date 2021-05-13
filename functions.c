#include "monty.h"

/**
 * monty_push - pushes an element to the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_push(stack_t **top_ptr, unsigned int line_n)
{
	/* temporal, esto en realidad viene en la variable externa */
	stack_t *new_node, *top;
	
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("L%u: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}
	new_node->n = ex.int_value;

	if (!top)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		top = new_node;
	}
	else 
	{
		new_node->next = NULL;
		new_node->prev = top;
		top->next = new_node;
		top = new_node;
	}
}

/**
 * monty_pall - prints all the values on the stack, starting from the top of the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_pall(stack_t **top, unsigned int line_n)
{
	/* temporal, esto en realidad viene en la variable externa */
	stack_t *head;
	stack_t *aux;

	aux = head;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * monty_pint - prints the value at the top of the stack, followed by a new line.
 * @top: idk.
 * @line_n: idk.
 */
void monty_pint(stack_t **top, unsigned int line_n)
{
	if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*top)->n);
}

/**
 * monty_pop - removes the top element of the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_pop(stack_t **top, unsigned int line_n)
{
	stack_t *popped = *top;

    if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if (popped->prev != NULL)
	{
		popped->prev->next = NULL;
		*top = popped->prev;
	}

    free(popped);
}

/**
 * monty_swap - swaps the top two elements of the stack.
 * @top: pointer to the top of the stack.
 * @line_n: lines of the file.
 */

void monty_swap(stack_t **top, unsigned int line_n)
{
	stack_t *last = *top;
	int aux_int =

	if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if (last != NULL)
	{
		aux_int = last->n;
		last->prev->n = last->n;
		last->n = last->prev->n;
	}
}

void monty_add(stack_t **top, unsigned int line_n)
{
	stack_t *last = *top;
	int sum;

	if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	sum = last->prev->n + last->n;

	monty_pop(last, line_n);
}

void monty_mul(stack_t **top, unsigned int line_n)
{
	stack_t *last = *top;
	int mul;

	if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	mul = last->prev->n * last->n;

	monty_pop(last, line_n);
}

void monty_nop(stack_t **top, unsigned int line_n)
{
	*top = *top;
	line_n = line_n;
}

void monty_div(stack_t **top, unsigned int line_n)
{
	stack_t *last = *top;
	int div;

	if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	div = last->prev->n / last->n;

	monty_pop(last, line_n);
}

void monty_mod(stack_t **top, unsigned int line_n)
{
	stack_t *last = *top;
	int div;

	if (!top)
	{
		printf("L%u: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	div = last->prev->n % last->n;

	monty_pop(last, line_n);
}
