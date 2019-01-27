#include "binary_trees.h"

/**
 * sift_up - sift larger nodes to the top of the max heap
 * @node: Node to check
 * Return: resting place of the value
 */
heap_t *sift_up(heap_t *node)
{
	int temp = 0;

	if (node->parent && node->n > node->parent->n)
	{
		temp = node->parent->n;
		node->parent->n = node->n;
		node->n = temp;
		return (sift_up(node->parent));
	}
	return (node);
}
/**
 * find_depth - find the minimum depth of the tree
 * @node: node to find the depth of
 * Return: int of the depth
 */
int find_depth(heap_t *node)
{
	int left, right;

	if (node == NULL)
		return (0);

	left = find_depth(node->left);
	right = find_depth(node->right);

	return (((left < right) ? left : right) + 1);
}
/**
 * rec_find_end - recursively searches tree for end node
 * @deep: min depth of the tree
 * @depth: current depth of the recursion
 * @node: current node recursion is looking at
 * Return: parent node of the empty slot of the next node
 */
heap_t *rec_find_end(int deep, int depth, heap_t *node)
{
	heap_t *left = NULL;
	heap_t *right = NULL;

	if (depth > deep)
		return (NULL);

	if (node->right == NULL)
		return (node);

	left = (rec_find_end(deep, depth + 1, node->left));
	right = (rec_find_end(deep, depth + 1, node->right));


	if (left != NULL)
		return (left);
	else
		return (right);
}
/**
 * find_end - finds the node who's child is next to be added in a balanced tree
 * @root: root node of the tree
 * Return: node to add too
 */
heap_t *find_end(heap_t *root)
{
	int depth = 0;

	depth = find_depth(root);

	return (rec_find_end(depth - 1, 0, root));
}
/**
 * heap_insert - insert a new node into a max heap
 * @root: root node of the heap. if NULL create new heap
 * @value: value of the new node
 * Return: address of newly created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = binary_tree_node(*root, value);
	heap_t *temp = NULL;

	if (new == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new;
		return (new);
	}

	temp = find_end(*root);
	new->parent = temp;
	if (temp->left == NULL)
		temp->left = new;
	else
		temp->right = new;

	new = sift_up(new);

	return (new);
}
