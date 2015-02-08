%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	extern YYSTYPE yylval;
%}

digit [0-9]

%%

{digit}+       	       {yylval.ival = atoi(yytext); return NUM;}
read           	       {return READ;}
write                  {return WRITE;}
if                     {return IF;}
then                   {return THEN;}
endif                  {return ENDIF;}
while                  {return WHILE;}
do                     {return DO;}
endwhile               {return ENDWHILE;}
decl                   {return DECL;}
enddecl                {return ENDDECL;}
TRUE                   {return TRUE;}
FALSE                  {return FALSE;}
boolean                {return BOOLEAN;}
integer                {return INTEGER;}
[a-zA-Z][a-zA-Z0-9]*   {yylval.var = strdup(yytext) ; return ID;}
"=="                   {return EQUAL;}
">="                   {return GE;}
"<="                   {return LE;}
"!="                   {return NE;}
[ \t\n]      	       {}
[-+*/=,<>;()\[\]%]     {return *yytext;}
.                      {printf("LEXICAL ERROR!\n"); exit(1);}

%%

