#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

#include "lists.h"

/**
 * insert_node_beginning - adds a new node at the beginning of a
 * listint_t list
 *
 * @current: pointer to the current node (head of single linked list)
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node_beginning(listint_t **current, int number)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (!new)
	{
		return (NULL);
	}
	new->n = number;
	new->next = *current;

	return (new);
}

/**
 * insert_node_middle - adds a new node at somewhere in the middle of a
 * listint_t list
 *
 * @current: pointer to the current node
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node_middle(listint_t **current, int number)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (!new)
	{
		return (NULL);
	}
	new->n = number;
	new->next = (*current)->next;
	(*current)->next = new;

	return (new);
}

/**
 * insert_node_end - adds a new node at end of a listint_t list
 *
 * @current: pointer to the current node
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node_end(listint_t **current, int number)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (!new)
	{
		return (NULL);
	}
	(*current)->next = new;
	new->n = number;
	new->next = NULL;

	return (new);
}

/**
 * insert_node - adds a new node in a sorted listint_t list
 *
 * @head: pointer to the head 
 * @number:number of the new node
 * Return: listint_t*  of the new element,  or NULL if fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *ptr = *head;

	if (ptr == NULL || ptr->n > number)
	{
		*head = insert_node_beginning(head, number);
		goto exit;
	}
	while (ptr)
	{
		if (ptr->next != NULL && ptr->next->n > number)
		{
			insert_node_middle(&ptr, number);
			goto exit;
		}
		if (ptr->next == NULL)
		{
			insert_node_end(&ptr, number);
			goto exit;
		}
		ptr = ptr->next;
	}
exit: return (ptr);
}