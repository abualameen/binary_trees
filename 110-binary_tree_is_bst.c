#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
int check_if_bst(binary_tree_t *node, double last_visted_node_value);
/**
 * binary_tree_is_bst - the entry point
 * @tree: the pointer to the root
 * Return: 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	double last_visted_node_value = -DBL_MAX;

	if (tree == NULL)
	{
		return (0);
	}
	return (check_if_bst((binary_tree_t *)tree, last_visted_node_value));
}
/**
 * check_if_bst - function entry
 * @node: pointer to the root
 * @last_visted_node_value: data
 * Return: 0
 */
int check_if_bst(binary_tree_t *node, double last_visted_node_value)
{
	if (node == NULL)
	{
		return (1);
	}
	if (!check_if_bst(node->left, last_visted_node_value))
	{
		return (0);
	}
	if (last_visted_node_value != -DBL_MAX && node->n <= last_visted_node_value)
	{
		return (0);
	}
	last_visted_node_value = node->n;
	return (check_if_bst(node->right, last_visted_node_value));
}
