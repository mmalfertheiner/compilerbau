%{
#include <stdio.h>
#include <string.h>

void yyerror(char* s);


enum Token {
	Token_add, 
	Token_and, 
	Token_array,
	Token_assign, 
	Token_begin, 
	Token_bigger, 
	Token_colon, 
	Token_comma, 
	Token_div, 
	Token_divide, 
	Token_do, 
	Token_dot, 
	Token_else, 
	Token_end, 
	Token_eq, 
	Token_error,
	Token_false, 
	Token_for,
	Token_identifier, 
	Token_if, 
	Token_integer, 
	Token_lBracket, 
	Token_leq, 
	Token_less, 
	Token_lRectBracket, 
	Token_mod, 
	Token_mult, 
	Token_noteq, 
	Token_of, 
	Token_program, 
	Token_rBracket,
	Token_read, 
	Token_real, 
	Token_repeat, 
	Token_rRectBracket, 
	Token_semicolon, 
	Token_string, 
	Token_sub, 
	Token_then, 
	Token_to, 
	Token_true, 
	Token_until, 
	Token_var, 
	Token_while, 
	Token_write, 
};

static char *TOKEN_STRING[] = {
	"Token_add", 
	"Token_and", 
	"Token_array",
	"Token_assign", 
	"Token_begin", 
	"Token_bigger", 
	"Token_colon", 
	"Token_comma", 
	"Token_div", 
	"Token_divide", 
	"Token_do", 
	"Token_dot", 
	"Token_else", 
	"Token_end", 
	"Token_eq", 
	"Token_error",
	"Token_false", 
	"Token_for",
	"Token_identifier", 
	"Token_if", 
	"Token_integer", 
	"Token_lBracket", 
	"Token_leq", 
	"Token_less", 
	"Token_lRectBracket", 
	"Token_mod", 
	"Token_mult", 
	"Token_noteq", 
	"Token_of", 
	"Token_program", 
	"Token_rBracket",
	"Token_read", 
	"Token_real", 
	"Token_repeat", 
	"Token_rRectBracket", 
	"Token_semicolon", 
	"Token_string", 
	"Token_sub", 
	"Token_then", 
	"Token_to", 
	"Token_true", 
	"Token_until", 
	"Token_var", 
	"Token_while", 
	"Token_write",
};

enum Token currentToken;
int errorMessage = 0;


void match(enum Token type){
	if (type == currentToken){
		char tmp[100];
		strcpy(tmp, yytext);
		currentToken = yylex();
		printf("%s--->%s\n", tmp, yytext);
	} 
	else 
	{
		if (errorMessage == 0)
			yyerror(TOKEN_STRING[type]);
	}

}


void varDec(){
	printf("%d: varDec\n", yylineno);
	match(Token_var);
}

/*
	start 			→ PROGRAM IDENT ; varDec compStmt .
*/
void start() {
	currentToken = yylex();

	printf("%d: start\n", yylineno);
	printf("%s\n", TOKEN_STRING[currentToken]);
	match(Token_program);
	match(Token_identifier);
	match(Token_semicolon);
	varDec();
	//compStmt();Token_program
	match(Token_dot);
	printf("%d: End of start\n", yylineno);
}

%}

%option noyywrap


Blanks					[ ]+
Tabs					[\t]+
NewLines				[\n]+
String					\"[^\"]*\"
Digit					[0-9]
Integer 				{Digit}+
Real					{Digit}+.{Digit}+
Identifier				[A-z_][A-z0-9_]*
OldComment				\{[^\}]*\}
OpenCom					"(*"
CloseCom				"*)"

%%

{NewLines}				{ yylineno++; }
{Blanks}				
{Tabs}							
{OldComment}				
{String}				return Token_string;
{Integer}				return Token_integer;

":=" 					return Token_assign;
"<="					return Token_leq;
"<>"					return Token_noteq;	
"and" 					return Token_and;
"array"					return Token_array;
"begin"					return Token_begin;
"div"					return Token_div;
"do"					return Token_do;
"else"					return Token_else;
"end"					return Token_end;
"false"					return Token_false;
"for"					return Token_for;
"if"					return Token_if;
"repeat"				return Token_repeat;
"until"					return Token_until;
"mod"					return Token_mod;
"of"					return Token_of;
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

.					{ yyerror(yytext); return Token_error; }

%%

void yyerror(char *s)
{
    printf("Error at line %d: %s at %s\n", yylineno, s, yytext);
    errorMessage = 1;
}



main(int argc, char **argv) {
	start();

  	return 0;
}

