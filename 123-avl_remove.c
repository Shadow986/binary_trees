#include "binary_trees.h"

/**
 * avl_remove - removes a node from an AVL tree
 *
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
	return (NULL);

	root = avl_remove_helper(root, value);

	return (root);
}

/**
 * avl_remove_helper - recursive helper function for avl_remove
 *
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing the desired value
 */
avl_t *avl_remove_helper(avl_t *root, int value)
{
	if (root == NULL)
	return (NULL);
	
if (value < root->n)
	{
	root->left = avl_remove_helper(root->left, value);
	}
	else if (value > root->n)
	{
	root->right = avl_remove_helper(root->right, value);
	}
	else
	{
	if (root->left == NULL || root->right == NULL)
	{
	avl_t *temp = root->left ? root->left : root->right;

	if (temp == NULL)
	{
	temp = root;
	root = NULL;
	}
	else
	{
	*root = *temp;
	}

	free(temp);
	}
	else
	{
	avl_t *temp = avl_minimum_value_node(root->right);

	root->n = temp->n;

	root->right = avl_remove_helper(root->right, temp->n);
	}
	}

	if (root == NULL)
	return (NULL);

	root->height = 1 + MAX(avl_get_height(root->left), avl_get_height(root->right));

	int balance = avl_get_balance(root);

	if (balance > 1 && avl_get_balance(root->left) >= 0)
	{
	return (binary_tree_rotate_right(root));
	}

	if (balance > 1 && avl_get_balance(root->left) < 0)
	{
	root->left = binary_tree_rotate_left(root->left);
	return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && avl_get_balance(root->right) <= 0)
	{
	return (binary_tree_rotate_left(root));
	}

	if (balance < -1 && avl_get_balance(root->right) > 0)
	{
 	root->right = binary_tree_rotate_right(root->right);
	return (binary_tree_rotate_left(root));
	}

	return (root);
}

/**
 * avl_minimum_value_node - finds the node with the minimum value in an AVL tree
 *
 * @root: pointer to the root node of the AVL tree
 *
 * Return: a pointer to the node with the minimum value
 */
avl_t *avl_minimum_value_node(avl_t *root)
{
	avl_t *current = root;

	while (current->left != NULL)
	current = current->left;

	return (current);
}

/**
 * avl_get_height - gets the height of an AVL tree
 *
 * @node: pointer to the root node of the AVL tree
 *
 * Return: the height of the AVL tree
 */
int avl_get_height(avl_t *node)
{
	if (node == NULL)
	return (0);

	return (node->height);
}

/**
 * avl_get_balance - gets the balance factor of an AVL tree
 *
 * @node: pointer to the root node of the AVL tree
 *
 * Return: the balance factor of the AVL tree
 */
int avl_get_balance(avl_t *node)
{
	if (node == NULL)
	return (0);

	return (avl_get_height(node->left) - avl_get_height(node->right));
}
