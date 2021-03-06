#include <stdio.h>
#include <stdlib.h>

typedef struct node	{
	struct node * left;
	int key;
	struct node * right;
	struct node * parent;
} node;

node * insert(int, node *, node *);
void ancestors(int, node *);
void printparents(node *);

int main()
{
	int n;
	scanf("%d", &n);

	node * root;
	root = NULL;
	
	for (int i = 0; i < n; i++)	{
		int data;
		scanf("%d", &data);
		root = insert(data, root, NULL);

	}
	scanf("%d", &n);
	ancestors(n, root);

	return 0;

}

node * insert(int key, node * root, node * parent)
{
	if(!root)	{
		node * new;
		new = malloc(sizeof(node));
		*new = (node) {NULL, key, NULL, parent};
		return new;

	}

	if (key < root->key)
		root->left = insert(key, root->left, root);
	else
		root->right = insert(key, root->right, root);

	return root;

}

void ancestors(int key, node * root)
{
	if (!root)
		return;
	else if (root->key == key)	{
		printparents(root->parent);
		printf("\n");

	}
	else if (key < root->key)
		ancestors(key, root->left);
	else
		ancestors(key, root->right);

}

void printparents(node * n)
{
	if(!n)
		return;
	printparents(n->parent);
	printf("%d_", n->key);

}
