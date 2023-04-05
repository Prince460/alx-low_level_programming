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
	listint_t *gent;
	listint_t *temp = *head;

	gent = malloc(sizeof(listint_t));
	if (!gent || head)
		return (NULL);
	gent->n = n;
	gent->next = NULL;
	if (idx == 0)
	{
		gent->next = *head;
		*head = gent;
		return (gent);

	}
	for (j = 0; temp && j < idx; j++)
	if (j == idx - 1)
	{
		gent->next = temp->next;
		temp->next = gent;
		return (gent);
	}
	else
		temp = temp->next;
	{
		return (NULL);
	}
}
