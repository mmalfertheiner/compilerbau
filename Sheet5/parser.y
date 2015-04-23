%{ 

#include <stdio.h>

extern int yylex(void);

int yyerror (char *);

%}

%token	Token_add
%token	Token_and
%token	Token_array
%token	Token_assign
%token	Token_begin
%token	Token_beq
%token	Token_bigger
%token	Token_colon
%token	Token_comma
%token	Token_div
%token	Token_divide
%token	Token_do
%token	Token_dot
%token	Token_downTo
%token	Token_else
%token	Token_end
%token	Token_EOF
%token	Token_eq
%token	Token_error
%token	Token_false
%token	Token_for
%token	Token_identifier
%token	Token_if
%token	Token_Integer
%token	Token_integer
%token	Token_lBracket
%token	Token_leq
%token	Token_less
%token	Token_lRectBracket
%token	Token_mod
%token	Token_mult
%token	Token_not
%token	Token_noteq
%token	Token_of
%token	Token_or
%token	Token_program
%token	Token_rBracket
%token	Token_read
%token	Token_Real
%token	Token_real
%token	Token_repeat
%token	Token_rRectBracket
%token	Token_semicolon
%token	Token_String
%token	Token_string
%token	Token_sub
%token	Token_then
%token	Token_to
%token	Token_true
%token	Token_until
%token	Token_var
%token	Token_while
%token	Token_write


%start		start

%%


start			:	Token_program Token_identifier Token_semicolon varDec compStmt Token_dot
				;

varDec 			:	Token_var varDecList
				|	/* Epsilon */
				;

varDecList		:	varDecList identListType Token_semicolon
				| 	identListType Token_semicolon
				;


identListType	:	identList Token_comma type
				;


identList 		:	identList Token_colon Token_identifier 
				|	Token_identifier
				;

type 			:	simpleType
				|	Token_array Token_lRectBracket Token_integer Token_dot Token_dot Token_integer Token_lRectBracket Token_of simpleType
				;

simpleType		:	Token_Integer
				|	Token_Real
				|	Token_String
				;

compStmt		:	Token_begin stmtList Token_end
				;

stmtList		:	stmtList Token_semicolon statement
				| 	statement
				;

statement		:	assignStmt
				| 	compStmt
				| 	ifStmt
				| 	whileStmt
				| 	forStmt
				| 	Token_read Token_lBracket exprList Token_rBracket
				| 	Token_write Token_lBracket exprList Token_rBracket
				;

assignStmt		:	Token_identifier Token_assign expr
				| 	Token_identifier index Token_assign expr
				;

index			:	Token_lRectBracket expr Token_rRectBracket
				| 	Token_lRectBracket expr Token_dot Token_dot expr Token_rRectBracket
				;

ifStmt			:	Token_if expr Token_then statement elsePart
				;

elsePart		:	Token_else statement
				|	/* Epsilon */
				;

whileStmt		:	Token_while expr Token_do statement
				;

forStmt 		:	Token_for Token_identifier Token_assign expr toPart expr Token_do statement
				;

toPart			:	Token_to
				| 	Token_downTo
				;

exprList		:	exprList Token_comma expr 
				|	expr
				;

expr 			:	simpleExpr relOp simpleExpr
				|	simpleExpr
				;

simpleExpr 		|	simpleExpr addOp term
				|	term
				;

term			:	term mulOp factor
				|	factor
				;

factor 			:	Token_integer 
				| 	Token_real
				|	Token_string
				|	Token_false
				|	Token_true
				|	Token_identifier
				|	Token_identifier index 
				| 	Token_not factor 
				| 	Token_sub factor
				| 	Token_lBracket exp Token_rBracket
				;

relOp 			: 	Token_less
				| 	Token_leq
				| 	Token_bigger
				| 	Token_beq
				| 	Token_eq
				| 	Token_noteq
				;

addOp 			:	Token_add
				| 	Token_sub
				|	Token_or
				;

mulOp 			: 	Token_mult 
				|	Token_divide
				|	Token_div
				| 	Token_mod
				| 	Token_and
				;

%%

main() {
	return yyparse();
}

int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}