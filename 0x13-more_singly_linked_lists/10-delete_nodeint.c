#include "lists.h"
/**
 * delete_nodeint_at_index - deleting a node in a linked list at a certain inde
 * @head: pointer to the first element in the list
 * @index: index of the node that will be deleted
 * Return: 1 if successful or -1 if fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *codegent = NULL;
	unsigned int j = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (j < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		j++;
	}
	codegent = temp->next;
	temp->next = codegent->next;
	free(codegent);
	return (1);
}
