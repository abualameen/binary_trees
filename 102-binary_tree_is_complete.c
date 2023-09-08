#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
Que *creat_que(binary_tree_t *value);
int is_empty(Que *head);
void enque(Que **head, Que **tail, binary_tree_t *value);
binary_tree_t *deque(Que **head, Que **tail);


/**
 * binary_tree_is_complete - entry func
 * @tree: pointer to the root
 * Return: 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	Que *head, *tail;
	binary_tree_t *current;
	int flag;

	if (tree == NULL)
	{
		return (0);
	}
	flag = 0;
	head = NULL;
	tail = NULL;

	enque(&head, &tail, (binary_tree_t *)tree);
	while (!is_empty(head))
	{
		current = deque(&head, &tail);
		if (current->left == NULL || current->right == NULL)
		{
			flag = 1;
		}
		if (current->left == NULL)
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			return (0);
		}
		if (current->left != NULL)
		{
			enque(&head, &tail, current->left);
		}
		if (current->right == NULL)
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			return (0);
		}
		if (current->right != NULL)
		{
			enque(&head, &tail, current->right);
		}
	}
	return (1);
}


/**
 * creat_que - the entry
 * @value: data
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

/**
 * is_empty - the function entry
 * @head: heat of the linked list
 * Return: 0
 */
int is_empty(Que *head)
{
	return (head == NULL);
}
/**
 * enque - main entry point
 * @head: pointer to the the head
 * @tail: pointer to the tail
 * @value: data
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

/**
 * deque - the main entry point
 * @head: pointer to the head
 * @tail: pointer to the tail
 * Return: 0
 */
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
