#include "binary_trees.h"

/**
 * pop - delete the first node
 * @h_queue: pointer** to the first element of the queue
 */

void pop(queue_t **h_queue)
{
	queue_t *temp = *h_queue;

	*h_queue = (*h_queue)->next;
	free(temp);
}

/**
 * insert - inserts a new_node node in a queue
 * @h_queue: double pointer to the first item in queue
 * @node: node to insert in queue
 * Return: pointer to the new_node node
 */

queue_t *insert(queue_t **h_queue, heap_t *node)
{
	queue_t *new_node;
	queue_t *curr;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;
	curr = *h_queue;

	if (!*h_queue)
	{
		*h_queue = new_node;
		return (new_node);
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	return (new_node);
}

/**
 * traversal - level order traversal through queue
 * @root: double pointer to the start of the queue
 * @value: value to give inserted nodes
 *
 * Return: pointer to something
 */
heap_t *traversal(heap_t **root, int value)
{
	queue_t *h_queue = NULL;
	heap_t *curr;
	heap_t *new_node = NULL;

	if (!insert(&h_queue, *root))
		return (NULL);

	while (h_queue)
	{
		curr = h_queue->node;
		if (curr->left)
		{
			if (!insert(&h_queue, curr->left))
				return (NULL);
		}
		else if (!new_node)
		{
			new_node = binary_tree_node(curr, value);
			curr->left = new_node;
			if (!new_node)
				return (NULL);
		}
		if (curr->right)
		{
			if (!insert(&h_queue, curr->right))
				return (NULL);
		}
		else if (!new_node)
		{
			new_node = binary_tree_node(curr, value);
			curr->right = new_node;
			if (!new_node)
				return (NULL);

		}
		pop(&h_queue);
	}
	return (new_node);
}

/**
 * swap - if necessary, swaps the new_node node's value with it's parent's value
 * @new_node: new_node node to swapt value with
 *
 * Return: a pointer to the modified value
 */
heap_t *swap(heap_t *new_node)
{
	heap_t *ptr = new_node;
	int tmp;

	while (ptr->parent)
	{
		if (ptr->n > ptr->parent->n)
		{
			tmp = ptr->n;
			ptr->n = ptr->parent->n;
			ptr->parent->n = tmp;
			new_node = new_node->parent;
		}
		ptr = ptr->parent;
	}
	return (new_node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value stored in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	new_node = traversal(root, value);
	return (swap(new_node));
}