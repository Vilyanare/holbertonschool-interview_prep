#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * recurse_avl - Recursive funcion to make the tree
 * @parent: parent node of tree
 * @array: array of numbers
 * @size: size of the array
 * Return: void
 */
void recurse_avl(avl_t *parent, int *array, size_t size)
{
	int half = (size / 2);
	int iSize = size;
	int left = half - 1 + (size % 2);
	int right = half + 1 + (size % 2);

	parent->n = array[half - 1 + (size % 2)];
	if (left)
	{
		parent->left = malloc(sizeof(avl_t));
		if (parent->left == NULL)
			return;
		parent->left->parent = parent;
		parent->left->right = NULL;
		parent->left->left = NULL;
		recurse_avl(parent->left, array, left);
	}
	if (right <= iSize)
	{
		parent->right = malloc(sizeof(avl_t));
		if (parent->right == NULL)
			return;
		parent->right->parent = parent;
		parent->right->right = NULL;
		parent->right->left = NULL;
		recurse_avl(parent->right, array + half + size % 2, half);
	}
}
/**
 * sorted_array_to_avl - Converts a sorted array into an AVL tree
 * @array: array to convert
 * @size: Size of the array
 * Return: NULL on failure otherwise converted tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new = NULL;

	if (!array || size < 1)
		return (NULL);

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	recurse_avl(new, array, size);

	return new;
}
