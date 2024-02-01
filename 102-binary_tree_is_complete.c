#include "binary_trees.h"

/**
 * binary_tree_is_complete - a function taht checks
 * if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index = 0;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	return (binary_tree_is_complete_helper(tree, index, size));
}

/**
 * binary_tree_size - a function that measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete_helper - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: index of the node in an array representation of the tree
 * @size: size of the array representation of the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_helper(const binary_tree_t *tree,
		size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (binary_tree_is_complete_helper(tree->left, 2 * index + 1, size) &&
			binary_tree_is_complete_helper(tree->right, 2 * index + 2, size));
}
