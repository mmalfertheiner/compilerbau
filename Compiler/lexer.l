%{
#include <stdio.h>
#include <string.h>

void yyerror(char *s)
{
    printf("Error at line %d: %s at %s\n", yylineno, s, yytext);
}

char *toUpperCase ( char *str )
{

	char *newstr, *p;
	p = newstr = strdup(str);

	while( *p )
	{
		*p=toupper( *p );
		p++;
	}

	return newstr;
}

char *toLowerCase ( char *str )
{

	char *newstr, *p;
	p = newstr = strdup(str);

	while( *p )
	{
		*p=tolower( *p );
		p++;
	}

	return newstr;
}

%}

%option noyywrap


Comment					\{.*\}
Blanks					[ ]+
Tabs					[\t]+
NewLines				[\n]+
String					\".*\"
Integer 				[0-9]+
Identifier				[A-z][A-z0-9]*

%%

{NewLines}				{ yylineno++; printf("\n"); }
{Blanks}				{ printf(" "); }
{Tabs}					{ printf( "%s", yytext); }
[-,:;.(){}\[\]*/+<=>]	{ printf( "%s", yytext ); }
{Comment}				{ printf( "%s", yytext ); }
{String}				{ printf( "%s", yytext ); }
{Integer}				{ printf( "%s", yytext ); }


":=" 					{ printf( "%s", yytext ); }
"<="					{ printf( "%s", yytext ); }
"<>"					{ printf( "%s", yytext ); }	
"and" 					{ printf( "%s", toUpperCase(yytext)); }
"array"					{ printf( "%s", toUpperCase(yytext)); }
"begin"					{ printf( "%s", toUpperCase(yytext)); }
"div"					{ printf( "%s", toUpperCase(yytext)); }
"do"					{ printf( "%s", toUpperCase(yytext)); }
"else"					{ printf( "%s", toUpperCase(yytext)); }
"end"					{ printf( "%s", toUpperCase(yytext)); }
"false"					{ printf( "%s", toUpperCase(yytext)); }
"for"					{ printf( "%s", toUpperCase(yytext)); }
"if"					{ printf( "%s", toUpperCase(yytext)); }
"integer"				{ printf( "%s", toUpperCase(yytext)); }
"mod"					{ printf( "%s", toUpperCase(yytext)); }
"of"					{ printf( "%s", toUpperCase(yytext)); }
"program"				{ printf( "%s", toUpperCase(yytext)); }
"read"					{ printf( "%s", toUpperCase(yytext)); }
"real"					{ printf( "%s", toUpperCase(yytext)); }
"then"					{ printf( "%s", toUpperCase(yytext)); }
"to"					{ printf( "%s", toUpperCase(yytext)); }
"true"					{ printf( "%s", toUpperCase(yytext)); }
"var"					{ printf( "%s", toUpperCase(yytext)); }
"while"					{ printf( "%s", toUpperCase(yytext)); }
"write"					{ printf( "%s", toUpperCase(yytext)); }
{Identifier}			{ printf( "%s", toLowerCase(yytext)); }

.						{ yyerror(yytext); }

%%

main(int argc, char **argv) {
  yylex();
  return 0;
}

