#include "binary_trees.h"
/**
 * binary_tree_nodes - function that returns # of nodes in a tree with children
 * @tree: tree to check
 * Return: number of nodes with children
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	return (0);

	return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}
