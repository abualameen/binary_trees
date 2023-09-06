#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
binary_tree_t *binary_trees_ancestor_recur(const binary_tree_t *tree,
	const binary_tree_t *first, const binary_tree_t *second);
/**
 * binary_trees_ancestor - entry
 * @first: pointer
 * @second: pointer
 * Return: 0
 */


binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *tree1, *tree2;

	if (!first || !second)
	{
		return (NULL);
	}
	tree1 = first;
	while (tree1->parent != NULL)
	{
		tree1 = tree1->parent;
	}
	tree2 = second;
	while (tree2->parent != NULL)
	{
		tree2 = tree2->parent;
	}
	if (tree1 != tree2)
	{
		return (NULL);
	}
	return (binary_trees_ancestor_recur(tree1, first, second));
}





/**
 * binary_trees_ancestor_recur - entry
 * @tree: pointer to the root
 * @first: pointer
 * @second: pointer
 * Return: 0
 */

binary_tree_t *binary_trees_ancestor_recur(const binary_tree_t *tree,
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *left_ancestor, *right_ancestor;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (tree == first || tree == second)
	{
		return ((binary_tree_t *)tree);
	}
	left_ancestor = binary_trees_ancestor_recur(tree->left, first, second);
	right_ancestor = binary_trees_ancestor_recur(tree->right, first, second);
	if (left_ancestor != NULL && right_ancestor != NULL)
	{
		return ((binary_tree_t *)tree);
	}
	else if (left_ancestor != NULL)
	{
		return (left_ancestor);
	}
	else
	{
		return (right_ancestor);
	}
}
