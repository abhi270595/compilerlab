slp: y.tab.c lex.yy.c
	gcc -o slp y.tab.c -ll

lex.yy.c : slp.l
	lex slp.l

y.tab.c : slp.y
	yacc -d slp.y
