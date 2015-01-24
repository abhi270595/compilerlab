%option noyywrap

number [0-9]+
op [-|+|*|/|^|=]

%%

{number}            {printf(" number");}
{op}                {printf(" option");}
.                   {printf(" error");}

%%

int main()
{
	yylex();
	return 1;
}
