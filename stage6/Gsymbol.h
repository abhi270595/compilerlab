#include<stdio.h>
#include<stdlib.h>

struct Gsymbol
{
    char *name;
    int type;
    int size;
    int *binding;
    struct Gsymbol *next;
};

struct Gsymbol *head=NULL;
char keywords[11][15]={"while","do","endwhile","if","then","endif","decl","enddecl","read","write","integer"};
int keysize=11;

struct Gsymbol * Glookup(struct Gsymbol *pre,char *name)
{
    if(pre!=NULL)
    {
        if(pre->name==name)
            return pre;
        else
            return Glookup(pre->next,name);
    }   
    else
        return NULL;
}

struct Gsymbol * Ginstall(char *name,int type,int size)
{
    if(Glookup(head)==NULL)
    {
        int *arr=(int *)malloc(sizeof(int)*size);
        struct Gsymbol *temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
        temp->name=name;
        temp->type=type;
        temp->size=size;
        temp->binding=arr;
        temp->next=head;
        head=temp;
	return temp;
    }
    else
    {
        printf("Duplicating Name for Variables\n");
        exit(1);
    }
}
