#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * bst_insert - function entry
 * @tree: double pointer to the tree root
 * @value: value to be node to be inserted
 * Return: 0
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (*tree == NULL)
	{
		new_node = (bst_t *)binary_tree_node((binary_tree_t *)*tree, value);
		return (new_node);
	}
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = (bst_t *)binary_tree_node((binary_tree_t *)*tree, value);
			(*tree)->left = new_node;
			return (new_node);
		}
		else
		{
			return (bst_insert(&((*tree)->left), value));
		}
	}
	else
	{
		if ((*tree)->right == NULL)
		{
			new_node = (bst_t *)binary_tree_node((binary_tree_t *)*tree, value);
			(*tree)->right = new_node;
			return (new_node);
		}
		else
		{
			return ((bst_insert(&((*tree)->right), value)));
		}
	}
}
