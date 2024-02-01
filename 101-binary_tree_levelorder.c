#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - a function that goes
 * through a binary tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;

	h = binary_tree_height(tree) + 1;
	for (i = 0; i < h; i++)
		binary_tree_print_level(tree, i, func);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);
	left_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_print_level - prints nodes at a given level
 * @tree: a pointer to the root node of the tree to traverse
 * @level: level at which the nodes are to be printed
 * @func: a pointer to a function to call for each node
 */
void binary_tree_print_level(const binary_tree_t *tree,
		size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		binary_tree_print_level(tree->left, level - 1, func);
		binary_tree_print_level(tree->right, level - 1, func);
	}
}
