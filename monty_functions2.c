#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_add(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int sum;

	if (!last)
	{
		fprintf(stderr, "L%u: can't add, stack empty\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	sum = last->prev->n + last->n;

	monty_pop(top_ptr, line_n);

	last->n = sum;
}

/**
 * monty_sub - subtracts the top element of the stack from the second top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */

/**
 * monty_div - divides the second top element of the stack by the top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_div(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int div;

	if (!last)
	{
		fprintf(stderr,"L%u: can't div, stack empty\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		div = last->prev->n / last->n;
	else
	{
		fprintf(stderr,"L%u: division by zero\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}

	monty_pop(top_ptr, line_n);
	last->n = div;
}

/**
 * monty_mul - multiplies the second top element of the stack with the top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_mul(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int mul;

	if (!last)
	{
		fprintf(stderr, "L%u: can't mul, stack empty\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	mul = last->prev->n * last->n;

	monty_pop(top_ptr, line_n);
	last->n = mul;
}

/**
 * monty_mod - computes the rest of the division of the second top element of the stack by the top element of the stack.
 * @top_ptr: idk.
 * @line_n: idk.
 */
void monty_mod(stack_t **top_ptr, unsigned int line_n)
{
	stack_t *last = *top_ptr;
	int mod;

	if (!last)
	{
		printf("L%u: can't mod, stack empty\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}
	if (last->n != 0)
		mod = last->prev->n % last->n;
	else
	{
		fprintf(stderr,"L%u: division by zero\n", line_n);
		free(ex.line);
		fclose(ex.fp);
		free_stack(*top_ptr);
		exit(EXIT_FAILURE);
	}

	monty_pop(top_ptr, line_n);
	last->n = mod;
}
