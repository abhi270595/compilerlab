#include<stdio.h>
#include<stdlib.h>

int symbol[26];

struct tree_node
{
	char type_opt;
	int val;
	char location;
	char *construct;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node * mkCondNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkBoolOptNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkOperatorNode(char opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->type_opt=opt;
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkEquNode(char opt,char loc,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->type_opt=opt;
	root->location=loc;
	root->left=NULL;
	root->right=right;
	return root;
}

struct tree_node * mkLeafNode_Num(int num)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->type_opt='`';
	root->val=num;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkLeafNode_Id(char opt)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->type_opt=opt;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkWNode(struct tree_node *left)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->left=left;
	root->right=NULL;
	return root;
}

struct tree_node * mkRNode(char variable)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->location=variable;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkListNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->type_opt='@';
	root->left=left;
	root->right=right;
	return root;
}

int evaluate(struct tree_node *root)
{
	int retval;
	if(root->type_opt=='@')
	{
		retval=evaluate(root->left);
		retval=evaluate(root->right);
		return 0;
	}
	else if(root->construct=="IF")
	{
		if(evaluate(root->left))
			retval=evaluate(root->right);
		return 0;
	}
	else if(root->construct=="WHILE")
	{
		while(evaluate(root->left))
			retval=evaluate(root->right);
		return 0;
	}
	else if(root->construct==">")
		return evaluate(root->left)>evaluate(root->right);
	else if(root->construct=="<")
		return evaluate(root->left)<evaluate(root->right);
	else if(root->construct=="==")
		return evaluate(root->left)==evaluate(root->right);
	else if(root->type_opt=='`')
        return root->val;
	else if(root->type_opt=='+')
        return evaluate(root->left)+evaluate(root->right);
	else if(root->type_opt=='*')
        return evaluate(root->left)*evaluate(root->right);
	else if(root->type_opt=='=')
	{
		symbol[root->location-'a']=evaluate(root->right);
		return 0;
	}	
	else if(root->left==NULL && root->right==NULL && root->location>='a' && root->location<='z')
	{
		scanf("%d",&symbol[root->location-'a']);
		return 0;
	}
	else if(root->left!=NULL && root->right==NULL)
	{
		printf("%d\n",evaluate(root->left));
		return 0;
	}
	else if(root->type_opt>='a' && root->type_opt<='z')
		return symbol[root->type_opt-'a'];
}
