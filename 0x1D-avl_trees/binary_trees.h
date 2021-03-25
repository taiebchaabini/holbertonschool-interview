#ifndef binary_trees_h
#define binary_trees_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
size_t tree_max_height(const binary_tree_t *node);
void inOrder_checkBST(binary_tree_t *tree, int dir, int max, int *count);
binary_tree_t *binary_tree_node(binary_tree_t *, int);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif
