#include "binary_trees.h"

/**
 * struct binary_tree_node - Structure for a binary tree node
 * @n: Integer stored in the node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_node {
	int n;
	struct binary_tree_node *left;
	struct binary_tree_node *right;
} binary_tree_node;

/**
 * struct binary_tree_node - Structure for a binary tree node
 * @n: Integer stored in the node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_node {
	int n;
	struct binary_tree_node *left;
	struct binary_tree_node *right;
} binary_tree_node;

/**
 * struct heap_s - Structure for a binary heap
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s {
	struct binary_tree_node *root;
} heap_t;

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array of integers (in descending order)
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size) {
	int *sorted_array;

	if (heap == NULL || size == NULL)
 	return (NULL);

	*size = 0; // Initialize size to 0

	// Function to get the size of the heap
	size_t get_heap_size(binary_tree_node *node) {
	if (node == NULL)
	return 0;
	return 1 + get_heap_size(node->left) + get_heap_size(node->right);
	}

	// Function to fill the sorted array in descending order
	void fill_sorted_array(binary_tree_node *node, int *arr, size_t *index) {
	if (node == NULL)
	return;

	fill_sorted_array(node->right, arr, index);
	arr[(*index)++] = node->n;
	fill_sorted_array(node->left, arr, index);
	}

	*size = get_heap_size(heap->root);
	sorted_array = malloc(sizeof(int) * (*size));
	if (sorted_array == NULL)
	return (NULL);

	size_t index = 0;
	fill_sorted_array(heap->root, sorted_array, &index);

    return sorted_array;
}
