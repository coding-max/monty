#include "monty.h"

/**
 * monty_push - pushes an element to the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_push(stack_t **ptr, unsigned int line_n)
{
	/* temporal, esto en realidad viene en la variable externa */
	stack_t *head;
	stack_t *top = *ptr;
	stack_t *new_node;
	content_v data;


	/* if <int> is not an integer or if there is no argument given to push, 
	print the error message L<line_number>: usage: push integer, 
	followed by a new line, and exit with the status EXIT_FAILURE */

	
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		// error
	}
	new_node->n = data.value;

	if (!top)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		top = new_node;
		head = new_node;
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
	if (!(*top))
	{
		printf("L%d: can't pint, stack empty\n", line_n)
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

}

/**
 * monty_swap - swaps the top two elements of the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_swap(stack_t **top, unsigned int line_n)
{

}
