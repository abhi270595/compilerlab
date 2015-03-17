%{
	#include <stdio.h>
	#include "lex.yy.c"
	#include "exprtree1.h"
	extern yylineno;
	int datatype;
	FILE *outFile;
	char filename[50];
%}

%union
{
	int ival;
	char *var;
	struct tree_node *nptr;	
};

%token <ival> NUM
%token <var>  ID READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE INTEGER BOOLEAN DECL ENDDECL BEGINING END MAIN RETURN EQUAL TRUE FALSE GE LE NE AND OR NOT 
%type <nptr> Slist Stmt expr total gdefblock gdeflist gdecl type gidlist gid arglist argglist arg argidlist argid fdeflist fdef mainblock ldefblock ldeflist ldecl lidlist lid body retstmt exprlist

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

pgm       : {fprintf(outFile,"START\n");}total                       {fprintf(outFile,"hlt: MOV R0, 10\nPUSH R0\nINT 7"); exit(0);}
  ;
total     : gdefblock fdeflist mainblock                    {}
  ;
gdefblock : DECL gdeflist ENDDECL                           {fprintf(outFile,"MOV SP, %d\n",mem_loc_ptr-1); fprintf(outFile,"MOV BP, SP\n"); fprintf(outFile,"CALL main\n"); fprintf(outFile,"JMP hlt\n");}
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
	  | ID{retvaltype=datatype;}'('arglist')'           {Ginstall($1,retvaltype,0,"%FUNCTION%",ARGLIST); ARGLIST=NULL; datatype=retvaltype;}
          | ID'['NUM']'                                     {Ginstall($1,datatype,$3,"%ARR%",NULL);}
  ;
arglist   : argglist                                        {}
          |                                                 {}
  ;
argglist  : arg argglist                                    {}
          | type argidlist                                  {}
  ;
arg       : type argidlist';'                               {}
  ;
argidlist : argid','argidlist                               {}
          | argid                                           {}
  ;
argid     : ID                                              {Arginstall($1,datatype,1);}
	  | '&'ID                                           {Arginstall($2,datatype,0);}
  ;
fdeflist  :  fdeflist fdef      		            {}
	  |                                                 {}
  ;
fdef      : type{retvaltype=datatype;}ID'('arglist')'{insertlocal($3,ARGLIST);}'{'ldefblock body'}'        {evaluate(mkFDefNode($3,retvaltype,ARGLIST,$10)); lsym=NULL; ARGLIST=NULL; datatype=retvaltype;}
  ;
mainblock : INTEGER{retvaltype=2;}MAIN'('')''{'ldefblock body'}'                 {evaluate(mkFDefNode("main",2,NULL,$8)); lsym=NULL; ARGLIST=NULL; datatype=2;}
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
lid       : ID						    {Linstall($1,datatype,lbind,1); lbind+=1;}
  ;
body      : BEGINING Slist retstmt END                      {$$=mkNode("%BODY%",$2,$3);}
  ;
retstmt   : RETURN expr ';'                                 {$$=mkReturnNode($2);}
  ;
Slist     : Slist Stmt          			    {$$=mkNode("%LIST%",$1,$2);}
          | Stmt                    			    {$$=$1;}
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
          | expr                                            {$$=mkNode("%EXPRLIST%",NULL,$1);}
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
{
	printf("Syntax Error:Line No-%d, None of the Grammer rules Matched\n",yylineno); 
	remove(filename);
	exit(1);
}

int main(int argc,char *argv[])
{
	if(argc>=2)
	{
		yyin=fopen(argv[1],"r");
		outFile=fopen(argv[2],"w");
		strcpy(filename,argv[2]);
		yyparse();
		fclose(yyin);
	}
	else
		return yyparse();	
	return 0;
}
