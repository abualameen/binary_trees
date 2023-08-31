#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_delete - entry point
 * @tree: the pointer to the root node of the tree to delete
 * Return: 0
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	free(tree);
}
