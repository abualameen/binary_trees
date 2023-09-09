#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function entry
 * @tree: pointer to the root
 * Return: 0
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *current, *new_root;

	if (tree == NULL || tree->right == NULL)
	{
		return (tree);
	}
	current = tree;
	new_root = current->right;
	current->right = new_root->left;

	if (new_root->left != NULL)
	{
		new_root->left->parent = current;
	}
	new_root->parent = current->parent;
	if (current->parent == NULL)
	{
		tree = new_root;
	}
	else if (current->parent->left == current)
	{
		current->parent->left = new_root;
	}
	else
	{
		current->parent->right = new_root;
	}
	new_root->left = current;
	current->parent = new_root;
	return (tree);
}
