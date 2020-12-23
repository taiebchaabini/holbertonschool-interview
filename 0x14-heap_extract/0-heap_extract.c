#include "binary_trees.h"

/**
 * tree_depth - Used the detph of the heap
 * @root: First element in the heap.
 * Return: returns the depth of the heap.
 **/
int tree_depth(heap_t *root)
{
	int left = 0;
	int right = 0;

	if (root == NULL)
		return (0);

	left = tree_depth(root->left);
	right = tree_depth(root->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * find_leaf - Finds last element of the last level in the heap.
 * @root: Pointer to first element in the heap.
 * Return: return pointer to the last element.
 **/
heap_t *find_leaf(heap_t *root)
{
	if (root == NULL)
		return;
	if (!root->right && !root->left)
		return (root);

	if (tree_depth(root->left) > tree_depth(root->right))
		return (find_leaf(root->left));
	if (tree_depth(root->right) > tree_depth(root->left))
		return (find_leaf(root->right));
	return (find_leaf(root->right));
}
/**
 * swap_nodes - Used to swap elements values
 * @parent: First element for swap
 * @child: Second element for swap
 **/
void swap_nodes(heap_t *parent, heap_t *child)
{
	int tmp = child->n;

	child->n = parent->n;
	parent->n = tmp;
}
/**
 * siftDown - Used to repair the heap
 * @parent: First element of the heap
 **/
void siftDown(heap_t **parent)
{
	heap_t *target = (*parent);

	while (target->left && target->n < target->left->n ||
			target->right && target->n < target->right->n)
	{

		if (target->left && target->right && target->left->n > target->right->n)
			target = target->left;
		else if (target->right->n > target->left->n)
			target = target->right;
		swap_nodes(target->parent, target);
	}
}
/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: First element of the heap
 * Return: returns the removed value
 **/
int heap_extract(heap_t **root)
{
	heap_t *leaf = find_leaf((*root));
	heap_t *tmp = (*root);

	tmp->left->parent = leaf;
	leaf->left = tmp->left;

	tmp->right->parent = leaf;
	leaf->right = tmp->right;

	if (leaf->parent->left == leaf)
		leaf->parent->left = NULL;
	else if (leaf->parent->right == leaf)
		leaf->parent->right = NULL;

	leaf->parent = tmp->parent;
	(*root) = leaf;

	free(tmp);
	siftDown(root);
	return (leaf->n);
}
