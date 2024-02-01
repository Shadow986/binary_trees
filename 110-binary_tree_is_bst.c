#include "binary_trees.h"

/**
 * binary_tree_is_bst - a function that
 * checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - a function that
 * recursive helper function for binary_tree_is_bst
 * @tree: Pointer to the current node
 * @min: Minimum value allowed in the subtree
 * @max: Maximum value allowed in the subtree
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (bst_helper(tree->left, min, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, max));
}
