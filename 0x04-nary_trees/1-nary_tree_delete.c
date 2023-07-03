#include "nary_trees.h"

/**
 * nary_tree_delete - nary_tree_delete
 * @tree: a pointer to parent node
 * Return: void
 */

void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *tmp, *tmp2;

	if (!tree)
		return;
	tmp = tree->children;
	while (tmp)
	{
		tmp2 = tmp->next;
		nary_tree_delete(tmp);
		tmp = tmp2;
	}
	free(tree->content);
	free(tree);
}
