#include "lists.h"

/**
 * is_palindrome - checks to see if a linked list is a palindrome
 * @head: pointer to head node of list
 * Return: 1 if list is a palindrome - Otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *last = *head;
	listint_t *first = *head;
	int max = 0, min = 0, x = 0;

	if (!head || !*head)
		return(1);

	while (last->next)
	{
		last = last->next;
		max++;
	}
	max--;
	while (min <= max)
	{
		if (first->n != last->n)
			return(0);

		last = first;
		for (x = 0; x < (max - min); x++)
		{
			last = last->next;
		}
		first = first->next;
		min++;
		max--;
	}
	return(1);
}
