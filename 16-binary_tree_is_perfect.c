#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_perfect_recursive - Helper function to check if a tree is perfect
 * @tree: Pointer to the root node of the tree
 * Return: 0 if not perfect, the level of height otherwise
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree)
{
    int l = 0, r = 0;

    if (tree->left && tree->right)
    {
        l = 1 + binary_tree_is_perfect_recursive(tree->left);
        r = 1 + binary_tree_is_perfect_recursive(tree->right);

        if (r == l && r != 0 && l != 0)
            return (r);

        return (0);
    }
    else if (!tree->left && !tree->right)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return binary_tree_is_perfect_recursive(tree);
}
