%{
#include <stdio.h>

void yyerror(char *s)
{
      printf("%d: %s at %s\n", yylineno, s, yytext);
}

%}

%option noyywrap
whitespace		[ \t]+

%%

[-,;.()\[\]{}*/+<=>]	{ printf( "%s", yytext ); }

":=" 			{ printf( "%s", yytext ); }
"<="			{ printf( "%s", yytext ); }
"<>"			{ printf( "%s", yytext ); }	
"and" 			{ printf( "%s", yytext ); }
"array"			{ printf( "%s", yytext ); }
"begin"			{ printf( "%s", yytext ); }
"div"			{ printf( "%s", yytext ); }
"do"			{ printf( "%s", yytext ); }
"else"			{ printf( "%s", yytext ); }
"end"			{ printf( "%s", yytext ); }
"false"			{ printf( "%s", yytext ); }
"for"			{ printf( "%s", yytext ); }
"if"			{ printf( "%s", yytext ); }
"integer"		{ printf( "%s", yytext ); }
"mod"			{ printf( "%s", yytext ); }
"of"			{ printf( "%s", yytext ); }
"program"		{ printf( "%s", yytext ); }
"read"			{ printf( "%s", yytext ); }
"real"			{ printf( "%s", yytext ); }
"then"			{ printf( "%s", yytext ); }
"to"			{ printf( "%s", yytext ); }
"true"			{ printf( "%s", yytext ); }
"var"			{ printf( "%s", yytext ); }
"while"			{ printf( "%s", "WHILE" ); }
"write"			{ printf( "%s", yytext ); }

.				{ yyerror(yytext); }

%%

main(int argc, char **argv) {
  yylex();
  return 0;
}

