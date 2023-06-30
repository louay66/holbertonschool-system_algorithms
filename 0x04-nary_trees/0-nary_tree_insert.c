#include "nary_trees.h"

/**
 * nary_tree_insert - inserts  node in  N-ary tree
 * @parent: a pointer to parent node
 * @str: string to be stored in the created node
 * Return: nary_tree_t
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new;

	new = malloc(sizeof(nary_tree_t));

	if (!new)
		return (NULL);

	new->parent = parent;
	new->content = strdup(str);
	new->nb_children = 0;
	new->children = NULL;
	new->next = NULL;

	if (new && parent)
	{
		parent->nb_children++;
		if (parent->children)
		{
			new->next = parent->children;
		}
		parent->children = new;
	}
	return (new);
}
