#include "binary_trees.h"

/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: Pointer to the root node of
 * the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of
 * the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = bst_min_value(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * bst_min_value - Finds the node with the minimum value in a BST
 * @root: Pointer to the root node of the BST
 * Return: Pointer to the node with the minimum value
 */
bst_t *bst_min_value(bst_t *root)
{
	bst_t *current = root;

	while (current->left != NULL)
		current = current->left;
	return (current);
}
