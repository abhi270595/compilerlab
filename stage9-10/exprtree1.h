#include <stdio.h>
#include <stdlib.h>
#include "Gsymbol.h"

extern yylineno;

int symbol[26];

struct tree_node
{
	int val;
    	int type;
	struct Gsymbol *variable;
	char *construct;
	struct tree_node *left;
	struct tree_node *middle;
	struct tree_node *right;
	struct Lsymbol *lsymbol;
	struct Argstruct *ARGLIST;
};

int pre_reg=0;
int label=1;

void insertlocal(struct Argstruct *ARGLIST)
{
	struct Argstruct *temp1=ARGLIST;
	int binding=-3;
	while(temp1!=NULL)
	{
		Linstall(temp1->name,temp1->type,binding);
		binding-=1;
		temp1=temp1->next;
	}
}

struct tree_node * mkFDefNode(char *name,int type,struct Argstruct *ARGLIST,struct tree_node *right)
{
	struct Gsymbol *tmp=Glookup(head,name,"%FUNCTION%");
	struct Argstruct *temp,*temp1;
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	if(tmp!=NULL || strcmp(name,"main")==0)
	{
		if(strcmp(name,"main")!=0)
		{
			temp=tmp->ARGLIST;
			temp1=ARGLIST;
			while(temp!=NULL && temp1!=NULL && strcmp(temp->name,temp1->name)==0 && temp->type==temp1->type)
			{
				temp=temp->next;
				temp1=temp1->next;
			}
			if(temp!=NULL && temp1!=NULL && (strcmp(temp->name,temp1->name)!=0 || temp->type!=temp1->type))
			{
				printf("Syntax Error:Line No-%d, %s function's Arguments did not match to the defination\n",yylineno,name);
       				exit(1);
			}	
			if(tmp->isdef!=0)
			{
				printf("Syntax Error:Line No-%d, Function %s is already defined\n",yylineno,name);
       				exit(1);
			}
			tmp->isdef=1;
		}
		temp1=ARGLIST;
		root->construct="%FUNCTION%";
        	root->type=type;
		root->lsymbol=lsym;
		root->variable=tmp;
		root->ARGLIST=ARGLIST;
		root->left=NULL;
		root->middle=NULL;
		root->right=right;
		lbind=1;
		return root;
        }
	else
	{
		printf("Syntax Error:Line No-%d, Function %s is not defined\n",yylineno,name);
       		exit(1);
	}	
}

struct tree_node * mkCondNode(char *opt,struct tree_node *left,struct tree_node *middle,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
    	root->type=0;
	root->left=left;
	root->middle=middle;
	root->right=right;
    	if(root->left->type!=1)
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
    	if(root->left->type!=2 || root->right->type!=2)
    	{
        	printf("Syntax Error:Line No-%d, Invalid Type of Oprands to a Boolean Operator %s\n",yylineno,opt);
       		exit(1);
    	}
        root->type=1;
	return root;
}

struct tree_node * mkBoolOptBoolNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
    	if(root->left->type!=1 || root->right->type!=1)
    	{
        	printf("Syntax Error:Line No-%d, Invalid Type of Oprands to a Boolean Operator %s\n",yylineno,opt);
       		exit(1);
    	}
        root->type=1;
	return root;
}

struct tree_node * mkBoolOptNotNode(char *opt,struct tree_node *left)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=NULL;
    	if(root->left->type!=1)
    	{
        	printf("Syntax Error:Line No-%d, Invalid Type of Oprands to a Boolean Operator %s\n",yylineno,opt);
       		exit(1);
    	}
        root->type=1;
	return root;
}

struct tree_node * mkOperatorNode(char *opt,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	root->right=right;
    	if(root->left->type!=2 || root->right->type!=2)
    	{
       		printf("Syntax Error:Line No-%d, Invalid Type of Oprands to a Arithmetic Operator %s\n",yylineno,opt);
        	exit(1);
    	}
        root->type=2;
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
    	root->type=0;
	return root;
}

struct tree_node * mkLeafNode_Num(int num)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%NUM%";
	root->val=num;
	root->left=NULL;
	root->right=NULL;
    	root->type=2;
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
    	root->type=1;
	return root;
}


struct tree_node * mkWNode(struct tree_node *left)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%WRITE%";
	root->left=left;
	root->right=NULL;
    	root->type=0;
	return root;
}

struct tree_node * mkRNode(char *var)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%READ%";
	struct Gsymbol *temp=Glookup(head,var,"%ID%");	
	struct Lsymbol *temp1=Llookup(lsym,var);
	root->lsymbol=NULL;
	root->variable=NULL;
	if(temp1==NULL && temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		exit(1);
	}
	else if(temp1!=NULL)
		root->lsymbol=temp1;
	else
		root->variable=temp;
	root->left=NULL;
	root->right=NULL;
    	root->type=0;
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
    	if(right->type!=2)
    	{
        	printf("Syntax Error:Line No-%d, Array index cannot be of Another Type except Integer\n",yylineno);
    		exit(1);
   	}
	root->variable=temp;
	root->left=NULL;
	root->right=right;
    	root->type=0;
	return root;
}

struct tree_node * ckLeafNode_Id(char *var)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%IDNODE%";
	struct Gsymbol *temp=Glookup(head,var,"%ID%");	
	struct Lsymbol *temp1=Llookup(lsym,var);
	root->lsymbol=NULL;
	root->variable=NULL;	
	if(temp1==NULL && temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		exit(1);
	}
	else if(temp1!=NULL)
	{
		root->lsymbol=temp1;
    		root->type=root->lsymbol->type;
	}
	else
	{
		root->variable=temp;
    		root->type=root->variable->type;
	}
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
    	if(right->type!=2)
    	{
        	printf("Syntax Error:Line No-%d, Array index cannot be of Another Type except Integer\n",yylineno);
    		exit(1);
   	}
	root->variable=temp;
    	root->type=root->variable->type;
	root->left=NULL;
	root->right=right;
	return root;
}

struct tree_node * ckLeafNode_Function(char *var,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%FUNCTIONCALL%";
	struct Gsymbol *temp=Glookup(head,var,"%FUNCTION%");
	struct tree_node *temp1=right;
	struct Argstruct *temp2=temp->ARGLIST;	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Function %s was undeclared\n",yylineno,var);
		exit(1);
	}
	while(temp1!=NULL && temp2!=NULL && temp1->right->type==temp2->type)
	{
		temp1=temp1->left;
		temp2=temp2->next;
	}
	if(temp1!=NULL || temp2!=NULL)
	{
		printf("Syntax Error:Line No-%d, Function %s calling arguments did not match with function %s defination\n",yylineno,var,var);
		exit(1);
	}
	root->variable=temp;
    	root->type=root->variable->type;
	root->left=NULL;
	root->right=right;
	return root;
}

struct tree_node * mkReturnNode(struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	if(retvaltype!=right->type)
	{
		printf("Syntax Error:Line No-%d, Function's return type did not match\n",yylineno);
		exit(1);
	}
	root->construct="%RET%";
	root->left=NULL;
	root->right=right;
    	root->type=right->type;
	return root;
}

struct tree_node * mkNode(char *construct,struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=construct;
	root->left=left;
	root->right=right;
    	root->type=0;
	return root;
}

int evaluate(struct tree_node *root)
{
	int retval,loclabel,loclabel1;
	if(strcmp(root->construct,"%FUNCTION%")==0)
	{
		//lsym=root->lsymbol;
		//printf("%s: ",root->variable->name);
		
	}
	else if(strcmp(root->construct,"%BODY%")==0)
	{
		retval=evaluate(root->left);
		retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%EXPRLIST%")==0)
	{
		retval=evaluate(root->left);
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
		retval=evaluate(root->left);
		printf("JZ R%d, L%d\n",pre_reg,label);
		loclabel=label;
		label+=1;
		retval=evaluate(root->right);		
		printf("L%d: ",loclabel);
		//if(evaluate(root->left))
		//	retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%IFELSE%")==0)
	{
		retval=evaluate(root->left);
		printf("JZ R%d, L%d\n",pre_reg,label);
		loclabel=label;
		label+=1;
		retval=evaluate(root->middle);
		printf("JMP L%d\n",label);
		loclabel1=label;
		label+=1;
		printf("L%d: ",loclabel);		
		retval=evaluate(root->right);		
		printf("L%d: ",loclabel1);
		//if(evaluate(root->left))
		//	retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%WHILE%")==0)
	{
		printf("L%d: ",label);
		retval=evaluate(root->left);
		printf("JZ R%d, L%d\n",pre_reg,label+1);
		loclabel=label+1;
		label+=2;
		retval=evaluate(root->right);
		printf("JMP L%d\n",loclabel-1);		
		printf("L%d: ",loclabel);
		//while(evaluate(root->left))
		//	retval=evaluate(root->right);
		return 0;
	} 
	else if(strcmp(root->construct,"AND")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("MUL R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left) && evaluate(root->right);
	}
	else if(strcmp(root->construct,"OR")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("JNZ R%d, L%d\n",pre_reg,label);
		printf("JNZ R%d, L%d\n",pre_reg+1,label);
		printf("MOV R%d, %d\n",pre_reg,0);
		printf("JMP L%d\n",label+1);
		printf("L%d: MOV R%d, %d\n",label,pre_reg,1);
		printf("L%d: ",label+1);
		label+=2;
		//return evaluate(root->left) || evaluate(root->right);
	}
	else if(strcmp(root->construct,"NOT")==0)
	{
		retval=evaluate(root->left);
		printf("INR R%d\n",pre_reg);
		printf("MOV R%d, %d\n",pre_reg+1,2);
		printf("MOD R%d, R%d\n",pre_reg,pre_reg+1);
		//return !evaluate(root->left);
	}
	else if(strcmp(root->construct,">")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("GT R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)>evaluate(root->right);
	}
	else if(strcmp(root->construct,"<")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("LT R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)<evaluate(root->right);
	}
	else if(strcmp(root->construct,"==")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("EQ R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)==evaluate(root->right);
	}
	else if(strcmp(root->construct,">=")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("GE R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)>=evaluate(root->right);
	}
	else if(strcmp(root->construct,"<=")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("LE R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)<=evaluate(root->right);
	}
	else if(strcmp(root->construct,"!=")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("NE R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)!=evaluate(root->right); 
	}
	else if(strcmp(root->construct,"%NUM%")==0)
        {	
		printf("MOV R%d, %d\n",pre_reg,root->val);
		//return root->val;
	}
	else if(strcmp(root->construct,"%BOOL%")==0)
        {
		printf("MOV R%d, %d\n",pre_reg,root->val);
		//return root->val;
	}
	else if(strcmp(root->construct,"+")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("ADD R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)+evaluate(root->right);
	}
	else if(strcmp(root->construct,"*")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("MUL R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)*evaluate(root->right);
	}
	else if(strcmp(root->construct,"-")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("SUB R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)-evaluate(root->right);
	}
	else if(strcmp(root->construct,"/")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("DIV R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)/evaluate(root->right);
	}
	else if(strcmp(root->construct,"%")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		printf("MOD R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)%evaluate(root->right);
	}
	else if(strcmp(root->construct,"=")==0)
	{
		if(strcmp(root->left->construct,"%IDNODE%")==0)
		{
			printf("MOV R%d, %d\n",pre_reg,root->left->variable->binding);
			pre_reg+=1;
			retval=evaluate(root->right);
			pre_reg-=1;
			printf("MOV [R%d], R%d\n",pre_reg,pre_reg+1);
		}
		else
		{
			retval=evaluate(root->left->right);
			pre_reg+=1;
			printf("MOV R%d, %d\n",pre_reg,root->left->variable->binding);
			pre_reg-=1;
			printf("ADD R%d, R%d\n",pre_reg,pre_reg+1);
			pre_reg+=1;
			retval=evaluate(root->right);
			pre_reg-=1;
			printf("MOV [R%d], R%d\n",pre_reg,pre_reg+1);
			/*if(retval<0 || retval>=root->left->variable->size)
			{
				printf("Parsing Error: Segmentation Fault Core Dumped\n");
				exit(1);
			}
			else
				root->left->variable->binding[retval]=evaluate(root->right);
			*/
		}
		return 0;
	}
	else if(strcmp(root->construct,"%IDNODE%")==0)	
	{	
		printf("MOV R%d, %d\n",pre_reg,root->variable->binding);
		printf("MOV R%d, [R%d]\n",pre_reg,pre_reg);
		//return root->variable->binding[0];
	}
	else if(strcmp(root->construct,"%ARRNODE%")==0)
	{
		retval=evaluate(root->right);
		pre_reg+=1;
		printf("MOV R%d, %d\n",pre_reg,root->variable->binding);
		pre_reg-=1;
		printf("ADD R%d, R%d\n",pre_reg,pre_reg+1);
		printf("MOV R%d, [R%d]\n",pre_reg,pre_reg);
		/*if(retval<0 || retval>=root->variable->size)
		{
			printf("Syntax Error: Segmentation Fault Core Dumped\n");
			exit(1);
		}
		else
			return root->variable->binding[retval];
		*/
	}		
	else if(strcmp(root->construct,"%READ%")==0)
	{
		printf("IN R%d\n",pre_reg);
		printf("MOV R%d, %d\n",pre_reg+1,root->variable->binding);
		printf("MOV [R%d], R%d\n",pre_reg+1,pre_reg);
		//scanf("%d",&root->variable->binding[0]);
		return 0;
	}
	else if(strcmp(root->construct,"%READARR%")==0)
	{		
		printf("IN R%d\n",pre_reg);
		pre_reg+=1;
		retval=evaluate(root->right);
		printf("MOV R%d, %d\n",pre_reg+1,root->variable->binding);
		printf("ADD R%d, R%d\n",pre_reg,pre_reg+1);
		pre_reg-=1;
		printf("MOV [R%d], R%d\n",pre_reg+1,pre_reg);
		/*if(retval<0 || retval>=root->variable->size)
		{
			printf("Syntax Error: Segmentation Fault Core Dumped\n");
			exit(1);
		}
		else
			scanf("%d",&root->variable->binding[retval]);
		*/
		return 0;
	}
	else if(strcmp(root->construct,"%WRITE%")==0)
	{
		retval=evaluate(root->left);
		printf("OUT R%d\n",pre_reg);
		return 0;
	}
	return 0;
}	
