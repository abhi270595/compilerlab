%{
	#include <stdio.h>
	#include "exprtree.h"
	#include "lex.yy.c"
%}

%union
{
	int ival;
	struct tree_node *nptr;	
};

%token <ival>NUM
%type  <nptr>expr

%left '+' '-'
%left '*' '/' '%'
%left '(' ')' 

%%
pgm : expr'\n'     {preorder($1); printf("%d\n",evaluate($1)); exit(0);}
  ;
expr : expr'+'expr {$$=mkOperatorNode('+',$1,$3);}
  ;
expr : expr'-'expr {$$=mkOperatorNode('-',$1,$3);}
  ;
expr : expr'%'expr {$$=mkOperatorNode('%',$1,$3);}
  ;
expr : expr'*'expr {$$=mkOperatorNode('*',$1,$3);}
  ;
expr : expr'/'expr {$$=mkOperatorNode('/',$1,$3);}
  ;
expr : '('expr')'  {$$=$2;}
  ;
expr : NUM         {$$=mkLeafNode($1);}
  ;
%%

yyerror()
{printf("ERROR!\n");}

int main(void)
{
	return yyparse();
}
