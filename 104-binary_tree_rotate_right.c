#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function entry
 * @tree: pointer to the root
 * Return: 0
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *current, *new_root;

	if (tree == NULL || tree->left == NULL)
	{
		return (tree);
	}
	current = tree;
	new_root = current->left;
	current->left = new_root->right;
	if (new_root->right != NULL)
	{
		new_root->right->parent = current;
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
	new_root->right = current;
	current->parent = new_root;
	return (new_root);

}
