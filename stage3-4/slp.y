%{
	#include <stdio.h>
	#include "lex.yy.c"
	#include "exprtree1.h"
%}

%union
{
	int ival;
	char var;
	struct tree_node *nptr;	
};

%token <ival>NUM
%token <var>ID
%token <nptr>READ
%token <nptr>WRITE
%token <nptr>IF
%token <nptr>THEN
%token <nptr>ENDIF
%token <nptr>WHILE
%token <nptr>DO
%token <nptr>ENDWHILE
%type  <nptr>Slist
%type  <nptr>Stmt
%type  <nptr>expr

%right '='
%left  "=="
%left  '<' '>'
%left  '+' '-'
%left  '*' '/' '%'
%left  '(' ')' 

%%
pgm   : Slist'\n'           			        {evaluate($1); exit(0);}
  ;
Slist : Slist Stmt          			        {$$=mkListNode($1,$2);}
  ;
Slist : Stmt                			        {$$=$1;}
  ;
Stmt  : IF'('expr')'THEN Slist ENDIF';'         {$$=mkCondNode("IF",$3,$6);}
  ;
Stmt  : WHILE'('expr')'DO Slist ENDWHILE';'     {$$=mkCondNode("WHILE",$3,$6);}
  ;
Stmt  : ID'='expr';'        			        {$$=mkEquNode('=',$1,$3);}
  ; 
Stmt  : READ'('ID')'';'     			        {$$=mkRNode($3);}
  ;
Stmt  : WRITE'('expr')'';'  			        {$$=mkWNode($3);}
  ;
expr  : expr'<'expr         			        {$$=mkBoolOptNode("<",$1,$3);}
  ;
expr  : expr'>'expr         			        {$$=mkBoolOptNode(">",$1,$3);}
  ;
expr  : expr'=''='expr      			        {$$=mkBoolOptNode("==",$1,$4);}
  ;
expr  : expr'+'expr         		        	{$$=mkOperatorNode('+',$1,$3);}
  ;
expr  : expr'*'expr      			            {$$=mkOperatorNode('*',$1,$3);}
  ;
expr  : '('expr')'          			        {$$=$2;}
  ;
expr  : ID                  			        {$$=mkLeafNode_Id($1);}
  ;
expr  : NUM                 			        {$$=mkLeafNode_Num($1);}
  ;
%%

yyerror()
{printf("Syntax Error!\n");}

int main(void)
{
	return yyparse();
}
