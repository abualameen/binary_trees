#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_insert_left - Entry point
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: 0
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *old_left_child;
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		old_left_child = parent->left;
		new_node->left = old_left_child;
		parent->left->parent = new_node;
	}
	else
	{
		parent->left = new_node;
	}
	return (new_node);
}
