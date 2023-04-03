#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in the new node
 * Return: pointer to the new node or NULL if it fials
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *gent;

	gent = malloc(sizeof(listint_t));
	if (!gent)
		return (NULL);

	gent->n = n;
	gent->next = *head;
	*head = gent;

	return (gent);
}
