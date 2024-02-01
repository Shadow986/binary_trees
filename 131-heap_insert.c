#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 *
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = binary_tree_node(*root, value);
	heap_t *parent, *current;

	if (new_node == NULL)
	return (NULL);

	if (*root == NULL)
	{
	*root = new_node;
	return (new_node);
	}

	current = *root;
	while (current != NULL)
	{
	parent = current;
	if (value > current->n)
	current = current->right;
	else
	current = current->left;
	}

	if (value > parent->n)
	parent->right = new_node;
	else
	parent->left = new_node;

	new_node->parent = parent;

	heapify_up(new_node);

	return (new_node);
}

/**
 * heapify_up - restores the Max Heap property after inserting a new node
 *
 * @node: pointer to the node to heapify up
 */
void heapify_up(heap_t *node)
{
	heap_t *parent;
	int temp;

	while (node->parent != NULL && node->n > node->parent->n)
	{
	parent = node->parent;
	temp = parent->n;
	parent->n = node->n;
	node->n = temp;
	node = parent;
	}
}
