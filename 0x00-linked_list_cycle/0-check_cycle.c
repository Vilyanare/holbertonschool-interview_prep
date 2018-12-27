#include "lists.h"

/**
 * check_cycle - Checks to see if there is a loop in a linked list
 * @list: List to check for a loop
 * Return: 1 if there is a loop 0 if there is no loop
 */
int check_cycle(listint_t *list)
{
	listint_t *fast = list;
	listint_t *slow = list;

	if (list == NULL)
	{
		return(0);
	}

	while (slow->next)
	{
		if (fast->next)
		{
			if (fast->next->next)
			{
				fast = fast->next->next;
			}
			else
			{
				return(0);
			}
		}
		else
		{
			return(0);
		}
		slow = slow->next;
		if (slow == fast)
		{
			return(1);
		}
	}
	return(0);
}
