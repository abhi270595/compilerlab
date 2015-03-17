// INTEGER 2
// BOOLEAN 1

#include<stdio.h>
#include<stdlib.h>

extern yylineno;
extern char filename[];
extern FILE *outFile;

struct Argstruct
{
    char *name;
    int type;
    int id_type;
    struct Argstruct *next;
};

struct Lsymbol
{
    char *name;
    int type;
    int id_type;
    int binding;
    struct Lsymbol *next;
};

struct Gsymbol
{
    char *name;
    int type;
    int size;
    char *id_type;
    int binding;
    int isdef;
    struct Argstruct *ARGLIST;
    struct Gsymbol *next;
};

struct Gsymbol *head=NULL;
struct Argstruct *ARGLIST=NULL;
struct Lsymbol *lsym=NULL;
int retvaltype;
int mem_loc_ptr=1536;
int lbind=1;

struct Gsymbol * Glookup(struct Gsymbol *pre,char *name,char *id_type)
{
    if(pre!=NULL)
    {
        if(strcmp(pre->name,name) == 0)
            return pre;
        else
            return Glookup(pre->next,name,id_type);
    }   
    else
        return NULL;
}

void Ginstall(char *name,int type,int size,char *id_type,struct Argstruct *ARGLIST)
{
    if(Glookup(head,name,id_type)==NULL)
    {
        struct Gsymbol *temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
        temp->name=name;
        temp->type=type;
        temp->size=size;
        temp->id_type=id_type;
        temp->binding=mem_loc_ptr;
	temp->isdef=0;
	temp->ARGLIST=ARGLIST;
        temp->next=head;
        head=temp;
	mem_loc_ptr+=size;
    }
    else
    {
        printf("Syntax Error:Line No-%d, Duplicating Name for Variables or Functions\n",yylineno);
	remove(filename);
        exit(1);
    }
}

struct Argstruct * Arglookup(struct Argstruct *pre,char *name)
{
    if(pre!=NULL)
    {
        if(strcmp(pre->name,name) == 0)
            return pre;
        else
            return Arglookup(pre->next,name);
    }   
    else
        return NULL;
}

void Arginstall(char *name,int type,int id_type)
{
    if(Arglookup(ARGLIST,name)==NULL)
    {
    	struct Argstruct *temp=(struct Argstruct *)malloc(sizeof(struct Argstruct));
    	temp->name=name;
    	temp->type=type;
	temp->id_type=id_type;
    	temp->next=ARGLIST;
    	ARGLIST=temp;
    }
    else
    {
	printf("Syntax Error:Line No-%d, Duplicating Name for Variables in argument list\n",yylineno);
	remove(filename);
        exit(1);
    }
}

struct Lsymbol * Llookup(struct Lsymbol *pre,char *name)
{
    if(pre!=NULL)
    {
        if(strcmp(pre->name,name) == 0)
            return pre;
        else
            return Llookup(pre->next,name);
    }   
    else
        return NULL;
}

void Linstall(char *name,int type,int binding,int id_type)
{
    if(Llookup(lsym,name)==NULL)
    {
    	struct Lsymbol *temp=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
    	temp->name=name;
    	temp->type=type;
	temp->binding=binding;
	temp->id_type=id_type;
    	temp->next=lsym;
    	lsym=temp;
    }
    else
    {
	printf("Syntax Error:Line No-%d, Duplicating Name for Variables in Local Symbol Table\n",yylineno);
	remove(filename);
        exit(1);
    }
}
