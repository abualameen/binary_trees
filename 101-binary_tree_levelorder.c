#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
Que *creat_que(binary_tree_t *value);
int is_empty(Que *head);
void enque(Que **head, Que **tail, binary_tree_t *value);
binary_tree_t *deque(Que **head, Que **tail);


/**
 * binary_tree_levelorder - entry func
 * @tree: pointer
 * @func: function
 * Return: 0
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{	
	if (tree == NULL || func == NULL)
	{
	
		return;
	}
	Que *head = NULL;
	Que *tail = NULL;

	enque(&head, &tail, (binary_tree_t *)tree);
	while (!is_empty(head))
	{
		binary_tree_t *current = deque(&head, &tail);

		func(current->n);
		if (current->left != NULL)
		{
			enque(&head, &tail, current->left);
		}
		if (current->right != NULL)
		{
			enque(&head, &tail, current->right);
		}
	}
}


/**
 * creat_que - the entry
 * Return: 0
 */
Que *creat_que(binary_tree_t *value)
{
	Que *newNode;

	newNode = malloc(sizeof(Que));
	if (newNode == NULL)
	{
		printf("memory allocation failed\n");
		exit(1);
	}
	newNode->n = value;
	newNode->next = NULL;
	return (newNode);
}

int is_empty(Que *head)
{
	return (head == NULL);
}
/**
 * enque - main entry point
 * @que: pointer to the que
 * @val: data
 * Return: 0
 */
void enque(Que **head, Que **tail, binary_tree_t *value)
{
	Que *newNode;

	newNode = creat_que(value);
	newNode->next = NULL;
	if (is_empty(*head))
	{
		*head = *tail = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		*tail = newNode;
	}
}


binary_tree_t *deque(Que **head, Que **tail)
{
	binary_tree_t *val;
	Que *oldHead;
	
	if (is_empty(*head))
	{
		printf("Que is empty\n");
		exit(1);
	}
	val = (*head)->n;
	oldHead = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		*head = (*head)->next;
	}
	free(oldHead);
	return (val);
}

