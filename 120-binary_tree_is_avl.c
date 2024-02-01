#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_is_avl_helper(tree) != -1);
}

/**
 * binary_tree_is_avl_helper - recursive helper function for binary_tree_is_avl
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: the height of the tree if it is an AVL Tree, and -1 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_is_avl_helper(tree->left);
    if (left_height == -1)
        return (-1);

    right_height = binary_tree_is_avl_helper(tree->right);
    if (right_height == -1)
        return (-1);

    if (abs(left_height - right_height) > 1)
        return (-1);

    return (1 + MAX(left_height, right_height));
}
