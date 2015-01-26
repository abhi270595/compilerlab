%{
	#include <stdio.h>
	#include "lex.yy.c"
	#include "exprtree1.h"
%}

%union
{
	int ival;
	char *var;
	struct tree_node *nptr;	
};

%token <ival>NUM
%token <var> ID
%token <nptr>READ
%token <nptr>WRITE
%token <nptr>IF
%token <nptr>THEN
%token <nptr>ENDIF
%token <nptr>WHILE
%token <nptr>DO
%token <nptr>ENDWHILE
%token <nptr>INTEGER
%token <nptr>DECL
%token <nptr>ENDDECL
%type  <nptr>Slist
%type  <nptr>Stmt
%type  <nptr>expr
%type  <nptr>total
%type  <nptr>gdecl
%type  <nptr>decllist
%type  <nptr>idlist
%type  <nptr>decl
%type  <nptr>array

%left  ','
%right '='
%left  "=="
%left  '<' '>'
%left  '+' '-'
%left  '*' '/' '%'
%left  '(' ')' '[' ']'

%%
pgm      : total           			           {evaluate($1); exit(0);}
  ;
total    : gdecl Slist                                     {$$=mkPgmNode($1,$2);}
  ;
gdecl    : DECL decllist ENDDECL                           {$$=$2;}
  ;
decllist : decl decllist                                   {$$=mkDecllistNode($1,$2);}
  ;
decllist : decl                                            {$$=$1;}
  ;
decl     : INTEGER idlist';'                               {$$=mkDeclNode("%INTEGER%",$2);}
  ;
idlist   : ID','idlist                                     {$$=mkIdlistvarNode(mkLeafNode_Id($1),$3);}
  ;
idlist   : array','idlist                                  {$$=mkIdlistarrNode($1,$3);}
  ;
idlist   : ID                                              {$$=mkLeafNode_Id($1);}
  ;
idlist   : array                                           {$$=$1;}
  ;
array    : ID'['NUM']'                                     {$$=mkLeafNode_Array($1,$3);}
  ;
Slist    : Slist Stmt          			           {$$=mkListNode($1,$2);}
  ;
Slist    : Stmt            			           {$$=$1;}
  ;
Stmt     : IF'('expr')'THEN Slist ENDIF';'                 {$$=mkCondNode("%IF%",$3,$6);}
  ;
Stmt     : WHILE'('expr')'DO Slist ENDWHILE';'             {$$=mkCondNode("%WHILE%",$3,$6);}
  ;
Stmt     : ID'='expr';'        			           {$$=mkEquNode("=",ckLeafNode_Id($1),$3);}
  ; 
Stmt     : ID'['expr']''='expr';'        	           {$$=mkEquNode("=",ckLeafNode_Arr($1,$3),$6);}
  ; 
Stmt     : READ '(' ID ')' ';'     		           {$$=mkRNode($3);}
  ;
Stmt     : READ'('ID'['expr']'')'';'     		   {$$=mkRArrNode($3,$5);}
  ;
Stmt     : WRITE'('expr')'';'  			           {$$=mkWNode($3);}
  ;
expr     : expr'<'expr         			           {$$=mkBoolOptNode("<",$1,$3);}
  ;
expr     : expr'>'expr         			           {$$=mkBoolOptNode(">",$1,$3);}
  ;
expr     : expr'=''='expr      			           {$$=mkBoolOptNode("==",$1,$4);}
  ;
expr     : expr'+'expr         		        	   {$$=mkOperatorNode("+",$1,$3);}
  ;
expr     : expr'-'expr         		        	   {$$=mkOperatorNode("-",$1,$3);}
  ;
expr     : expr'/'expr         		        	   {$$=mkOperatorNode("/",$1,$3);}
  ;
expr     : expr'%'expr         		        	   {$$=mkOperatorNode("%",$1,$3);}
  ;
expr     : expr'*'expr      			           {$$=mkOperatorNode("*",$1,$3);}
  ;
expr     : '('expr')'          			           {$$=$2;}
  ;
expr     : ID                  			           {$$=ckLeafNode_Id($1);}
  ;
expr     : ID'['expr']'                 	           {$$=ckLeafNode_Arr($1,$3);}
  ;
expr     : NUM                 			           {$$=mkLeafNode_Num($1);}
  ;
%%

yyerror()
{printf("Syntax Error!\n");}

int main(int argc,char *argv[])
{
	if(argc>=2)
	{
		yyin=fopen(argv[1],"r");
		yyparse();
		fclose(yyin);
	}
	else
		return yyparse();	
	return 0;
}
