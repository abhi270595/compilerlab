#include <stdio.h>
#include <stdlib.h>
#include "Gsymbol.h"

extern yylineno;

int symbol[26];

struct tree_node
{
	int val;
    	char *type;
	struct Gsymbol *variable;
	char *construct;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node * mkPgmNode(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%PGM%";
    	root->type="%VOID%";
	root->left=left;
	root->right=right;
	return root;
}

struct tree_node * mkCondNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
    	root->type="%VOID%";
	root->left=left;
	root->right=right;
    	if(root->left->type!="%BOOLEAN%")
    	{
        	printf("Syntax Error:Line No-%d, Invalid Type for the Condition Argument\n",yylineno);
        	exit(1);
    	}
	return root;
}

struct tree_node * mkBoolOptNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
    	if(root->left->type!="%INTEGER%" || root->right->type!="%INTEGER%")
    	{
        	printf("Syntax Error:Line No-%d, Invalid Type of Oprands to a Boolean Operator %s\n",yylineno,opt);
       		exit(1);
    	}
        root->type="%BOOLEAN%";
	return root;
}

struct tree_node * mkOperatorNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
    	if(root->left->type!="%INTEGER%" || root->right->type!="%INTEGER%")
    	{
       		printf("Syntax Error:Line No-%d, Invalid Type of Oprands to a Arithmetic Operator %s\n",yylineno,opt);
        	exit(1);
    	}
        root->type="%INTEGER%";
	return root;
}

struct tree_node * mkEquNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
    	if(root->left->type!=root->right->type)
    	{
        	printf("Syntax Error:Line No-%d, An Boolean Variable Cannot be assigned to an Arithmetic Expression\n",yylineno);
        	exit(1);
    	}
    	root->type="%VOID%";
	return root;
}

struct tree_node * mkLeafNode_Num(int num)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%NUM%";
	root->val=num;
	root->left=NULL;
	root->right=NULL;
    	root->type="%INTEGER%";
	return root;
}

struct tree_node * mkLeafNode_Bool(char *value)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%BOOL%";
	if(strcmp(value,"TRUE") == 0)
        	root->val=1;
    	else
        	root->val=0;
	root->left=NULL;
	root->right=NULL;
    	root->type="%BOOLEAN%";
	return root;
}


struct tree_node * mkWNode(struct tree_node *left)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%WRITE%";
	root->left=left;
	root->right=NULL;
    	root->type="%VOID%";
	return root;
}

struct tree_node * mkRNode(char *var)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%READ%";
	struct Gsymbol *temp=Glookup(head,var,"%ID%");	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		exit(1);
	}
	root->variable=temp;
	root->left=NULL;
	root->right=NULL;
    	root->type="%VOID%";
	return root;
}

struct tree_node * mkRArrNode(char *var,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%READARR%";
	struct Gsymbol *temp=Glookup(head,var,"%ARR%");	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Array %s was undeclared\n",yylineno,var);
		exit(1);
	}
    	if(right->type!="%INTEGER%")
    	{
        	printf("Syntax Error:Line No-%d, Array index cannot be of Another Type except Integer\n",yylineno);
    		exit(1);
   	}
	root->variable=temp;
	root->left=NULL;
	root->right=right;
    	root->type="%VOID%";
	return root;
}

struct tree_node * ckLeafNode_Id(char *var)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDNODE%";
	struct Gsymbol *temp=Glookup(head,var,"%ID%");	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		exit(1);
	}
	root->variable=temp;
    	if(root->variable->type==2)
        	root->type="%INTEGER%";
    	else
        	root->type="%BOOLEAN%";
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * ckLeafNode_Arr(char *var,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%ARRNODE%";
	struct Gsymbol *temp=Glookup(head,var,"%ARR%");	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Array %s was undeclared\n",yylineno,var);
		exit(1);
	}
    	if(right->type!="%INTEGER%")
    	{
        	printf("Syntax Error:Line No-%d, Array index cannot be of Another Type except Integer\n",yylineno);
    		exit(1);
   	}
	root->variable=temp;
    	if(root->variable->type==2)
        	root->type="%INTEGER%";
  	else
        	root->type="%BOOLEAN%";
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
    	root->type="%VOID%";
	return root;
}

int evaluate(struct tree_node *root)
{
	int retval;
	if(strcmp(root->construct,"%PGM%")==0)
	{
		retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%LIST%")==0)
	{
		retval=evaluate(root->left);
		retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%IF%")==0)
	{
		if(evaluate(root->left))
			retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%WHILE%")==0)
	{
		while(evaluate(root->left))
			retval=evaluate(root->right);
		return 0;
	} 
	else if(strcmp(root->construct,">")==0)
        return evaluate(root->left)>evaluate(root->right);
	else if(strcmp(root->construct,"<")==0)
		return evaluate(root->left)<evaluate(root->right);
	else if(strcmp(root->construct,"==")==0)
		return evaluate(root->left)==evaluate(root->right);
	else if(strcmp(root->construct,">=")==0)
		return evaluate(root->left)>=evaluate(root->right);
	else if(strcmp(root->construct,"<=")==0)
		return evaluate(root->left)<=evaluate(root->right);
	else if(strcmp(root->construct,"!=")==0)
		return evaluate(root->left)!=evaluate(root->right); 
	else if(strcmp(root->construct,"%NUM%")==0)
        	return root->val;
	else if(strcmp(root->construct,"%BOOL%")==0)
        	return root->val;
	else if(strcmp(root->construct,"+")==0)
        	return evaluate(root->left)+evaluate(root->right);
	else if(strcmp(root->construct,"*")==0)
        	return evaluate(root->left)*evaluate(root->right);
	else if(strcmp(root->construct,"-")==0)
        	return evaluate(root->left)-evaluate(root->right);
	else if(strcmp(root->construct,"/")==0)
        	return evaluate(root->left)/evaluate(root->right);
	else if(strcmp(root->construct,"%")==0)
        	return evaluate(root->left)%evaluate(root->right);
	else if(strcmp(root->construct,"=")==0)
	{
		if(strcmp(root->left->construct,"%IDNODE%")==0)
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
	else if(strcmp(root->construct,"%IDNODE%")==0)	
		return root->variable->binding[0];
	else if(strcmp(root->construct,"%ARRNODE%")==0)
	{
		retval=evaluate(root->right);
		if(retval<0 || retval>=root->variable->size)
		{
			printf("Syntax Error: Segmentation Fault Core Dumped\n");
			exit(1);
		}
		else
			return root->variable->binding[retval];
	}		
	else if(strcmp(root->construct,"%READ%")==0)
	{
		scanf("%d",&root->variable->binding[0]);
		return 0;
	}
	else if(strcmp(root->construct,"%READARR%")==0)
	{
		retval=evaluate(root->right);
		if(retval<0 || retval>=root->variable->size)
		{
			printf("Syntax Error: Segmentation Fault Core Dumped\n");
			exit(1);
		}
		else
			scanf("%d",&root->variable->binding[retval]);
		return 0;
	}
	else if(strcmp(root->construct,"%WRITE%")==0)
	{
		printf("%d\n",evaluate(root->left));
		return 0;
	}
	else
		return 0;
}	
