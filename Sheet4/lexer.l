%{
#include <stdio.h>
#include <string.h>
#include "sets.h"

void yyerror(char* s);
void compStmt();
void expr();
void simpleExpr();
void statement();
void whileStmt();
void ifStmt();
void forStmt();
void toPart();
void elsePart();
void term();
void factor();
void addOp();
void mulOp();
void arrayIndex();


enum Token {
	Token_add, 
	Token_and, 
	Token_array,
	Token_assign, 
	Token_begin,
	Token_beq, 
	Token_bigger, 
	Token_colon, 
	Token_comma, 
	Token_div, 
	Token_divide, 
	Token_do, 
	Token_dot,
	Token_downTo, 
	Token_else, 
	Token_end, 
	Token_eq, 
	Token_error,
	Token_false, 
	Token_for,
	Token_identifier, 
	Token_if, 
	Token_Integer,
	Token_integer, 
	Token_lBracket, 
	Token_leq, 
	Token_less, 
	Token_lRectBracket, 
	Token_mod, 
	Token_mult,
	Token_not, 
	Token_noteq, 
	Token_of,
	Token_or, 
	Token_program, 
	Token_rBracket,
	Token_read, 
	Token_Real, 
	Token_real, 
	Token_repeat, 
	Token_rRectBracket, 
	Token_semicolon, 
	Token_String, 
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
	"Token_beq", 
	"Token_bigger", 
	"Token_colon", 
	"Token_comma", 
	"Token_div", 
	"Token_divide", 
	"Token_do", 
	"Token_dot",
	"Token_downTo", 
	"Token_else", 
	"Token_end", 
	"Token_eq", 
	"Token_error",
	"Token_false", 
	"Token_for",
	"Token_identifier", 
	"Token_if", 
	"Token_Integer", 
	"Token_integer", 
	"Token_lBracket", 
	"Token_leq", 
	"Token_less", 
	"Token_lRectBracket", 
	"Token_mod", 
	"Token_mult", 
	"Token_noteq",
	"Token_not",
	"Token_of",
	"Token_or", 
	"Token_program", 
	"Token_rBracket",
	"Token_read", 
	"Token_Real",
	"Token_real", 
	"Token_repeat", 
	"Token_rRectBracket", 
	"Token_semicolon",
	"Token_String",
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
		printf("%s ------next Token------> %s\n", tmp, yytext);
	} 
	else 
	{
		if (errorMessage == 0)
			yyerror(TOKEN_STRING[type]);
	}

}

/*
	mulOp 			→ * | / | DIV | MOD | AND
*/
void mulOp(){
	printf("%d: addOp\n", yylineno);
	match(currentToken);
}


/*
	addOp			→ + | – | OR
*/
void addOp(){
	printf("%d: addOp\n", yylineno);
	match(currentToken);
}

/*
	relOp 			→ < | <= | > | >= | = | <>
*/
void relOp(){
	printf("%d: relOp\n", yylineno);
	match(currentToken);
}

/*
	exprList 		→ exprList exprList'
	exprList'		→ , expr exprList'
					| ε
*/
void exprList(){
	printf("%d: exprList\n", yylineno);
	expr();
	while (errorMessage == 0 && currentToken == Token_comma){
		match(Token_comma);
		expr();
	}
}

/*
	expr 			→ simpleExpr expr'
	expr'			→ relOp simpleExpr expr' 
					| ε
*/
void expr(){
	printf("%d: expr\n", yylineno);
	simpleExpr();
	while (errorMessage == 0 && (currentToken == Token_less || currentToken == Token_leq || currentToken == Token_bigger || currentToken == Token_beq || currentToken == Token_eq || currentToken == Token_noteq)){
		relOp();
		simpleExpr();
	}
}

/*
simpleExpr 		→ term simpleExpr'
simpleExpr' 	→ addOp term simpleExpr'
				| ε
*/
void simpleExpr(){
	printf("%d: simpleExpr\n", yylineno);
	term();
	while(errorMessage == 0 && (currentToken == Token_add || currentToken == Token_sub || currentToken == Token_or)){
		addOp();
		term();
	}
}

/*
	term 			→ factor term'
	term'			→ mulOp factor term'
					| ε
*/
void term(){
	printf("%d: term\n", yylineno);
	factor();
	while(errorMessage == 0 && (currentToken == Token_mult || currentToken == Token_divide || currentToken == Token_div || currentToken == Token_mod || currentToken == Token_and)){
		mulOp();
		factor();
	}
}

/*
	factor 		→ NUM
				| STRING
				| FALSE
				| TRUE
				| IDENT factor'
				| NOT factor
				| – factor
				| ( exp )
	factor'		→ index
				| ε
*/
void factor(){
	printf("%d: factor\n", yylineno);
	switch(currentToken){
		case Token_Integer:
			match(Token_Integer);
			break;
		case Token_Real:
			match(Token_Real);
			break;
		case Token_String:
			match(Token_String);
			break;
		case Token_false:
			match(Token_false);
			break;
		case Token_true:
			match(Token_true);
			break;
		case Token_identifier:
			match(Token_identifier);
			if(currentToken == Token_lRectBracket) {
				printf("%s\n\n\n", "In here");
				arrayIndex();
			}
			break;
		case Token_not:
			match(Token_not);
			factor();
			break;
		case Token_sub:
			match(Token_sub);
			factor();
			break;
		case Token_lBracket:
			match(Token_lBracket);
			expr();
			match(Token_rBracket);
			break;
		default:
			yyerror(TOKEN_STRING[currentToken]);
	}
}

/*
index 			→ [ simpleExpr index'
index'			→ ]
				| .. simpleExpr ]
*/
void arrayIndex(){
	printf("%d: index\n", yylineno);
	match(Token_lRectBracket);
	simpleExpr();
	if(currentToken == Token_dot){
		match(Token_dot);
		match(Token_dot);
		simpleExpr();
	}
	match(Token_rRectBracket);
	
}

/*
	assignStmt 		→ IDENT assignStmt'
	assignStmt'		→ := expr
					| index := expr
*/
void assignStmt(){
	printf("%d: assignStmt\n", yylineno);
	match(Token_identifier);
	if(currentToken == Token_lRectBracket){
		arrayIndex();
	}
	match(Token_assign);
	expr();
}


/*
	ifStmt 			→ IF expr THEN statement elsePart
	elsePart 		→ ELSE statement
					| ε
*/
void ifStmt(){
	printf("%d: ifStmt\n", yylineno);
	match(Token_if);
	expr();
	match(Token_then);
	statement();
	if(currentToken == Token_else){
		elsePart();
	}
}

void elsePart(){
	printf("%d: elsePart\n", yylineno);
	match(Token_else);
	statement();
}

/*
	whileStmt 		→ WHILE expr DO statement
*/

void whileStmt(){
	printf("%d: whileStmt\n", yylineno);
	match(Token_while);
	expr();
	match(Token_do);
	statement();
}

/*
	forStmt 		→ FOR IDENT := expr toPart expr DO statement
	toPart 			→ TO | DOWNTO
*/

void forStmt(){
	printf("%d: forStmt\n", yylineno);
	match(Token_for);
	match(Token_identifier);
	match(Token_assign);
	expr();
	toPart();
	expr();
	match(Token_do);
	statement();
}

void toPart(){
	printf("%d: forStmt\n", yylineno);
	switch(currentToken){
		case Token_to:
			match(Token_to);
			break;
		case Token_downTo:
			match(Token_downTo);
			break;
		default:
			yyerror(TOKEN_STRING[currentToken]);
	}
}

/*
	statement 		→ assignStmt
					| compStmt
					| ifStmt
					| whileStmt
					| forStmt
					| READ ( exprList )
                    | WRITE ( exprList )
*/
void statement(){
	printf("%d: statement\n", yylineno);
	switch(currentToken){
		case Token_identifier:
			assignStmt();
			break;
		case Token_begin:
			compStmt();
			break;
		case Token_if:
			ifStmt();
			break;
		case Token_while:
			whileStmt();
			break;
		case Token_for:
			forStmt();
			break;
		case Token_read:
			match(Token_read);
			match(Token_lBracket);
			exprList();
			match(Token_rBracket);
			break;
		case Token_write:
			match(Token_write);
			match(Token_lBracket);
			exprList();
			match(Token_rBracket);
			break;
		default:
			yyerror(TOKEN_STRING[currentToken]);
	}
}

/*
	stmtList 		→ stmtList stmtList'
	stmtList'		→ ; statement stmtList'
					| ε
*/
void stmtList(){
	printf("%d: stmtList\n", yylineno);
	statement();
	while (errorMessage == 0 && currentToken == Token_semicolon){
		match(Token_semicolon);
		statement();
	}
}


/*
	compStmt 		→ BEGIN stmtList END
*/
void compStmt(){
	printf("%d: compStmt\n", yylineno);
	match(Token_begin);
	stmtList();
	match(Token_end);
}

/*
	identList 		→ identList , IDENT
					| IDENT
*/
void identList(){
	printf("%d: identList\n", yylineno);
	match(Token_identifier);
	while (errorMessage == 0 && currentToken == Token_comma){
		match(Token_comma);
		match(Token_identifier);
	}
}

void simpleType(){
	printf("%d: simpleType\n", yylineno);
	switch(currentToken){
		case Token_real:
			match(Token_real);
			break;
		case Token_integer:
			match(Token_integer);
			break;
		case Token_string:
			match(Token_string);
			break;
		default:
			yyerror(TOKEN_STRING[currentToken]);
	}
}

/*
	type 			→ simpleType
				| ARRAY [ NUM .. NUM ] OF simpleType
*/
void type(){
	printf("%d: type\n", yylineno);
	switch(currentToken){
		case Token_array:
			match(Token_array);
			match(Token_lRectBracket);
			match(Token_Integer);
			match(Token_dot);
			match(Token_dot);
			match(Token_Integer);
			match(Token_rRectBracket);
			match(Token_of);
			simpleType();
			break;
		default:
			simpleType();
	}
}

/*
	identListType 	→ identList : type	
*/
void identListType(){
	printf("%d: identListType\n", yylineno);
	identList();
	match(Token_colon);
	type();
	printf("%d: End identListType\n", yylineno);
}


/*
	varDecList 		→ varDecList varDecList'
	varDecList'		→ identListType ; varDecList'
					|ε
*/
void varDecList(){
	printf("%d: varDecList\n", yylineno);
	identListType();
	while (errorMessage == 0 && currentToken == Token_semicolon){
		match(Token_semicolon);
		if (currentToken == Token_identifier)
			identListType();
	}
	
	printf("%d: End varDecList\n", yylineno);
}

/*
	varDec 			→ VAR varDecList
					| ε
*/
void varDec(){
	printf("%d: varDec\n", yylineno);
	match(Token_var);
	varDecList();
	printf("%d: End varDec\n", yylineno);	
}

/*
	start 			→ PROGRAM IDENT ; varDec compStmt .
*/
void start() {
	currentToken = yylex();

	printf("%d: start\n", yylineno);
	match(Token_program);
	match(Token_identifier);
	match(Token_semicolon);
	varDec();
	compStmt();
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


.					{ yyerror(yytext); return Token_error; }

%%

void yyerror(char *s)
{
    printf("Error at line %d: %s at %s\n", yylineno, s, yytext);
    errorMessage = 1;
}



int main(int argc, char **argv) {
	start();

  	return 0;
}

