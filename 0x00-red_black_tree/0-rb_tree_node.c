#include <stdlib.h>
#include "rb_trees.h"
/**
 * rb_tree_node - creates a Red-Black Tree node
 * @parent: pointer to parent
 * @value: value of new node
 * @color: color of new node
 *
 * Return: pointer to new node, NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node;

	if (color != RED && color != BLACK && color != DOUBLE_BLACK)
		return (NULL);
	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->color = color;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
