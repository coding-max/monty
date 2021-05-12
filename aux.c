#include "monty.h"

/**
 * dlistint_len - prints the lenght of the list
 * @h: head of the list
 * Return: Lenght of the list
 */
size_t stack_len(const stack_t *h)
{

	const stack_t *current;
	size_t count = 0;

	current = h;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
