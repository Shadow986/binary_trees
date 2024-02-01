#include "binary_trees.h"

/**
 * bst_insert - a function that
 * nserts a value in a Binary Search Tree
 * @tree: Double pointer to the
 * root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	current = *tree;
	while (1)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = new_node;
				new_node->parent = current;
				break;
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				current->right = new_node;
				new_node->parent = current;
				break;
			}
			current = current->right;
		}
		else
		{
			free(new_node);
			break;
		}
	}
	return (new_node);
}
