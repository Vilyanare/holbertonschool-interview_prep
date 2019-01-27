#include "binary_trees.h"

/**
 * sift_down - sifts node of the tree downwards
 * @node: node to sift down
 * Return: void
 */
void sift_down(heap_t *node)
{
	heap_t *greater = NULL;
	int temp;

	if (node->right)
		greater = (node->right->n > node->left->n) ? node->right : node->left;
	else if (node->left)
		greater = node->left;

	if (greater)
		if (greater->n > node->n)
		{
			temp = greater->n;
			greater->n = node->n;
			node->n = temp;
			sift_down(greater);
		}
}
/**
 * find_depth - finds max depth of a tree
 * @node: node to start at
 * Return: int of the depth of the tree
 */
int find_depth(heap_t *node)
{
	int left, right;

	if (node == NULL)
		return (0);

	left = find_depth(node->left);
	right = find_depth(node->right);

	return (((left > right) ? left: right) + 1);
}
/**
 * rec_find_end - recursive function to find the end of the tree
 * @depth: depth of current recursion
 * @deep: depth of the tree
 * @node: node current recursion is working with
 * Return: bottom most right node of the tree
 */
heap_t *rec_find_end(int deep, int depth, heap_t *node)
{
	heap_t *left = NULL;
	heap_t *right = NULL;

	if (depth != deep)
	{
		left = rec_find_end(deep, depth + 1, node->left);
		right = rec_find_end(deep, depth + 1, node->right);
	}
	else
	{
		return (node);
	}

	return ((right != NULL) ? right: left);
}
/**
 * find_end - Shell function to find the end node of the a tree
 * @root: root node of tree
 * Return: end node of the tree
 */
heap_t *find_end(heap_t *root)
{
	int depth;

	depth = find_depth(root);

	return (rec_find_end(depth, 1, root));
}
/**
 * heap_extract - remove the top node from a max heap tree
 * @root: root node of tree
 * Return: value stored at the removed node
 */
int heap_extract(heap_t **root)
{
	heap_t *temp = NULL;
	heap_t *nroot = *root;
	int swap;

	if (*root == NULL)
		return (0);

	if (nroot->left == NULL && nroot->right == NULL)
	{
		swap = nroot->n;
		free(*root);
		*root = NULL;
	}
	temp = find_end(*root);
	if (temp->parent->right)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;

	swap = nroot->n;
	nroot->n = temp->n;

	sift_down(*root);

	free(temp);
	return (swap);
}
