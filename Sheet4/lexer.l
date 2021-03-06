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
	Token_epsilon, 
	Token_end,
	Token_EOF, 
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
	"Token_epsilon", 
	"Token_end", 
	"Token_EOF",
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

struct FirstFollow
{
	enum Token *First;
	enum Token *Follow;
	int size_first;
	int size_follow;
};



// define list of FirstSets and FollowSets
/*
First(start) = {PROGRAM}
Follow(Start) = {$}
*/
enum Token First_Start[] = { Token_program };
enum Token Follow_Start[] = { Token_EOF };
struct FirstFollow Start_FirstFollow = { &First_Start[0], &Follow_Start[0], 1, 1};

/*
First(VarDecList) = First(IdenListType) = { IDENT }
Follow(VarDecList) = { BEGIN }
*/
enum Token First_VarDecList[] = { Token_identifier };
enum Token Follow_VarDecList[] = { Token_begin };
struct FirstFollow VarDecList_FirstFollow = { &First_VarDecList[0], &Follow_VarDecList[0], 1, 2 };

/*
First(IdenListType) = First(IdentList) = { IDENT }
Follow(identListType) += Follow(VarDecList) = { ; , BEGIN }
*/
#define First_IdentListType First_VarDecList
enum Token Follow_IdentListType[] = { Token_semicolon, Token_begin };
struct FirstFollow IdentListType_FirstFollow = { &First_IdentListType[0], &Follow_IdentListType[0], 1, 2 };


/*
First(IdentList) = 
Follow(IdentList) = 
*/
#define First_IdentList First_VarDecList
enum Token Follow_IdentList[] = { Token_colon };
struct FirstFollow IdentList_FirstFollow = { &First_IdentList[0], &Follow_IdentList[0], 1, 0 };

/*
First(Type) = {ARRAY, INTGER, REAL, STRING}
Follow(type) = Follow(IdentListType) = { ; , BEGIN}
*/
enum Token First_Type[] = { Token_array, Token_integer, Token_real, Token_string };
enum Token Follow_Type[] = { Token_semicolon, Token_begin };
struct FirstFollow Type_FirstFollow = { &First_Type[0], &Follow_Type[0], 4, 2 };

/*
First(SimpleType)={INTE GER, REAL, STRING}
Follow(simpleType) = Follow(type) = { ; , BEGIN}
*/
enum Token First_SimpleType[] = { Token_integer, Token_real, Token_string };
enum Token Follow_SimpleType[] = { Token_semicolon, Token_begin };
struct FirstFollow SimpleType_FirstFollow = { &First_SimpleType[0], &Follow_SimpleType[0], 3, 2 };

/*
First(CompStmt) = {BEGIN}
Follow(compStmt) = Follow(statement) = { ; , END, ELSE}
*/
enum Token First_CompStmt[] = { Token_begin };
enum Token Follow_CompStmt[] = { Token_semicolon, Token_end, Token_else };
struct FirstFollow CompStmt_FirstFollow = { &First_CompStmt[0], &Follow_CompStmt[0], 1, 3 };

/*
First(StmtList) = First(Statement) = {BEGIN, READ, WRITE , IDENT, IF, WHILE, FOR}
Follow(StmtList) = {END}
*/
enum Token First_StmtList[] = { Token_begin, Token_read, Token_write, Token_identifier, Token_if, Token_while, Token_for};
enum Token Follow_StmtList[] = { Token_end };
struct FirstFollow StmtList_FirstFollow = { &First_StmtList[0], &Follow_StmtList[0], 7, 1};

/*
First(Statement) = {BEGIN, READ, WRITE , IDENT, IF, WHILE, FOR}
Follow(Statment) = { ; , END, ELSE}
*/
#define First_Statement First_StmtList
enum Token Follow_Statement[] = { Token_semicolon, Token_end, Token_else };
struct FirstFollow Statement_FirstFollow = { &First_Statement[0], &Follow_Statement[0], 7, 3};

/*
First(AssignStmt) = {IDENT}
Follow(assignStmt) = Follow(statement) = { ; , END, ELSE}
*/
enum Token First_AssignStmt[] = { Token_identifier };
enum Token Follow_AssignStmt[] = { Token_semicolon, Token_end, Token_else };
struct FirstFollow AssignStmt_FirstFollow = { &First_AssignStmt[0], &Follow_AssignStmt[0], 1, 3};

/*
First(index) = { [ }
Follow(index) += ] = { :, ] }
*/
enum Token First_Index[] = { Token_lBracket };
enum Token Follow_Index[] = { Token_colon, Token_rRectBracket };
struct FirstFollow index_FirstFollow = { &First_Index[0], &Follow_Index[0], 1, 2};

/*
First(IfStmt) = {IF}
Follow(ifStmt) = { ; , END, ELSE}
*/
enum Token First_IfStmt[] = { Token_if };
enum Token Follow_IfStmt[] = { Token_semicolon, Token_end, Token_else };
struct FirstFollow IfStmt_FirstFollow = { &First_IfStmt[0], &Follow_IfStmt[0], 1, 3};

/*
First(WhileStmt) = {WHILE}
Follow(WhileStmt) = { ; , END, ELSE}
*/
enum Token First_WhileStmt[] = { Token_while };
enum Token Follow_WhileStmt[] = { Token_semicolon, Token_end, Token_else };
struct FirstFollow WhileStmt_FirstFollow = { &First_WhileStmt[0], &Follow_WhileStmt[0], 1, 3};

/*
First(ForStmt) = {FOR}
Follow(ForStmt) = { ; , END, ELSE}
*/
enum Token First_ForStmt[] = { Token_for };
enum Token Follow_ForStmt[] = { Token_semicolon, Token_end, Token_else };
struct FirstFollow ForStmt_FirstFollow = { &First_ForStmt[0], &Follow_ForStmt[0], 1, 3};

/*
First(ToPart) = {TO, DOWNTO}
Follow(toPart) = First(expr) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
*/
enum Token First_ToPart[] = { Token_to, Token_downTo };
enum Token Follow_ToPart[] = { Token_Integer, Token_Real, Token_String, Token_true, Token_false, Token_identifier, Token_not, Token_sub, Token_lBracket };
struct FirstFollow ToPart_FirstFollow = { &First_ToPart[0], &Follow_ToPart[0], 2, 9};

/*
First(ExprList) = First(Expr) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
Follow(exprList) = { ) }
*/
enum Token First_ExprList[] = { Token_Integer, Token_Real, Token_String, Token_true, Token_false, Token_identifier, Token_not, Token_sub, Token_lBracket };
enum Token Follow_ExprList[] = { Token_rBracket };
struct FirstFollow ExprList_FirstFollow = { &First_ExprList[0], &Follow_ExprList[0], 9, 1};

/*
First(Expr) = First(SimpleExpr) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
Follow(expr) += Follow(assignStmt) = { ELSE, ; , END, THEN, DO, TO, DOWNTO, ',', ) }
*/
#define First_Expr First_ExprList
enum Token Follow_Expr[] = { Token_else, Token_semicolon, Token_end, Token_then, Token_do, Token_to, Token_downTo, Token_colon, Token_rBracket };
struct FirstFollow Expr_FirstFollow = { &First_Expr[0], &Follow_Expr[0], 9, 9};

/*
First(SimpleExpr) = First(Term) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
Follow(simpleExpr) += Follow(expr) = {ELSE, . , ], <, <=, >, >=, =, <>, ;, END, THEN, DO, TO, DOWNTO, ',', ) }
*/
#define First_SimpleExpr First_Expr
enum Token Follow_SimpleExpr[] = { Token_else, Token_dot, Token_rRectBracket, Token_less, Token_leq, Token_bigger, Token_beq, Token_eq, Token_noteq, Token_semicolon, Token_end, Token_then, Token_do, Token_to, Token_downTo, Token_colon, Token_rBracket };
struct FirstFollow SimpleExpr_FirstFollow = { &First_SimpleExpr[0], &Follow_SimpleExpr[0], 9, 17};

/*
First(Term) = First(Factor) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
Follow(term) += Follow(SimpleExpr) = {ELSE, +, -, OR, . , ], <, <=, >, >=, =, <>, ;, END, THEN, DO, TO, DOWNTO, ',', ) }
*/
#define First_Term First_SimpleExpr
enum Token Follow_Term[] = { Token_else, Token_add, Token_sub, Token_or, Token_dot, Token_rRectBracket, Token_less, Token_leq, Token_bigger, Token_beq, Token_eq, Token_noteq, Token_semicolon, Token_end, Token_then, Token_do, Token_to, Token_downTo, Token_colon, Token_rBracket };
struct FirstFollow Term_FirstFollow = { &First_Term[0], &Follow_Term[0], 9, 20};

/*
First(Factor) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
Follow(factor) += Follow(term) = {ELSE, *, /, DIV, MOD, AND, +, -, OR, . , ], <, <=, >, >=, =, <>, ;, END, THEN, DO, TO, DOWNTO, ',', ) }
*/
#define First_Factor First_Term
enum Token Follow_Factor[] = { Token_else, Token_mult, Token_divide, Token_div, Token_mod, Token_and, Token_add, Token_sub, Token_or, Token_dot, Token_rRectBracket, Token_less, Token_leq, Token_bigger, Token_beq, Token_eq, Token_noteq, Token_semicolon, Token_end, Token_then, Token_do, Token_to, Token_downTo, Token_colon, Token_rBracket };
struct FirstFollow Factor_FirstFollow = { &First_Factor[0], &Follow_Factor[0], 9, 25};

/*
First(RelOp) = {<, <=, >, >=, =, <>}
Follow(relOp) = First(simpleExpr) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
*/
enum Token First_RelOp[] = { Token_less, Token_leq, Token_bigger, Token_beq, Token_eq, Token_noteq};
#define Follow_RelOp First_SimpleExpr
struct FirstFollow RelOp_FirstFollow = { &First_RelOp[0], &Follow_RelOp[0], 6, 9};

/*
First(AddOp) = {+, -, OR}
Follow(addOp) = First(term) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
*/
enum Token First_AddOp[] = { Token_add, Token_sub, Token_or };
#define Follow_AddOp First_Term
struct FirstFollow AddOp_FirstFollow = { &First_AddOp[0], &Follow_AddOp[0], 3, 9};

/*
First(MulOp) = {*, /, DIV, MOD, AND}
Follow(mulOp) = First(factor) = { NUM, STRING, FALSE, TRUE, IDENT, NOT, -, ( }
*/
enum Token First_MulOp[] = { Token_mult, Token_div, Token_divide, Token_mod, Token_and };
#define Follow_MulOp First_Factor
struct FirstFollow MulOp_FirstFollow = { &First_MulOp[0], &Follow_MulOp[0], 5, 9};

////////////////////////// DONE WITH SETS

enum Token currentToken;
int errorMessage = 0;


void match(enum Token type){
	if (type == currentToken){
		char tmp[100];
		strcpy(tmp, yytext);
		currentToken = yylex();
		//printf("%s ------next Token------> %s\n", tmp, yytext);
	}
	else 
	{
		yyerror(TOKEN_STRING[currentToken]);
	}
}


int isElementfollower(struct FirstFollow sets, enum Token currentToken){
	int i;
	for(i=0;i<sets.size_follow;i++){
		if(sets.Follow[i]==currentToken || sets.Follow[i]==Token_epsilon){
			return 1;
		}
	}
	return 0;
}


int isElementfirst(struct FirstFollow sets, enum Token currentToken){
	int i;
	for(i=0;i<sets.size_first;i++){
		if(sets.First[i]==currentToken || sets.First[i]==Token_epsilon){
			return 1;
    	}
	}
    return 0;
}

void scanto(struct FirstFollow sets){
 	while ( !isElementfollower(sets,currentToken) && !isElementfirst(sets, currentToken) && currentToken != Token_EOF )
    { 	
    	char tmp[100];
        strcpy(tmp, yytext);
		currentToken=yylex();
		printf("Skip %s and move on to %s CurrenToken: %s \n",tmp ,yytext, TOKEN_STRING[currentToken]);
  	};
}

void checkFirstFollow(struct FirstFollow sets){
    if(!isElementfirst(sets,currentToken)){
    	printf("%s not found in FirstSet\n", yytext);
		scanto(sets);
    }
}

/*
	mulOp 			→ * | / | DIV | MOD | AND
*/
void mulOp(){
	printf("%d: addOp\n", yylineno);
	checkFirstFollow(MulOp_FirstFollow);
	match(currentToken);
}


/*
	addOp			→ + | – | OR
*/
void addOp(){
	printf("%d: addOp\n", yylineno);
	checkFirstFollow(AddOp_FirstFollow);
	match(currentToken);
}

/*
	relOp 			→ < | <= | > | >= | = | <>
*/
void relOp(){
	printf("%d: relOp\n", yylineno);
	checkFirstFollow(RelOp_FirstFollow);
	match(currentToken);
}

/*
	exprList 		→ exprList exprList'
	exprList'		→ , expr exprList'
					| ε
*/
void exprList(){
	printf("%d: exprList\n", yylineno);
	checkFirstFollow(ExprList_FirstFollow);
	expr();
	while (currentToken == Token_comma){
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
	checkFirstFollow(Expr_FirstFollow);
	simpleExpr();
	while (currentToken == Token_less || currentToken == Token_leq || currentToken == Token_bigger || currentToken == Token_beq || currentToken == Token_eq || currentToken == Token_noteq){
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
	checkFirstFollow(SimpleExpr_FirstFollow);
	term();
	while(currentToken == Token_add || currentToken == Token_sub || currentToken == Token_or){
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
	checkFirstFollow(Term_FirstFollow);
	factor();
	while(currentToken == Token_mult || currentToken == Token_divide || currentToken == Token_div || currentToken == Token_mod || currentToken == Token_and){
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
	checkFirstFollow(Factor_FirstFollow);
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
	checkFirstFollow(AssignStmt_FirstFollow);
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
	checkFirstFollow(IfStmt_FirstFollow);
	match(Token_if);
	expr();
	match(Token_then);
	statement();
	if(currentToken == Token_else){
		match(Token_else);
		statement();
	}
}

/*
	whileStmt 		→ WHILE expr DO statement
*/

void whileStmt(){
	printf("%d: whileStmt\n", yylineno);
	checkFirstFollow(WhileStmt_FirstFollow);
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
	checkFirstFollow(ForStmt_FirstFollow);
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
	checkFirstFollow(ToPart_FirstFollow);
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
	checkFirstFollow(Statement_FirstFollow);
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
	checkFirstFollow(StmtList_FirstFollow);
	statement();
	while (currentToken == Token_semicolon){
		match(Token_semicolon);
		statement();
	}
}


/*
	compStmt 		→ BEGIN stmtList END
*/
void compStmt(){
	printf("%d: compStmt\n", yylineno);
	checkFirstFollow(CompStmt_FirstFollow);
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
	checkFirstFollow(IdentList_FirstFollow);
	match(Token_identifier);
	while (currentToken == Token_comma){
		match(Token_comma);
		match(Token_identifier);
	}
}

void simpleType(){
	printf("%d: simpleType\n", yylineno);
	checkFirstFollow(SimpleType_FirstFollow);
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
	checkFirstFollow(Type_FirstFollow);
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
	checkFirstFollow(IdentListType_FirstFollow);
	identList();
	match(Token_colon);
	type();
	//printf("%d: End identListType\n", yylineno);
}


/*
	varDecList 		→ varDecList varDecList'
	varDecList'		→ identListType ; varDecList'
					|ε
*/
void varDecList(){
	printf("%d: varDecList\n", yylineno);
	checkFirstFollow(VarDecList_FirstFollow);
	identListType();
	while (currentToken == Token_semicolon){
		match(Token_semicolon);
		if (currentToken == Token_identifier)
			identListType();
	}
	
	//printf("%d: End varDecList\n", yylineno);
}

/*
	varDec 			→ VAR varDecList
					| ε
*/
void varDec(){
	printf("%d: varDec\n", yylineno);
	match(Token_var);
	varDecList();
	//printf("%d: End varDec\n", yylineno);	
}

/*
	start 			→ PROGRAM IDENT ; varDec compStmt .
*/
void start() {
	currentToken = yylex();
	checkFirstFollow(Start_FirstFollow);
	printf("%d: start\n", yylineno);
	match(Token_program);
	match(Token_identifier);
	match(Token_semicolon);
	varDec();
	compStmt();
	match(Token_dot);
	//printf("%d: End of start\n", yylineno);
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

