/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *
 * @root: double pointer to the root node of the heap
 *
 * Return: the value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (root == NULL || *root == NULL)
	return (0);

	int value = (*root)->n;

	heap_t *last_node = get_last_node(*root);

	if (*root == last_node)
	{
	free(*root);
	*root = NULL;
	return (value);
	}

	swap_values(&((*root)->n), &(last_node->n));

	if (last_node->parent->left == last_node)
	last_node->parent->left = NULL;
	else
	last_node->parent->right = NULL;

	free(last_node);

	heapify_down(*root);

	return (value);
}

/**
 * get_last_node - gets the last node in a binary tree
 *
 * @root: pointer to the root node of the tree
 *
 * Return: a pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	if (root == NULL)
	return (NULL);

	while (root->left != NULL || root->right != NULL)
	{
	if (root->right != NULL)
	root = root->right;
	else
	root = root->left;
	}

	return (root);
}

/**
 * heapify_down - restores the Max Heap property after extracting the root node
 *
 * @root: pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;

	while (1)
	{
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left != NULL && left->n > largest->n)
	largest = left;

	if (right != NULL && right->n > largest->n)
	largest = right;

	if (largest == root)
	break;

	swap_values(&(root->n), &(largest->n));
	root = largest;
	}
}

/**
 * swap_values - swaps the values of two integers
 *
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
