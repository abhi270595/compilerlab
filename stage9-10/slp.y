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

%token <ival> NUM
%token <var>  ID READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE INTEGER BOOLEAN DECL ENDDECL BEGINING END MAIN RETURN EQUAL TRUE FALSE GE LE NE AND OR NOT 
%type <nptr> Slist Stmt expr total gdefblock gdeflist gdecl type gidlist gid arglist arg argidlist argid fdeflist fdef mainblock ldefblock ldeflist ldecl lidlist lid body retstmt exprlist

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

pgm       : total           			            {evaluate($1); exit(0);}
  ;
total     : gdefblock fdeflist mainblock                    {$$=mkNode("%PGM%",$2,$3);}
  ;
gdefblock : DECL gdeflist ENDDECL                           {}
  ;
gdeflist  : gdecl gdeflist                                  {}
          |                                                 {}
  ;
gdecl     : type gidlist';'                                 {}
  ;
type      : INTEGER                                         {datatype=2;}
	  | BOOLEAN                                         {datatype=1;} 
  ;
gidlist   : gid','gidlist                                   {}
          | gid                                             {}
  ;
gid	  : ID                                              {Ginstall($1,datatype,1,"%ID%",NULL);}
	  | ID'('arglist')'                                 {Ginstall($1,datatype,1,"%FUNCTION%",ARGLIST); ARGLIST=NULL;}
          | ID'['NUM']'                                     {Ginstall($1,datatype,$3,"%ARR%",NULL);}
  ;
arglist   : arg arglist                                     {}
          |                                                 {}
  ;
arg       : type argidlist';'                               {}
  ;
argidlist : argid','argidlist                               {}
          | argid                                           {}
  ;
argid     : ID                                              {Arginstall($1,datatype);}
  ;
fdeflist  :  fdeflist fdef      		            {$$=mkNode("%FDEFLIST%",$1,$2);}
	  |                                                 {}
  ;
fdef      : type ID'('arglist')''{'ldefblock body'}'        {$$=mkFDefNode($2,datatype,ARGLIST,$8);}
  ;
mainblock : INTEGER MAIN'('')''{'ldefblock body'}'          {$$=mkFDefNode("main",2,NULL,$7);}
  ;
ldefblock : DECL ldeflist ENDDECL                           {}
  ;
ldeflist  : ldecl ldeflist                                  {}
          |                                                 {}
  ;
ldecl     : type lidlist';'                                 {}
  ;
lidlist   : lid','lidlist                                   {}
          | lid                                             {}
  ;
lid       : ID						    {Linstall($1,datatype,lbind); lbind+=1;}
  ;
body      : BEGINING Slist retstmt END                      {$$=mkNode("%BODY%",$2,$3);}
  ;
retstmt   : RETURN NUM ';'                                  {$$=mkReturnNode_Num($2);}
          | RETURN ID ';'                                   {$$=mkReturnNode_Id($2);}
  ;
Slist     : Slist Stmt          			    {$$=mkNode("%LIST%",$1,$2);}
          |                     			    {}
  ;
Stmt      : IF'('expr')'THEN Slist ENDIF';'                 {$$=mkCondNode("%IF%",$3,NULL,$6);}
  	  | IF'('expr')'THEN Slist ELSE Slist ENDIF';'      {$$=mkCondNode("%IFELSE%",$3,$6,$8);}
          | WHILE'('expr')'DO Slist ENDWHILE';'             {$$=mkCondNode("%WHILE%",$3,NULL,$6);}
          | ID'='expr';'        			    {$$=mkEquNode("=",ckLeafNode_Id($1),$3);}
          | ID'['expr']''='expr';'        	            {$$=mkEquNode("=",ckLeafNode_Arr($1,$3),$6);}
          | READ '(' ID ')' ';'     		            {$$=mkRNode($3);}
          | READ '('ID'['expr']'')'';'     		    {$$=mkRArrNode($3,$5);}
          | WRITE'('expr')'';'  			    {$$=mkWNode($3);}
  ;
exprlist  : exprlist','expr                                 {$$=mkNode("%EXPRLIST%",$1,$3);}
          |                                                 {}
  ;
expr      : expr'<'expr         			    {$$=mkBoolOptNode("<",$1,$3);}
          | expr'>'expr         			    {$$=mkBoolOptNode(">",$1,$3);}
          | expr EQUAL expr      			    {$$=mkBoolOptNode("==",$1,$3);}
          | expr GE expr      			            {$$=mkBoolOptNode(">=",$1,$3);}
          | expr LE expr      			            {$$=mkBoolOptNode("<=",$1,$3);}
          | expr NE expr      			            {$$=mkBoolOptNode("!=",$1,$3);}
	  | expr AND expr                                   {$$=mkBoolOptBoolNode("AND",$1,$3);}
	  | expr OR expr                                    {$$=mkBoolOptBoolNode("OR",$1,$3);}
          | NOT expr                                        {$$=mkBoolOptNotNode("NOT",$2);}
          | expr'+'expr         		            {$$=mkOperatorNode("+",$1,$3);}
          | expr'-'expr         		            {$$=mkOperatorNode("-",$1,$3);}
          | expr'/'expr         		            {$$=mkOperatorNode("/",$1,$3);}
          | expr'%'expr         		            {$$=mkOperatorNode("%",$1,$3);}
          | expr'*'expr      			            {$$=mkOperatorNode("*",$1,$3);}
          | '('expr')'          	       	            {$$=$2;}
          | ID                  	                    {$$=ckLeafNode_Id($1);}
	  | ID'('exprlist')'                                {$$=ckLeafNode_Function($1,$3);}
          | ID'['expr']'                 	            {$$=ckLeafNode_Arr($1,$3);}
          | NUM                 	                    {$$=mkLeafNode_Num($1);}
          | TRUE                                    	    {$$=mkLeafNode_Bool("TRUE");}
          | FALSE                                   	    {$$=mkLeafNode_Bool("FALSE");}
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