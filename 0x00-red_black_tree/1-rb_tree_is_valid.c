#include <stdlib.h>
#include <stdio.h>
#include "rb_trees.h"

static int max_black;
/**
 * colour_check - colore is valid
 * @cur: pointer to current tree node
 *
 * Return: 1 if color invalid , otherwise 0
 */
int colour_check(const rb_tree_t *cur)
{
	if (cur->color != RED && cur->color != BLACK)
		return (1);
	if (cur->color == RED &&
			((cur->parent && cur->parent->color == RED) ||
			 (cur->left && cur->left->color == RED) ||
			 (cur->right && cur->right->color == RED)))
		return (1);
	return (0);
}
/**
 * bst_check - check binary search tree
 * @cur: pointer to current tree node
 *
 * Return: 1 if BST is  invalid , otherwise 0
 */
int bst_check(const rb_tree_t *cur)
{
	if ((cur->left && cur->left->n > cur->n) ||
			(cur->right && cur->right->n < cur->n))
		return (1);
	return (0);
}
/**
 * check_rb_tree - recursively checks if red-black tree is valid
 * @tree: pointer to tree node
 * @counter_black: count of black nodes
 *
 * Return: 1 if valid, otherwise 0
 */
int check_rb_tree(const rb_tree_t *tree, int counter_black)
{
	if (!tree)
	{
		if (!max_black)
		{
			max_black = counter_black;
		}
		return (1);
	}

	if (colour_check(tree) || bst_check(tree))
		return (0);
	if (tree->color == BLACK)
		counter_black++;

	if (!check_rb_tree(tree->left, counter_black) ||
			!check_rb_tree(tree->right, counter_black))
		return (0);
	if ((!tree->left || !tree->right) && counter_black != max_black)
		return (0);
	return (1);
}
/**
 * rb_tree_is_valid - checks if binary tree is valid red-black tree
 * @tree: pointer to root node
 *
 * Return: 1 if valid, otherwise 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int counter_black;

	if (!tree || tree->color != BLACK)
		return (0);
	max_black = counter_black = 0;
	return (check_rb_tree(tree, counter_black));
}
