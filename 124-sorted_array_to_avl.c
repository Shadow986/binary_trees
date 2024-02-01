#include "binary_trees.h"
/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
	return NULL;

	return sorted_array_to_avl_helper(array, 0, size - 1);
}

/**
 * sorted_array_to_avl_helper - recursive helper function for sorted_array_to_avl
 *
 * @array: pointer to the first element of the array to be converted
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 *
 * Return: a pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
	if (start > end)
	return NULL;

	int mid = (start + end) / 2;
	avl_t *root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
	return NULL;

	root->left = sorted_array_to_avl_helper(array, start, mid - 1);
	root->right = sorted_array_to_avl_helper(array, mid + 1, end);

	return root;
}
