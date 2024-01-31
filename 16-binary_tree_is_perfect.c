#include "binary_trees.h"
/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
	return (0);

	if (tree->left == NULL && tree->right == NULL)
 	return (1);

	if (tree->left != NULL && tree->right != NULL)
	return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));

	return (0);
}
