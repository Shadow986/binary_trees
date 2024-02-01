#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, the function will return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *m, *n;

    if (first == NULL || second == NULL)
        return (NULL);

    for (m = (binary_tree_t *)first; m; m = m->parent)
    {
        for (n = (binary_tree_t *)second; n; n = n->parent)
        {
            if (m == n)
                return (m);
        }
    }

    return (NULL);
}
