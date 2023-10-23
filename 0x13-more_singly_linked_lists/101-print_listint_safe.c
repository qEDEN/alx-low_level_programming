#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * If it is looped - the number of unique nodes in the list.
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *sloth, *usain_bolt;
	size_t nod = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	sloth = head->next;
	usain_bolt = (head->next)->next;

	while (usain_bolt)
	{
		if (sloth == usain_bolt)
		{
			sloth = head;
			while (sloth != usain_bolt)
			{
				nod++;
				sloth = sloth->next;
				usain_bolt = usain_bolt->next;
			}

			sloth = sloth->next;
			while (sloth != usain_bolt)
			{
				nod++;
				sloth = sloth->next;
			}

			return (nod);
		}

		sloth = sloth->next;
		usain_bolt = (usain_bolt->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - prints the listint_t list safely.
 * @head: Points to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nod, index = 0;

	nod = looped_listint_len(head);

	if (nod == 0)
	{
		for (; head != NULL; nod++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nod; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nod);
}
