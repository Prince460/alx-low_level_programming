#include "lists.h"

/**
 * insert_nodeint_at_index - inserting a new node in a linked list
 * @head: pointer to the first node in the list
 * @idx: index that the new node is added to
 * @n: data to insert in the new node
 * Return: pointer to the new node or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *gent, *temp = *head;

	gent = malloc(sizeof(listint_t));
	if (gent == NULL)
		return (NULL);
	gent->n = n;

	if (idx == 0)
	{
		gent->next = temp;
		*head = gent;
		return (gent);
	}
	for (j = 0; j < (idx - 1); j++)
	{
		if (temp == NULL || temp->next == NULL)
			return (NULL);
		temp = temp->next;
	}
		gent->next = temp->next;
		temp->next = gent;

		return (gent);
}
