%{
#include <stdio.h>
#include <string.h>


void yyerror(char *s);

void maxNestingLevel( int nestingLevel);

char *toUpperCase ( char *str );

char *toLowerCase ( char *str );

char *substring(char *str, int position, int length);

char *toPascalComment(char *str);

int nesting = 0;
int maxNesting = 0;
int totalComments = 0;

%}

%option noyywrap

%x MODULACOMMENT

Blanks					[ ]+
Tabs					[\t]+
NewLines				[\n]+
String					\"[^\"]*\"
Digit					[0-9]
Integer 				{Digit}+
Float					{Digit}+.{Digit}*
Real 					^[+-]?(?:\d+\.?\d*|\d*\.\d+)$
Identifier				[A-z_][A-z0-9_]*
OldComment				\{[^\}]*\}
OpenCom					"(*"
CloseCom				"*)"

KeyWords				"and"|"array"|"begin"|"div"|"do"|"else"|"end"|"false"|"for"|"if"|"integer"|"repeat"|"until"|"mod"|"of"|"program"|"read"|"then"|"to"|"true"|"var"|"while"|"write"
Operations				":="|"<="|">="|"<>"

%%

{NewLines}						{ yylineno++; printf("\n"); }
{Blanks}						{ printf(" "); }
{Tabs}							{ printf( "%s", yytext); }

{OpenCom}						{ BEGIN MODULACOMMENT; nesting = 0; totalComments++; printf( "%s", yytext );}
<MODULACOMMENT>{OpenCom}		{ nesting++; totalComments++; printf( "%s", yytext );}
<MODULACOMMENT>{CloseCom}		{ 	maxNestingLevel(nesting); 
									printf( "%s", yytext ); 
									if (nesting == 0) 
									{ 
										BEGIN INITIAL; 
									} else 
									{ 
										nesting--; 
									}
								}
<MODULACOMMENT><<EOF>> 			{ 	if (nesting > 0) 
									{ 
										yyerror("Missing closing comment tag."); 
										exit(0); 
									}
								}
<MODULACOMMENT>.				{ printf( "%s", yytext ); }

{OldComment}					{ printf( "(*%s*)", toPascalComment(yytext)); }
[-,:;.(){}\[\]*/+<=>]			{ printf( "%s", yytext ); }
{String}						{ printf( "%s", yytext ); }
{Integer}						{ printf( "%s", yytext ); }
{Float}							{ printf( "%s", yytext ); }
{Real}							{ printf( "%s", yytext ); }
{Operations} 					{ printf( "%s", yytext ); }
{KeyWords} 						{ printf( "%s", toUpperCase(yytext)); }
{Identifier}					{ printf( "%s", toLowerCase(yytext)); }

.								{ yyerror(yytext); }

%%

void yyerror(char *s)
{
    printf("Error at line %d: %s at %s\n", yylineno, s, yytext);
}

void maxNestingLevel( int nestingLevel) {
	if (maxNesting <= nestingLevel) {
		maxNesting = nestingLevel;
	}
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

char *substring(char *str, int position, int length) 
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1);
 
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(str+position-1);      
      str++;   
   }
 
   *(pointer+c) = '\0';
 
   return pointer;
}

char *toPascalComment(char *str) {
	char *subs = substring(str, 2, strlen(str) - 2);
	return subs;
}

main(int argc, char **argv) {
  yylex();
  printf("\n\nTotal comments: %i\n", totalComments);
  printf("\n\nMax nesting level: %i\n", maxNesting);
  return 0;
}

