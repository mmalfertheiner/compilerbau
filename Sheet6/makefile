all: parser

parser: lex.yy.c y.tab.c
	gcc -g -O0 lex.yy.c parser.tab.c -o parser ast.c

lex.yy.c: y.tab.c lexer.l
	lex lexer.l

y.tab.c: parser.y
	bison -d --debug --verbose parser.y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser
	rm -rf parser.dSYM
