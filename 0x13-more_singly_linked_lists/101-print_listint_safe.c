#include "lists.h"

/**
 * print_listint_safe - Print a listint_t linked list safely
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	tortoise = hare = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		printf("[%p] %d\n", (void *)tortoise, tortoise->n);

		if (tortoise == hare)
		{
			printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
			break;
		}

		count++;
	}

	if (tortoise == hare)
	{
		tortoise = head;
		while (tortoise != hare)
		{
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			tortoise = tortoise->next;
			hare = hare->next;
		}

		printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
		count++;
	}

	return (count);
}
/**
 * main - Entry point for the program
 *
 * Description: This function serves as the entry point for the program.
 * It creates and prints a listint_t linked list safely.
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *head;
	listint_t *head2;
	listint_t *node;

	head2 = NULL;
	add_nodeint(&head2, 0);
	add_nodeint(&head2, 1);
	add_nodeint(&head2, 2);
	add_nodeint(&head2, 3);
	add_nodeint(&head2, 4);
	add_nodeint(&head2, 98);
	add_nodeint(&head2, 402);
	add_nodeint(&head2, 1024);
	print_listint_safe(head2);

	head = NULL;
	node = add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	add_nodeint(&head, 4);
	node->next = add_nodeint(&head, 98);
	add_nodeint(&head, 402);
	add_nodeint(&head, 1024);
	print_listint_safe(head);

	return (0);
}
