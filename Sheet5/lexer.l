%{
#include <stdio.h>
#include <string.h>

%}

%option noyywrap


Blanks					[ ]+
Tabs					[\t]+
NewLines				[\n]+
String					\"[^\"]*\"
Digit					[0-9]
Integer 				{Digit}+?
Real					{Digit}+.{Digit}+
Letter					[A-Za-z]
Identifier				({Letter}|_)({Letter}|[0-9])*?
OldComment				\{[^\}]*\}
OpenCom					"(*"
CloseCom				"*)"

%%

{NewLines}				{ yylineno++; }
{Blanks}				
{Tabs}							
{OldComment}			{ yylineno++; }
{String}				return Token_String;
{Integer}				return Token_Integer;
{Real}					return Token_Real;

"integer"				return Token_integer;
"real"					return Token_real;
"string"				return Token_string;
":=" 					return Token_assign;
"<="					return Token_leq;
"<>"					return Token_noteq;
">="					return Token_beq;		
"and" 					return Token_and;
"array"					return Token_array;
"begin"					return Token_begin;
"div"					return Token_div;
"do"					return Token_do;
"downto"				return Token_downTo;
"else"					return Token_else;
"end"					return Token_end;
"false"					return Token_false;
"for"					return Token_for;
"if"					return Token_if;
"repeat"				return Token_repeat;
"until"					return Token_until;
"mod"					return Token_mod;
"not"					return Token_not;
"of"					return Token_of;
"or"					return Token_or;
"program"				return Token_program;
"read"					return Token_read;
"then"					return Token_then;
"to"					return Token_to;
"true"					return Token_true;
"var"					return Token_var;
"while"					return Token_while;
"write"					return Token_write;
"+"						return Token_add;
"-"						return Token_sub;
"*"						return Token_mult;
"/"						return Token_divide;
"<"						return Token_less;
">"						return Token_bigger;
"="						return Token_eq;
","						return Token_comma;
";"						return Token_semicolon;
":"						return Token_colon;
"."						return Token_dot;
"["						return Token_lRectBracket;
"]"						return Token_rRectBracket;
"("						return Token_lBracket;
")"						return Token_rBracket;
{Identifier}			return Token_identifier;
<<EOF>> 				return Token_EOF;

.						{ yyerror(yytext); return Token_error; }

%%

void yyerror(char *s)
{
    printf("Error at line %d: %s at %s\n", yylineno, s, yytext);
}



int main(int argc, char **argv) {
	start();

  	return 0;
}

