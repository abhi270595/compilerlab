#include<stdio.h>
#include<stdlib.h>

struct tree_node
{
	char operation;
	int value;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node * mkOperatorNode(char opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->operation=opt;
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkLeafNode(int num)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->operation='`';
	root->value=num;
	root->left=NULL;
	root->right=NULL;
	return root;
}

void preorder(struct tree_node *root)
{
	if(root->operation=='`')
		printf("%d",root->value);
	else
	{
		printf("(");
		preorder(root->left);
		printf(" %c ",root->operation);
		preorder(root->right);
		printf(")");
	}	
}

int evaluate(struct tree_node *root)
{
	if(root->operation=='`')
		return root->value;
	else
	{
		if(root->operation=='+')
			return evaluate(root->left)+evaluate(root->right);
		else if(root->operation=='-')
			return evaluate(root->left)-evaluate(root->right);
		else if(root->operation=='/')
			return evaluate(root->left)/evaluate(root->right);
		else if(root->operation=='*')
			return evaluate(root->left)*evaluate(root->right);
		else if(root->operation=='%')
			return evaluate(root->left)%evaluate(root->right);
	}
}
