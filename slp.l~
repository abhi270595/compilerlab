%{
	#include <stdio.h>
	#include "y.tab.h"
	extern YYSTYPE yylval;
%}

digit [0-9]
ID    [a-z]

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
{ID}                   {yylval.var = *yytext ; return ID;}
[();><=*+\n]           {return *yytext;}
.                      { }

%%

