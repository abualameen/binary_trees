#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - entry point
 * @tree: pointer to the root node of the tree to measure the heigth
 * Return: 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else if (tree->parent == NULL)
	{
		return (0);
	}
	else
	{
		return (binary_tree_depth(tree->parent) + 1);
	}
}
