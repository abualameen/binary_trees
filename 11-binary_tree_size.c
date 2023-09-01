#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_size - entry point
 * @tree: pointer to the root node of the tree to measure the heigth
 * Return: 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_sub_tree, right_sub_tree;
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_sub_tree = binary_tree_size(tree->left);
		right_sub_tree = binary_tree_size(tree->right);
		return (left_sub_tree + right_sub_tree + 1);
	}
}
