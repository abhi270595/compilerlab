%{
	#include <stdio.h>
	#include "lex.yy.c"
	#include "exprtree1.h"
	extern yylineno;
	int datatype;
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
%token <nptr>ELSE
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
%token <var> AND
%token <var> OR
%token <var> NOT
%token <nptr>BOOLEAN
%type  <nptr>Slist
%type  <nptr>Stmt
%type  <nptr>expr
%type  <nptr>total
%type  <nptr>gdecl
%type  <nptr>decllist
%type  <nptr>idlist
%type  <nptr>decl

%left  ','
%right '='
%left  OR
%left  AND
%left  EQUAL NE
%left  '<' LE '>' GE
%left  '+' '-'
%left  '*' '/' '%'
%right NOT
%left  '(' ')' '[' ']'

%%

pgm      : total           			           {evaluate($1); exit(0);}
  ;
total    : gdecl Slist                                     {$$=mkPgmNode(NULL,$2);}
  ;
gdecl    : DECL decllist ENDDECL                           {}
  ;
decllist : decl decllist                                   {}
         |                                                 {}
  ;
decl     : type idlist';'                                  {}
  ;
type     : INTEGER                                         {datatype=2;}
	 | BOOLEAN                                         {datatype=1;} 
  ;
idlist   : ID','idlist                                     {Ginstall($1,datatype,1,"%ID%");}
         | ID'['NUM']'','idlist                            {Ginstall($1,datatype,$3,"%ARR%");}                         
         | ID                                              {Ginstall($1,datatype,1,"%ID%");}
         | ID'['NUM']'                                     {Ginstall($1,datatype,$3,"%ARR%");}
  ;
Slist    : Slist Stmt          			           {$$=mkListNode($1,$2);}
         | Stmt            			           {$$=$1;}
  ;
Stmt     : IF'('expr')'THEN Slist ENDIF';'                 {$$=mkCondNode("%IF%",$3,NULL,$6);}
  	 | IF'('expr')'THEN Slist ELSE Slist ENDIF';'      {$$=mkCondNode("%IFELSE%",$3,$6,$8);}
         | WHILE'('expr')'DO Slist ENDWHILE';'             {$$=mkCondNode("%WHILE%",$3,NULL,$6);}
         | ID'='expr';'        			           {$$=mkEquNode("=",ckLeafNode_Id($1),$3);}
         | ID'['expr']''='expr';'        	           {$$=mkEquNode("=",ckLeafNode_Arr($1,$3),$6);}
         | READ '(' ID ')' ';'     		           {$$=mkRNode($3);}
         | READ '('ID'['expr']'')'';'     		   {$$=mkRArrNode($3,$5);}
         | WRITE'('expr')'';'  			           {$$=mkWNode($3);}
  ;
expr     : expr'<'expr         			           {$$=mkBoolOptNode("<",$1,$3);}
         | expr'>'expr         			           {$$=mkBoolOptNode(">",$1,$3);}
         | expr EQUAL expr      			   {$$=mkBoolOptNode("==",$1,$3);}
         | expr GE expr      			           {$$=mkBoolOptNode(">=",$1,$3);}
         | expr LE expr      			           {$$=mkBoolOptNode("<=",$1,$3);}
         | expr NE expr      			           {$$=mkBoolOptNode("!=",$1,$3);}
	 | expr AND expr                                   {$$=mkBoolOptBoolNode("AND",$1,$3);}
	 | expr OR expr                                    {$$=mkBoolOptBoolNode("OR",$1,$3);}
         | NOT expr                                        {$$=mkBoolOptNotNode("NOT",$2);}
         | expr'+'expr         		        	   {$$=mkOperatorNode("+",$1,$3);}
         | expr'-'expr         		        	   {$$=mkOperatorNode("-",$1,$3);}
         | expr'/'expr         		        	   {$$=mkOperatorNode("/",$1,$3);}
         | expr'%'expr         		        	   {$$=mkOperatorNode("%",$1,$3);}
         | expr'*'expr      			           {$$=mkOperatorNode("*",$1,$3);}
         | '('expr')'          			           {$$=$2;}
         | ID                  			           {$$=ckLeafNode_Id($1);}
         | ID'['expr']'                 	           {$$=ckLeafNode_Arr($1,$3);}
         | NUM                 			           {$$=mkLeafNode_Num($1);}
         | TRUE                                    	   {$$=mkLeafNode_Bool("TRUE");}
         | FALSE                                   	   {$$=mkLeafNode_Bool("FALSE");}
  ;

%%

yyerror()
{printf("Syntax Error:Line No-%d, None of the Grammer rules Matched\n",yylineno); exit(1);}

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
