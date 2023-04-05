#include "lists.h"
/**
 * find_listint_loop - finding the loop in a linked list
 * @head: pointer to the head of the linked list
 * Return: pointer to the node from the start of the loop
 * or NULL once there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *gent1, *gent2;

	if (head == NULL || head->next == NULL)
		return (NULL);
	gent1 = head->next;
	gent2 = (head->next)->next;
		while (gent2)
		{
			if (gent1 == gent2)
			{
				gent1 = head;
				while (gent1 != gent2)
				{
					gent1 = gent1->next;
					gent2 = gent2->next;
		}
				return (gent1);
			}
			gent1 = gent1->next;
			gent2 = (gent2->next)->next
		}
		return (NULL)
}
