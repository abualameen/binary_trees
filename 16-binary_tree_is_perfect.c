#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
size_t max(size_t arg1, size_t arg2);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - entry
 * @tree: pointer
 * Return: 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_perfect, right_perfect, left_height, right_height; 
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	left_perfect = binary_tree_is_perfect(tree->left);
	right_perfect = binary_tree_is_perfect(tree->right);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_perfect == 1 && right_perfect == 1 && left_height == right_height)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_height - entry point
 * @tree: pointer to the root node of the tree to measure the heigth
 * Return: 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height, left_height;

	if (tree == NULL)
	{
		return (0);
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	else
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		return (max(left_height, right_height) + 1);
	}
}

/**
 * max - max function
 * @arg1: argument 1
 * @arg2: argument 2
 * Return: max of arg1 and arg2
 */

size_t max(size_t arg1, size_t arg2)
{
	if (arg1 > arg2)
	{
		return (arg1);
	}
	else
	{
		return (arg2);
	}
}
