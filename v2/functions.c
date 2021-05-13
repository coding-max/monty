#include "monty.h"

/**
 * monty_push - pushes an element to the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_push(stack_t **top_ptr, unsigned int line_n)
{
	/* temporal, esto en realidad viene en la variable externa */
	stack_t *new_node, *top = *top_ptr;
	
	if (!ex.data.value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		/*free function*/ //todo
		fprintf(stderr, "Error: malloc failed\n");
		fclose(ex.fp); 
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	new_node->n = ex.int_value;

	if (!top)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*top_ptr = new_node;
	}
	else 
	{
		new_node->next = NULL;
		new_node->prev = top;
		top->next = new_node;
		*top_ptr = new_node;
	}
}

/**
 * monty_pall - prints all the values on the stack, starting from the top of the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_pall(stack_t **top_ptr, unsigned int line_n)
{
	/* temporal, esto en realidad viene en la variable externa */
	stack_t *aux = *top_ptr;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}

/**
 * monty_pint - prints the value at the top of the stack, followed by a new line.
 * @top: idk.
 * @line_n: idk.
 */
void monty_pint(stack_t **top_ptr, unsigned int line_n)
{
	if (!(*top_ptr))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*top_ptr)->n);
}

/**
 * monty_pop - removes the top element of the stack.
 * @top: idk.
 * @line_n: idk.
 */
void monty_pop(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *popped = *top_ptr;

    if (!popped)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (popped->prev != NULL)
	{
		popped->prev->next = NULL;
		*top_ptr = popped->prev;
	}
	else
		*top_ptr = NULL;

    free(popped);
}

void monty_swap(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int aux_int;

	if (!last)
	{
		fprintf(stderr, "L%u: can't swap, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	
	aux_int = last->n;
	last->prev->n = last->n;
	last->n = last->prev->n;
}

void monty_add(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int sum;

	if (!last)
	{
		fprintf(stderr, "L%u: can't add, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	sum = last->prev->n + last->n;

	monty_pop(top_ptr, line_n);
}



void monty_mul(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int mul;

	if (!last)
	{
		fprintf(stderr, "L%u: can't mul, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	mul = last->prev->n * last->n;

	monty_pop(top_ptr, line_n);
}

void monty_nop(stack_t **top_ptr, unsigned int line_n)
{
	*top_ptr = *top_ptr;
	line_n = line_n;
}



void monty_div(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int div;

	if (!last)
	{
		fprintf(stderr,"L%u: can't div, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		div = last->prev->n / last->n;
	else
	{
		fprintf(stderr,"L%u: division by zero\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}

	monty_pop(top_ptr, line_n);
}

void monty_mod(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int mod;

	if (!last)
	{
		printf("L%u: can't mod, stack empty\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		mod = last->prev->n % last->n;
	else
	{
		fprintf(stderr,"L%u: division by zero\n", line_n);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}

	monty_pop(top_ptr, line_n);
}

