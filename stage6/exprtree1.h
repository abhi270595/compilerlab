#include <stdio.h>
#include <stdlib.h>
#include "Gsymbol.h"

int symbol[26];

struct tree_node
{
	int val;
	struct Gsymbol *variable;
	char *construct;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node * mkPgmNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%PGM%";
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkDecllistNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%DECLLIST%";
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkDeclNode(char *opt,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=NULL;
	root->right=right;
	return root;
}

struct tree_node * mkIdlistvarNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDLISTVAR%";
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkIdlistarrNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDLISTARR%";
	root->left=left;
	root->right=right;
	return root;
}

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

struct tree_node * mkOperatorNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkEquNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkLeafNode_Num(int num)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%NUM%";
	root->val=num;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkLeafNode_Id(char *opt)
{
	int i;
	bool flag=true;
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%ID%";
	for(i=0;i<keysize;i++)
	{
		if(strcmp(opt,keywords[i])==0)
		{
			flag=false;
			break;
		}
	}
	if(!flag)
	{
		printf("Syntax Error:Variable name %s is the Keyword in the following language\n",opt);
		exit(1);
	}
	root->variable=Ginstall(opt,1,1);
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkLeafNode_Array(char *opt,int size)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDARRAY%";
	for(i=0;i<keysize;i++)
	{
		if(strcmp(opt,keywords[i])==0)
		{
			flag=false;
			break;
		}
	}
	if(!flag)
	{
		printf("Syntax Error:Array name %s is the Keyword in the following language\n",opt);
		exit(1);
	}
	root->variable=Ginstall(opt,1,size);
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkWNode(struct tree_node *left)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%WRITE%";
	root->left=left;
	root->right=NULL;
	return root;
}

struct tree_node * mkRNode(char *var)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%READ%";
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Variable %s was undeclared\n",var);
		exit(1);
	}
	root->variable=temp;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkRArrNode(char *var,int loc)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%READARR%";
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Array %s was undeclared\n",var);
		exit(1);
	}
	if(loc>=temp->size || loc<0)
	{
		printf("Syntax Error:Segmentation Fault\n",var);
		exit(1);
	}
	root->val=loc;
	root->variable=temp;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * ckLeafNode_Id(char *var)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDNODE%";
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Variable %s was undeclared\n",var);
		exit(1);
	}
	root->variable=temp;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * ckLeafNode_Arr(char *var,int loc)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%ARRNODE%";
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Array %s was undeclared\n",var);
		exit(1);
	}
	if(loc>=temp->size || loc<0)
	{
		printf("Syntax Error:Segmentation Fault\n",var);
		exit(1);
	}
	root->val=loc;
	root->variable=temp;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * mkListNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%LIST%";
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
