#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_nodes - func entry point
 * @tree: pointer
 * Return: 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_lefts, node_rights, count;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left != NULL || tree->right != NULL)
		{
			count = 1;
		}
		else
		{
			count = 0;
		}
		node_lefts = binary_tree_nodes(tree->left);
		node_rights= binary_tree_nodes(tree->right);
		return (count + node_lefts + node_rights);
	}
}
