// INTEGER 2
// BOOLEAN 1

#include<stdio.h>
#include<stdlib.h>

struct Gsymbol
{
    char *name;
    int type;
    int size;
    char *id_type;
    int *binding;
    struct Gsymbol *next;
};

struct Gsymbol *head=NULL;
char keywords[11][15]={"while","do","endwhile","if","then","endif","decl","enddecl","read","write","integer"};
int keysize=11;

struct Gsymbol * Glookup(struct Gsymbol *pre,char *name,char *id_type)
{
    if(pre!=NULL)
    {
        if(strcmp(pre->name,name) == 0 && strcmp(pre->id_type,id_type) == 0)
            return pre;
        else
            return Glookup(pre->next,name,id_type);
    }   
    else
        return NULL;
}

struct Gsymbol * Ginstall(char *name,int type,int size,char *id_type)
{
    if(Glookup(head,name,id_type)==NULL)
    {
        int *arr=(int *)malloc(sizeof(int)*size);
        struct Gsymbol *temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
        temp->name=name;
        temp->type=type;
        temp->size=size;
        temp->id_type=id_type;
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
