#include "lists.h"

/**
 * pop_listint - delete the head node of a linked list
 * @head: pointer to the first element in the linked list
 * Return: Data inside the element that was deleted
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;

	int gent;

	if (!head || !*head)
		return (0);

	gent = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;
	return (gent);

}
