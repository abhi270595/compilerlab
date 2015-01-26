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
	int i,flag=1;
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%ID%";
	for(i=0;i<keysize;i++)
	{
		if(strcmp(opt,keywords[i])==0)
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
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
	int i,flag=1;
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDARRAY%";
	for(i=0;i<keysize;i++)
	{
		if(strcmp(opt,keywords[i])==0)
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
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

struct tree_node * mkRArrNode(char *var,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%READARR%";
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Array %s was undeclared\n",var);
		exit(1);
	}
	root->variable=temp;
	root->left=NULL;
	root->right=right;
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

struct tree_node * ckLeafNode_Arr(char *var,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%ARRNODE%";
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Array %s was undeclared\n",var);
		exit(1);
	}
	root->variable=temp;
	root->left=NULL;
	root->right=right;
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
	if(root->construct=="%PGM%")
	{
		retval=evaluate(root->left);
		retval=evaluate(root->right);
		return 0;
	}
	else if(root->construct=="%LIST%")
	{
		retval=evaluate(root->left);
		retval=evaluate(root->right);
		return 0;
	}
	else if(root->construct=="%IF%")
	{
		if(evaluate(root->left))
			retval=evaluate(root->right);
		return 0;
	}
	else if(root->construct=="%WHILE%")
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
	else if(root->construct=="%NUM%")
        	return root->val;
	else if(root->construct=="+")
        	return evaluate(root->left)+evaluate(root->right);
	else if(root->construct=="*")
        	return evaluate(root->left)*evaluate(root->right);
	else if(root->construct=="-")
        	return evaluate(root->left)-evaluate(root->right);
	else if(root->construct=="/")
        	return evaluate(root->left)/evaluate(root->right);
	else if(root->construct=="%")
        	return evaluate(root->left)%evaluate(root->right);
	else if(root->construct=="=")
	{
		if(root->left->construct=="%IDNODE%")
			root->left->variable->binding[0]=evaluate(root->right);
		else
		{
			retval=evaluate(root->left->right);
			if(retval<0 || retval>=root->left->variable->size)
			{
				printf("Parsing Error: Segmentation Fault Core Dumped\n");
				exit(1);
			}
			else
				root->left->variable->binding[retval]=evaluate(root->right);
		}
		return 0;
	}
	else if(root->construct=="%IDNODE%")	
		return root->variable->binding[0];
	else if(root->construct=="%ARRNODE%")
	{
		retval=evaluate(root->right);
		if(retval<0 || retval>=root->variable->size)
		{
			printf("Parsing Error: Segmentation Fault Core Dumped\n");
			exit(1);
		}
		else
			return root->variable->binding[retval];
	}		
	else if(root->construct=="%READ%")
	{
		scanf("%d",&root->variable->binding[0]);
		return 0;
	}
	else if(root->construct=="%READARR%")
	{
		retval=evaluate(root->right);
		if(retval<0 || retval>=root->variable->size)
		{
			printf("Parsing Error: Segmentation Fault Core Dumped\n");
			exit(1);
		}
		else
			scanf("%d",&root->variable->binding[retval]);
		return 0;
	}
	else if(root->construct=="%WRITE%")
	{
		printf("%d\n",evaluate(root->left));
		return 0;
	}
	else
		return 0;
}	
