#include <stdio.h>
#include <stdlib.h>
#include "Gsymbol.h"

extern yylineno;
extern char filename[];
extern FILE *outFile;

int symbol[26];

struct tree_node
{
	int val;
    	int type;
	struct Gsymbol *variable;
	char *func_name;
	char *construct;
	struct tree_node *left;
	struct tree_node *middle;
	struct tree_node *right;
	struct Lsymbol *lsymbol;
	struct Argstruct *ARGLIST;
};

int pre_reg=0;
int label=1;

void insertlocal(char *name,struct Argstruct *ARGLIST)
{
	struct Gsymbol *tmp=Glookup(head,name);
	if(tmp->isdef!=0)
	{
		printf("Syntax Error:Line No-%d, Function %s is already defined\n",yylineno,name);
		remove(filename);
       		exit(1);
	}
	tmp->isdef=1;
	struct Argstruct *prev=NULL,*current=ARGLIST,*next,*temp1;
	while(current!=NULL)	
	{
		next  = current->next;  
        	current->next = prev;   
       	 	prev = current;
        	current = next;
	}
	temp1=prev;
	int binding=-3;
	if (tmp->type == 3) binding = -4;
	while(temp1!=NULL)
	{
		Linstall(temp1->name,temp1->type,binding,temp1->id_type);
		binding-=1;
		temp1=temp1->next;
	}
}

struct tree_node * mkFDefNode(char *name,int type,struct Argstruct *ARGLIST,struct tree_node *right)
{
	struct Gsymbol *tmp=Glookup(head,name);
	struct Argstruct *temp,*temp1;
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	if(tmp!=NULL)
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
			remove(filename);
       			exit(1);
		}	
		root->construct="%FUNCTION%";
        	root->type=type;
		root->lsymbol=lsym;
		root->variable=tmp;
		root->func_name=tmp->name;
		root->ARGLIST=ARGLIST;
		root->left=NULL;
		root->middle=NULL;
		root->right=right;
		lbind=1;
		return root;
        }
	else if(strcmp(name,"main")==0)
	{
		root->construct="%FUNCTION%";
        	root->type=type;
		root->lsymbol=lsym;
		root->variable=NULL;
		root->func_name=name;
		root->ARGLIST=NULL;
		root->left=NULL;
		root->middle=NULL;
		root->right=right;
		lbind=1;
		return root;
	}
	else
	{
		printf("Syntax Error:Line No-%d, Function %s is not defined\n",yylineno,name);
		remove(filename);
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
		remove(filename);
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
		remove(filename);
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
		remove(filename);
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
		remove(filename);
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
		remove(filename);
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
	root->val=-1;
    	if(root->left->type!=root->right->type)
    	{
        	printf("Syntax Error:Line No-%d, An Boolean Variable Cannot be assigned to an Arithmetic Expression\n",yylineno);
		remove(filename);
        	exit(1);
    	}
    	root->type=0;
	return root;
}

struct tree_node * mkEquPairNode(char *opt,struct tree_node *left,int middle,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct=opt;
	root->left=left;
	//printf("%d\n",middle);
	if(middle!=1 && middle!=2)
	{
		printf("Syntax Error:Line No-%d, Indexing of a Pair can only be 1 or 2\n",yylineno);
		remove(filename);
        	exit(1);
	}
	root->val=middle;
	//printf("Middle-%d\n", middle);
	root->right=right;
    	if(root->right->type!=2)
    	{
        	printf("Syntax Error:Line No-%d, An Integer Variable Cannot be assigned to an Arithmetic Expression\n",yylineno);
		remove(filename);
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

struct tree_node * ckLeafNode_Pair(struct tree_node *left,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%PAIR%";
	root->left=left;
	root->right=right;
	root->type=3;
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
	struct Gsymbol *temp=Glookup(head,var);	
	struct Lsymbol *temp1=Llookup(lsym,var);
	root->lsymbol=NULL;
	root->variable=NULL;
	if(temp1==NULL && temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		remove(filename);
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
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Array %s was undeclared\n",yylineno,var);
		remove(filename);
		exit(1);
	}
    	if(right->type!=2)
    	{
        	printf("Syntax Error:Line No-%d, Array index cannot be of Another Type except Integer\n",yylineno);
		remove(filename);
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
	struct Gsymbol *temp=Glookup(head,var);	
	struct Lsymbol *temp1=Llookup(lsym,var);
	root->lsymbol=NULL;
	root->variable=NULL;	
	if(temp1==NULL && temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		remove(filename);
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
	struct Gsymbol *temp=Glookup(head,var);	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Array %s was undeclared\n",yylineno,var);
		remove(filename);
		exit(1);
	}
    	if(right->type!=2)
    	{
        	printf("Syntax Error:Line No-%d, Array index cannot be of Another Type except Integer\n",yylineno);
		remove(filename);
    		exit(1);
   	}
	root->variable=temp;
    	root->type=root->variable->type;
	root->left=NULL;
	root->right=right;
	return root;
}

struct tree_node * ckLeafNode_Pair_Val(char *var,int num)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%PAIRVAL%";
	struct Gsymbol *temp=Glookup(head,var);	
	struct Lsymbol *temp1=Llookup(lsym,var);
	root->lsymbol=NULL;
	root->variable=NULL;
	//printf("%d\n",num);
	if(num!=1 && num!=2)
	{
		printf("Syntax Error:Line No-%d, Indexing of a Pair can only be 1 or 2\n",yylineno);
		remove(filename);
        	exit(1);
	}
	root->val=num;
	root->func_name=var;	
	if(temp1==NULL && temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Variable %s was undeclared\n",yylineno,var);
		remove(filename);
		exit(1);
	}
	else if(temp1!=NULL)
		root->lsymbol=temp1;
	else
		root->variable=temp;
    	root->type=2;
	root->left=NULL;
	root->right=NULL;
	return root;
}

struct tree_node * ckLeafNode_Function(char *var,struct tree_node *right)
{
	struct tree_node *root=(struct tree_node *)malloc(sizeof(struct tree_node));
	root->construct="%FUNCTIONCALL%";
	struct Gsymbol *temp=Glookup(head,var);
	struct tree_node *temp1=right;
	struct Argstruct *temp2=temp->ARGLIST;	
	if(temp==NULL)
	{
		printf("Syntax Error:Line No-%d, Function %s was undeclared\n",yylineno,var);
		remove(filename);
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
		remove(filename);
		exit(1);
	}
	root->variable=temp;
	root->ARGLIST=root->variable->ARGLIST;
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
		remove(filename);
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
	if(root==NULL)
		return 0;
	else if(strcmp(root->construct,"%FUNCTION%")==0)
	{
		//printf("%d\n",pre_reg);
		lsym=root->lsymbol;
		pre_reg = 0;
		fprintf(outFile,"%s: ",root->func_name);
		fprintf(outFile,"PUSH BP\n");
		fprintf(outFile,"MOV BP, SP\n");
		lsym=root->lsymbol;
		while(lsym!=NULL)
		{
			if(lsym->type==3)	
				fprintf(outFile,"PUSH R0\n");
			fprintf(outFile,"PUSH R0\n");
			lsym=lsym->next;
		} 
		lsym=root->lsymbol;
		//printf("%d\n",pre_reg);
		retval=evaluate(root->right);
		//printf("%d\n",pre_reg);
		return 0;
	}
	else if(strcmp(root->construct,"%FUNCTIONCALL%")==0)
	{
		retval=0;
		while(retval<pre_reg)
		{
			fprintf(outFile,"PUSH R%d\n",retval);
			retval+=1;
		}
		struct Argstruct *temp=root->ARGLIST;
		struct tree_node *temp1=root->right;
		while(temp!=NULL && temp1!=NULL)
		{
			if(temp->id_type==0 && (temp1->right->lsymbol==NULL || temp1->right->lsymbol->id_type==1))
			{
				if(strcmp(temp1->right->construct,"%IDNODE%")==0)
				{
					if(temp1->right->lsymbol!=NULL)
					{
						fprintf(outFile,"MOV R%d, BP\n",pre_reg);
						fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,temp1->right->lsymbol->binding);
						fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
						if(temp1->right->type==3)
						{
							pre_reg+=1;
							fprintf(outFile,"MOV R%d, R%d\n",pre_reg,pre_reg-1);
							fprintf(outFile,"INR R%d\n",pre_reg);
						}
					}
					else	
					{
						fprintf(outFile,"MOV R%d, %d\n",pre_reg,temp1->right->variable->binding);
						if(temp1->right->type==3)
						{
							pre_reg+=1;
							fprintf(outFile,"MOV R%d, R%d\n",pre_reg,pre_reg-1);
							fprintf(outFile,"INR R%d\n",pre_reg);
						}
					}
				}
				else if(strcmp(temp1->right->construct,"%ARRNODE%")==0)
				{
					retval=evaluate(temp1->right->right);
					pre_reg+=1;
					fprintf(outFile,"MOV R%d, %d\n",pre_reg,temp1->right->variable->binding);
					pre_reg-=1;
					fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
				}	
			}
			else if(temp->id_type==0 && temp1->right->lsymbol->id_type==0)
			{
				if(strcmp(temp1->right->construct,"%IDNODE%")==0)
				{
					if(temp1->right->lsymbol!=NULL)
					{
						fprintf(outFile,"MOV R%d, BP\n",pre_reg);
						fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,temp1->right->lsymbol->binding);
						fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
						if(temp1->right->type==3)
						{
							fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg+1,pre_reg);
							fprintf(outFile,"MOV R%d, %d\n",pre_reg+2,1);
							fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+2);
							fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
							pre_reg+=1;
						}
						else
							fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
					}
				}	
			}
			else
				retval=evaluate(temp1->right);
			fprintf(outFile,"PUSH R%d\n",pre_reg);
			if(temp1->right!=NULL && temp1->right->type==3)
			{
				pre_reg-=1;
				fprintf(outFile,"PUSH R%d\n",pre_reg);
			}
			temp1=temp1->left;
			temp=temp->next;
		}
		if(root->type==3)
			fprintf(outFile,"PUSH R0\n");
		fprintf(outFile,"PUSH R0\n");
		//printf("%d\n",pre_reg);
		fprintf(outFile,"CALL %s\n",root->variable->name);
		fprintf(outFile,"POP R%d\n",pre_reg);
		if(root->type==3)
		{
			pre_reg+=1;
			fprintf(outFile,"POP R%d\n",pre_reg);
			retval=pre_reg-2;
		}
		else
			retval=pre_reg-1;
		ARGLIST=root->ARGLIST;
		while(ARGLIST!=NULL)
		{
			//printf("%d\n",pre_reg);
			fprintf(outFile,"POP R%d\n",pre_reg+1);
			if(ARGLIST->type==3)
			{
				fprintf(outFile,"POP R%d\n",pre_reg+1);
				//printf("%d\n",pre_reg);
			}
			ARGLIST=ARGLIST->next;
		}
		while(retval>=0)
		{
			fprintf(outFile,"POP R%d\n",retval);
			retval-=1;
		}
		//printf("%d\n",pre_reg);
		return 0;
	}
	else if(strcmp(root->construct,"%PAIRVAL%")==0)
	{
		if(root->lsymbol!=NULL)
		{
			fprintf(outFile,"MOV R%d, BP\n",pre_reg);
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->lsymbol->binding);
			fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->val-1);
			if(root->lsymbol->binding<0)
				fprintf(outFile,"SUB R%d, R%d\n",pre_reg,pre_reg+1);
			else
				fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
			fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
		}
		else
		{
			fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->variable->binding);
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->val-1);
			if(root->variable->binding<0)
				fprintf(outFile,"SUB R%d, R%d\n",pre_reg,pre_reg+1);
			else
				fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
			fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
		}
		return 0;
	}
	else if(strcmp(root->construct,"%RET%")==0)
	{
		retval=evaluate(root->right);
		fprintf(outFile,"MOV R%d, BP\n",pre_reg+1);
		fprintf(outFile,"MOV R%d, %d\n",pre_reg+2,-2);
		fprintf(outFile,"ADD R%d, R%d\n",pre_reg+1,pre_reg+2);
		fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+1,pre_reg);
		if(root->type==3)
		{
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+2,-1);
			fprintf(outFile,"ADD R%d, R%d\n",pre_reg+1,pre_reg+2);
			fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+1,pre_reg-1);
		}
		while(lsym!=NULL)
		{
			fprintf(outFile,"POP R%d\n",pre_reg+1);
			if(lsym->type==3)
				fprintf(outFile,"POP R%d\n",pre_reg+1);
			lsym=lsym->next;
		}
		fprintf(outFile,"POP BP\n");
		fprintf(outFile,"RET\n");
		return 0;
	}
	else if(strcmp(root->construct,"%BODY%")==0)
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
		fprintf(outFile,"JZ R%d, L%d\n",pre_reg,label);
		loclabel=label;
		label+=1;
		retval=evaluate(root->right);		
		fprintf(outFile,"L%d: ",loclabel);
		//if(evaluate(root->left))
		//	retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%IFELSE%")==0)
	{
		retval=evaluate(root->left);
		fprintf(outFile,"JZ R%d, L%d\n",pre_reg,label);
		loclabel=label;
		label+=1;
		retval=evaluate(root->middle);
		fprintf(outFile,"JMP L%d\n",label);
		loclabel1=label;
		label+=1;
		fprintf(outFile,"L%d: ",loclabel);		
		retval=evaluate(root->right);		
		fprintf(outFile,"L%d: ",loclabel1);
		//if(evaluate(root->left))
		//	retval=evaluate(root->right);
		return 0;
	}
	else if(strcmp(root->construct,"%WHILE%")==0)
	{
		fprintf(outFile,"L%d: ",label);
		retval=evaluate(root->left);
		fprintf(outFile,"JZ R%d, L%d\n",pre_reg,label+1);
		loclabel=label+1;
		label+=2;
		retval=evaluate(root->right);
		fprintf(outFile,"JMP L%d\n",loclabel-1);		
		fprintf(outFile,"L%d: ",loclabel);
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
		fprintf(outFile,"MUL R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left) && evaluate(root->right);
	}
	else if(strcmp(root->construct,"OR")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"JNZ R%d, L%d\n",pre_reg,label);
		fprintf(outFile,"JNZ R%d, L%d\n",pre_reg+1,label);
		fprintf(outFile,"MOV R%d, %d\n",pre_reg,0);
		fprintf(outFile,"JMP L%d\n",label+1);
		fprintf(outFile,"L%d: MOV R%d, %d\n",label,pre_reg,1);
		fprintf(outFile,"L%d: ",label+1);
		label+=2;
		//return evaluate(root->left) || evaluate(root->right);
	}
	else if(strcmp(root->construct,"NOT")==0)
	{
		retval=evaluate(root->left);
		fprintf(outFile,"INR R%d\n",pre_reg);
		fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,2);
		fprintf(outFile,"MOD R%d, R%d\n",pre_reg,pre_reg+1);
		//return !evaluate(root->left);
	}
	else if(strcmp(root->construct,">")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"GT R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)>evaluate(root->right);
	}
	else if(strcmp(root->construct,"<")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"LT R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)<evaluate(root->right);
	}
	else if(strcmp(root->construct,"==")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"EQ R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)==evaluate(root->right);
	}
	else if(strcmp(root->construct,">=")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"GE R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)>=evaluate(root->right);
	}
	else if(strcmp(root->construct,"<=")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"LE R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)<=evaluate(root->right);
	}
	else if(strcmp(root->construct,"!=")==0)
	{
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"NE R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)!=evaluate(root->right); 
	}
	else if(strcmp(root->construct,"%NUM%")==0)
        {	
		fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->val);
		//return root->val;
	}
	else if(strcmp(root->construct,"%BOOL%")==0)
        {
		fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->val);
		//return root->val;
	}
	else if(strcmp(root->construct,"+")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)+evaluate(root->right);
	}
	else if(strcmp(root->construct,"*")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"MUL R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)*evaluate(root->right);
	}
	else if(strcmp(root->construct,"-")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"SUB R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)-evaluate(root->right);
	}
	else if(strcmp(root->construct,"/")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"DIV R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)/evaluate(root->right);
	}
	else if(strcmp(root->construct,"%")==0)
        {
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
		pre_reg-=1;
		fprintf(outFile,"MOD R%d, R%d\n",pre_reg,pre_reg+1);
		//return evaluate(root->left)%evaluate(root->right);
	}
	else if(strcmp(root->construct,"=")==0)
	{
		//fprintf(outFile,"glol\n");	
		//printf("%s-%d\n",root->left->construct,root->val);
		if(strcmp(root->left->construct,"%IDNODE%")==0 && root->val==-1)
		{
			//fprintf(outFile,"lol\n");
			if(root->left->lsymbol!=NULL)
			{
				fprintf(outFile,"MOV R%d, BP\n",pre_reg);
				fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->left->lsymbol->binding);
				fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
				if(root->left->lsymbol->id_type==0)
					fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
				if(root->left->type==3)
				{
					pre_reg+=1;
					fprintf(outFile,"MOV R%d, R%d\n",pre_reg,pre_reg-1);
					fprintf(outFile,"INR R%d\n",pre_reg);
				}
			}
			else
			{
				fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->left->variable->binding);
				if(root->left->type==3)
				{
					pre_reg+=1;
					fprintf(outFile,"MOV R%d, R%d\n",pre_reg,pre_reg-1);
					fprintf(outFile,"INR R%d\n",pre_reg);
				}
			}
			//fprintf(outFile,"lol\n");
			pre_reg+=1;
			retval=evaluate(root->right);
			pre_reg-=1;
			//fprintf(outFile,"loll\n");
			if(root->right->type==3)
			{
				fprintf(outFile,"MOV [R%d], R%d\n",pre_reg-1,pre_reg);
				fprintf(outFile,"MOV [R%d], R%d\n",pre_reg-2,pre_reg+1);	
			}
			else
				fprintf(outFile,"MOV [R%d], R%d\n",pre_reg,pre_reg+1);
			if(root->left->type==3)
				pre_reg-=2;
		}
		else if(strcmp(root->left->construct,"%IDNODE%")==0 && root->val!=-1)
		{
			//fprintf(outFile,"lol2\n");
			if(root->left->lsymbol!=NULL)
			{
				fprintf(outFile,"MOV R%d, BP\n",pre_reg);
				fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->left->lsymbol->binding);
				fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
				if(root->left->lsymbol->id_type==0)
					fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
				if(root->left->type==3)
				{
					fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->val-1);
					//printf("LOL-%d\n",root->val);
					fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
				}
			}
			else
			{
				fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->left->variable->binding);
				if(root->left->type==3)
				{
					fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->val-1);
					//printf("LOL2-%d\n",root->val);
					fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
				}
			}
			//fprintf(outFile,"lol\n");
			pre_reg+=1;
			retval=evaluate(root->right);
			pre_reg-=1;	
			fprintf(outFile,"MOV [R%d], R%d\n",pre_reg,pre_reg+1);
		}	
		else
		{
			//fprintf(outFile,"lol2\n");
			retval=evaluate(root->left->right);
			pre_reg+=1;
			fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->left->variable->binding);
			pre_reg-=1;
			fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
			pre_reg+=1;
			retval=evaluate(root->right);
			pre_reg-=1;
			fprintf(outFile,"MOV [R%d], R%d\n",pre_reg,pre_reg+1);
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
		//fprintf(outFile,"lol\n");	
		if(root->lsymbol!=NULL)
		{
			fprintf(outFile,"MOV R%d, BP\n",pre_reg);
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->lsymbol->binding);
			fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
			if(root->type==3)
			{
				pre_reg+=1;
				fprintf(outFile,"MOV R%d, R%d\n",pre_reg,pre_reg-1);
				fprintf(outFile,"INR R%d\n",pre_reg);	
			}
			if(root->lsymbol->id_type==0)
			{
				fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
				if(root->type==3)
					fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg-1,pre_reg-1);
			}
		}
		else
		{
			fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->variable->binding);
			if(root->type==3)
			{
				pre_reg+=1;
				fprintf(outFile,"MOV R%d, R%d\n",pre_reg,pre_reg-1);
				fprintf(outFile,"INR R%d\n",pre_reg);
			}
		}
		//printf("MOV R%d, %d\n",pre_reg,root->variable->binding);
		fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
		if(root->type==3)
		{
			fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg-1,pre_reg-1);
		}
		//return root->variable->binding[0];
	}
	else if(strcmp(root->construct,"%PAIR%")==0)	
	{	
		retval=evaluate(root->left);
		pre_reg+=1;
		retval=evaluate(root->right);
/*
		if(root->lsymbol!=NULL)
		{
			fprintf(outFile,"MOV R%d, BP\n",pre_reg+1);
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+2,root->lsymbol->binding);
			fprintf(outFile,"ADD R%d, R%d\n",pre_reg+1,pre_reg+2);
			if(root->lsymbol->id_type==0)
				fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg+1,pre_reg+1);
		}
		else
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->variable->binding);
		//printf("MOV R%d, %d\n",pre_reg,root->variable->binding);
		fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+1,pre_reg);
		fprintf(outFile,"INR R%d\n",pre_reg+1);
		fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+1,pre_reg-1);
		//return root->variable->binding[0];
*/
	}
	else if(strcmp(root->construct,"%ARRNODE%")==0)
	{
		retval=evaluate(root->right);
		pre_reg+=1;
		fprintf(outFile,"MOV R%d, %d\n",pre_reg,root->variable->binding);
		pre_reg-=1;
		fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
		fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg,pre_reg);
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
		fprintf(outFile,"IN R%d\n",pre_reg);
		if((root->variable!=NULL && root->variable->type==3) || (root->lsymbol!=NULL && root->lsymbol->type==3))
		{
			pre_reg+=1;
			fprintf(outFile,"IN R%d\n",pre_reg);
		}
		if(root->lsymbol!=NULL)
		{	
			fprintf(outFile,"MOV R%d, BP\n",pre_reg+1);
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+2,root->lsymbol->binding);
			fprintf(outFile,"ADD R%d, R%d\n",pre_reg+1,pre_reg+2);
			if(root->lsymbol->type==3)
			{
				fprintf(outFile,"MOV R%d, R%d\n",pre_reg+2,pre_reg+1);
				fprintf(outFile,"INR R%d\n",pre_reg+2);
			}
			if(root->lsymbol->id_type==0)
			{
				fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg+1,pre_reg+1);
				if(root->lsymbol->type==3)
					fprintf(outFile,"MOV R%d, [R%d]\n",pre_reg+2,pre_reg+2);
			}
		}
		else
		{
			fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->variable->binding);
			if((root->variable!=NULL && root->variable->type==3) || (root->lsymbol!=NULL && root->lsymbol->type==3))
			{
				fprintf(outFile,"MOV R%d, R%d\n",pre_reg+2,pre_reg+1);
				fprintf(outFile,"INR R%d\n",pre_reg+2);
				//fprintf(outFile,"OUT R%d\n",pre_reg+1);
				//fprintf(outFile,"OUT R%d\n",pre_reg+2);
			}
		}
		//printf("MOV R%d, %d\n",pre_reg+1,root->variable->binding);
		fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+1,pre_reg);
		if((root->variable!=NULL && root->variable->type==3) || (root->lsymbol!=NULL && root->lsymbol->type==3))
		{
			pre_reg-=1;
			fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+3,pre_reg);
			fprintf(outFile,"OUT R%d\n",pre_reg+2);
			fprintf(outFile,"OUT R%d\n",pre_reg+3);
		}
		//scanf("%d",&root->variable->binding[0]);
		return 0;
	}
	else if(strcmp(root->construct,"%READARR%")==0)
	{		
		fprintf(outFile,"IN R%d\n",pre_reg);
		pre_reg+=1;
		retval=evaluate(root->right);
		fprintf(outFile,"MOV R%d, %d\n",pre_reg+1,root->variable->binding);
		fprintf(outFile,"ADD R%d, R%d\n",pre_reg,pre_reg+1);
		pre_reg-=1;
		fprintf(outFile,"MOV [R%d], R%d\n",pre_reg+1,pre_reg);
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
		fprintf(outFile,"OUT R%d\n",pre_reg);
		if(root->left->type==3)
		{
			pre_reg-=1;
			fprintf(outFile,"OUT R%d\n",pre_reg);
		}
		return 0;
	}
	return 0;
}	
