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
%token <var> EQUAL
%token <var> TRUE
%token <var> FALSE
%token <var> GE
%token <var> LE
%token <var> NE
%token <nptr>BOOLEAN
%type  <nptr>Slist
%type  <nptr>Stmt
%type  <nptr>expr
%type  <nptr>total
%type  <nptr>gdecl
%type  <nptr>decllist
%type  <nptr>idlist
%type  <nptr>decl
%type  <nptr>array
%type  <nptr>bidlist
%type  <nptr>barray

%left  ','
%right '='
%left  EQUAL NE
%left  '<' LE '>' GE
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
decl     : BOOLEAN bidlist';'                              {$$=mkDeclNode("%BOOLEAN%",$2);} 
  ;
idlist   : ID','idlist                                     {$$=mkIdlistvarNode(mkLeafNode_Id($1,"%INTEGER%"),$3,"%INTEGER%");}
  ;
bidlist  : ID','bidlist                                    {$$=mkIdlistvarNode(mkLeafNode_Id($1,"%BOOLEAN%"),$3,"%BOOLEAN%");}
  ;
idlist   : array','idlist                                  {$$=mkIdlistarrNode($1,$3,"%INTEGER%");}
  ;
bidlist  : barray','bidlist                                {$$=mkIdlistarrNode($1,$3,"%BOOLEAN%");}
  ;
idlist   : ID                                              {$$=mkLeafNode_Id($1,"%INTEGER%");}
  ;
bidlist  : ID                                              {$$=mkLeafNode_Id($1,"%BOOLEAN%");}
  ;
idlist   : array                                           {$$=$1;}
  ;
bidlist  : barray                                          {$$=$1;}
  ;
array    : ID'['NUM']'                                     {$$=mkLeafNode_Array($1,$3,"%INTEGER%");}
  ;
barray   : ID'['NUM']'                                     {$$=mkLeafNode_Array($1,$3,"%BOOLEAN%");}
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
expr     : expr EQUAL expr      			   {$$=mkBoolOptNode("==",$1,$3);}
  ;
expr     : expr GE expr      			   {$$=mkBoolOptNode(">=",$1,$3);}
  ;
expr     : expr LE expr      			   {$$=mkBoolOptNode("<=",$1,$3);}
  ;
expr     : expr NE expr      			   {$$=mkBoolOptNode("!=",$1,$3);}
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
expr     : TRUE                                    {$$=mkLeafNode_Bool("TRUE");}
  ;
expr     : FALSE                                   {$$=mkLeafNode_Bool("FALSE");}
  ;

%%

yyerror()
{printf("Syntax Error!\n"); exit(1);}

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
