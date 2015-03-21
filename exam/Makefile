slp: y.tab.c lex.yy.c
	gcc -g -o slp y.tab.c -ll

lex.yy.c : slp.l
	lex slp.l

y.tab.c : slp.y
	yacc -d -v slp.y

clean:
	$(RM) y.tab.* slp lex.yy.c
