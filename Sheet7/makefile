all: parser

parser: lex.yy.c y.tab.c
	gcc -g -O0 lex.yy.c parser.tab.c ast.c ast_print.c sym_tab.c -o parser -ll

lex.yy.c: y.tab.c lexer.l
	lex -o lex.yy.c lexer.l

y.tab.c: parser.y
	bison -d parser.y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h parser
	rm -rf parser.dSYM
