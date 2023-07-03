#include "nary_trees.h"

/**
 * traverse_helper - Helper function to traverse an N-ary tree recursively
 * @node: a pointer to the current node
 * @depth: the depth of the current node
 * @action: pointer to the action function to be executed on each node
 * @max_depth: maximum depth that will return
 */

void traverse_helper(nary_tree_t const *node, size_t depth,
							void (*action)(nary_tree_t const *node, size_t depth), size_t max_depth)
{
	action(node, depth);

	if (depth > max_depth)
	{
		max_depth = depth;
	}

	nary_tree_t *child = node->children;

	while (child)
	{
		traverse_helper(child, depth + 1, action, max_depth);
		child = child->next;
	}
}

/**
 * nary_tree_traverse - Traverses an N-ary
 * tree and performs an action on each node
 * @root: a pointer to the root node of the tree to traverse
 * @action: pointer to the action function to be executed on each node
 * Return: the maximum depth of the tree
 */
size_t nary_tree_traverse(nary_tree_t const *root,
								  void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t max_depth = 0;

	if (!root)
	{
		return (0);
	}

	traverse_helper(root, 0, action, max_depth);

	return (max_depth);
}
