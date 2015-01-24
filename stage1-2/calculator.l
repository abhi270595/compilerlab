%{
	#include "y.tab.h"
	extern YYSTYPE yylval;
%}

digit [0-9]

%%

{digit}+      {yylval.ival = atoi(yytext); return NUM;}
[-%*+/()\n]   {return *yytext;}
.             { }

%%

