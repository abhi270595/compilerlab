%{
	#include <stdio.h>
	#include <stdlib.h>
	struct label_table
	{
		char *label;
		int address;
		struct label_table *next;
	};
	struct label_table *head=NULL;
	int preaddr=0;
	int reladdr=0;
	int pass=1;
	FILE * fp;
%}

%x 	PASS1

%option noyywrap

%%

	int i;
	if (pass == 1) BEGIN (PASS1);
	if (pass == 2) BEGIN (INITIAL);

<PASS1>{

[a-zA-Z0-9]+:    { struct label_table *temp=(struct label_table *)malloc(sizeof(struct label_table));
		   char *name;
		   name=strdup(yytext);
		   temp->label=name;
		   temp->address=preaddr+reladdr;
		   temp->next=head;
	           head=temp;
		 }
[\n]             { reladdr+=2; }	
.                { }

}

[a-zA-Z0-9]+:[ ] { }

[a-zA-Z0-9]+     { struct label_table *temp=head;
		   char *name;
		   int check=0;
		   name=strdup(yytext);
		   strcat(name,":");
		   while(temp!=NULL)
		   {
			 if(strcmp(name,temp->label)==0)
			 {
				fprintf(fp,"%d",temp->address);
				check=1;
				break;
			 }
			 temp=temp->next;
		   }	
		   if(check==0)
			 fprintf(fp,"%s",yytext);
		 }
[\n]             { fprintf(fp,"\n"); }
.                { fprintf(fp,"%s",yytext); }
	
%%

int main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");	
	fp=fopen(argv[2],"w");
	yylex();
	yyin=fopen(argv[1],"r");	
	pass=2;
	yylex();
	return 0;
}
