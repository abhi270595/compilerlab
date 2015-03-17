%{
	#include <stdio.h>
	struct label_table
	{
		char *label;
		int address;
		struct label_table *next;
	};
	struct label_table *head=NULL;
	int preaddr=1535;
	int reladdr=0;
	FILE * fp;
%}

%option noyywrap

%x 	PASS1

%%

	int i;
	if (pass == 1) BEGIN (PASS1);
	if (pass == 2) BEGIN (INITIAL);

<PASS1>{

[a-zA-Z0-9]+:   { struct label_table *temp=(struct label_table *)malloc(sizeof(struct label_table));
		  temp->label=yytext;
		  temp->address=preaddr+reladdr;
		  temp->next=head;
	          head=temp;
		  return(yytext); 
		}
[\n]            { reladdr+=2; return(yytext); }
.               { return(yytext); }

}

[a-zA-Z0-9]+    { struct label_table *temp=head;
		  char *name;
		  strcpy(name,yytext);
		  strcat(name,":");
		  while(temp!=NULL)
		  {
			if(strcmp(name,temp->label)==0)
			{
				fprintf(fp,"%d",temp->address);
				break;
			}
			temp=temp->next;
		  }	
		}
.               { fprintf(fp,"%s",yytext); }
	
%%

int main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");	
	fp=fopen(argv[2],"w");
	yylex();
	return 0;
}
