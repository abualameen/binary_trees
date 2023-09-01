#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_leaves - func entry point
 * @tree: pointer to the root node of the tree to count the num of leaves
 * Return: int
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leafs, right_leafs;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			return (1);
		}
		else
		{
			left_leafs = binary_tree_leaves(tree->left);
			right_leafs = binary_tree_leaves(tree->right);
			return (left_leafs + right_leafs);
		}
	}
}
