#include <stdio.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @h: linked list type listint_t to be traversed
 * Return: Number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t number = 0;

	while (h)
	{
		number++;
		h = h->next;
	}

	return (number);
}
