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
		printf("L<line_number>: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
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

/*
size_t monty_push(stack_t **head, unsigned int line_number)
{
    stack_t *new;
    extern_var_t intnum;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	if (*head != NULL)
	{
		new->n = data.value.intnum
		new->next = *head;
		new->prev = NULL;
		(*head)->prev = new;
		*head = new;
	}
	else
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}

	return (new);
}
*/


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
	stack_t *popped = top;

    if (!(*top))
	{
		printf("L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if (popped->prev != NULL)
	{
		popped->prev->next = NULL;
		top = popped->prev;
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

	if (!(*top))
	{
		printf("L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	if (last != NULL)
	{
		/*Assign the next position pointer to the previous node on the stack */
		last->next = last->prev;
		/*Assign the previous node next position pointer to NULL, it will be the last of the stack */
		last->prev->next = NULL;
		/*Assign the previous node prev position pointer to the actual last node*/
		last->prev->prev = last;
		/*Assign the last node prev position pointer to the previous position of previous node*/
		last->prev = last->prev->prev;

		/*Now, make the top pointer point to the last position of the stack*/
		top = last->prev->prev;
	}

}
