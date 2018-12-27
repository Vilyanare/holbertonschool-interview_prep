#include "lists.h"

/**
 * insert_node - Inserts a node in numerical order into a linked list
 * @head: Double pointer to the head node
 * @number: Number to insert
 * Return: Null if failed - Otherwise pointer to the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	if (head == NULL || *head == NULL)
		return(add_nodeint_end(head, number));

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;
	if (number < current->n)
	{
		new->next = current;
		*head = new;
		return(new);
	}

	while (current->next != NULL && current->next->n < new->n)
		current = current->next;

	new->next = current->next;
	current->next = new;

	return (new);

}
