#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_is_full - entry
 * @tree: pointer
 * Return: 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);
	if (left_full == 1 && right_full == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}

}
