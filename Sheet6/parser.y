%{ 

int yylex(void);

#include <stdio.h>
#include "ast.h"
#include "ast_print.h"

#define YYERROR_VERBOSE

extern int yylineno;

int yyerror (const char *s);

unsigned int errorFound = 0;
node_ast *ast = NULL;

int yydebug=1;

%}

%union {
	int iValue; 		/* integer, true, false, compOp, addOp, mulOp */
	float fValue;		/* number */		
	char *identifier;	/* string, identifier */
	struct _node *body; /* list of BNF right-hand side symbols of nonterminal type */
};


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

/*	Nonterminal types	*/
%type <iValue> 	relOp addOp mulOp
%type <body>	assignStmt compStmt elsePart expr exprList factor forStmt identList identListType ifStmt index simpleExpr simpleType start statement stmtList term toPart type varDec varDecList whileStmt



/* Expect one shift/reduce conflict */
%expect 1

//%error-verbose

%%


start			:	Token_program Token_identifier 
						Token_semicolon varDec compStmt Token_dot 		{ ast = ast_new_bodyNodeN(PROGRAM, 3, 
			 												   				ast_new_strNode(IDENTIFIER, $<identifier>2),
																	   		$4, $5);
																		}
				;

varDec 			:	Token_var varDecList								{ $$ = ast_new_bodyNode(VAR_LIST, $2); }
				|	/* Epsilon */										{ $$ = NULL; }
				;

varDecList		:	varDecList identListType Token_semicolon			{ $$ = $1;
																			ast_addNode($1, ast_new_bodyNode(VAR, $2));
																		}
				| 	identListType Token_semicolon						{ $$ = ast_new_bodyNode(VAR, $1);}
				;

identListType	:	identList Token_colon type							{ $$ = ast_new_bodyNodeN(IDENT_LIST_TYPE, 2, ast_new_bodyNode(IDENTIFIER_LIST, $1), $3); }
				;


identList 		:	identList Token_comma Token_identifier 				{ $$ = $1;
																			ast_addNode($1, ast_new_strNode(IDENTIFIER, $<identifier>3));
																		}
				|	Token_identifier									{ $$ = ast_new_strNode(IDENTIFIER, $<identifier>1); }
				;

type 			:	simpleType											{ $$ = $1; }
				|	Token_array Token_lRectBracket Token_Integer 
					Token_dot Token_dot Token_Integer 
					Token_rRectBracket Token_of simpleType				{
																			$$ = ast_new_bodyNodeN(ARRAY_TYPE, 3, ast_new_iNode(INT_CONST, $<iValue>3), ast_new_iNode(INT_CONST, $<iValue>6), $9);
					 													}
				;



simpleType		:	Token_integer										{ $$ = ast_new_strNode(TYPE, "integer"); }
				|	Token_real											{ $$ = ast_new_strNode(TYPE, "real"); }
				|	Token_string										{ $$ = ast_new_strNode(TYPE, "string"); }
				;



compStmt		:	Token_begin stmtList Token_end								{ $$ = ast_new_bodyNode(COMP_STMT, $2); }
				;



stmtList		:	stmtList Token_semicolon statement							{ $$ = $1;
																					ast_addNode($1, $3);
																				}
				| 	statement													{ $$ = $1; }
				;



statement		:	assignStmt													{ $$ = $1; }
				| 	compStmt													{ $$ = $1; }
				| 	ifStmt														{ $$ = $1; }
				| 	whileStmt													{ $$ = $1; }
				| 	forStmt														{ $$ = $1; }
				| 	Token_read Token_lBracket exprList Token_rBracket			{ $$ = ast_new_bodyNode(READ, $3); }
				| 	Token_write Token_lBracket exprList Token_rBracket			{ $$ = ast_new_bodyNode(WRITE, $3); }
				;

assignStmt		:	Token_identifier Token_assign expr 							{ $$ = ast_new_bodyNodeN(ASSIGN, 2, 
																						ast_new_strNode(IDENTIFIER, $<identifier>1), $3);
																				}
				|	Token_identifier index Token_assign expr					{ $$ = ast_new_bodyNodeN(ASSIGN, 2, 	
																				   		ast_new_bodyNodeN(ARRAY_IDENTIFIER, 2,
																				       		 ast_new_strNode(IDENTIFIER, 
																				   	   		 $<identifier>1)
																				   	   		 , $2)
																				   		, $4);
																				}
				;



index			:	Token_lRectBracket expr Token_rRectBracket								{ $$ = $2; }
				;



ifStmt			:	Token_if expr Token_then statement elsePart		{ $$ = ast_new_bodyNodeN(IF, 3, $2, $4, $5); }
				;



elsePart		:	Token_else statement						{ $$ = $2; }
				|	/* Epsilon */								{ $$ = NULL; }
				;



whileStmt		:	Token_while expr Token_do statement			{ $$ = ast_new_bodyNodeN(WHILE, 2, $2, $4); }
				;



forStmt 		:	Token_for Token_identifier Token_assign 
						expr toPart expr Token_do statement   	{ $$ = ast_new_bodyNodeN(FOR, 4,
					 												   ast_new_strNode(IDENTIFIER, $<identifier>2),
																	   $4, $6, $8); }
				;



toPart			:	Token_to								{ $$ = ast_new_strNode(CONST, "to"); }
				| 	Token_downTo							{ $$ = ast_new_strNode(CONST, "downto"); }
				;



exprList		:	exprList Token_comma expr 				{ $$ = $1;
																ast_addNode($1, $3);
															}
				|	expr 									{ $$ = $1;}
				;



expr 			:	simpleExpr relOp simpleExpr				{ $$ = ast_new_bodyNodeN(EXPR, 3, $1, 
																		ast_new_iNode(OP, $2), $3);
															}
				|	simpleExpr
				;



simpleExpr 		:	simpleExpr addOp term					{ $$ = ast_new_bodyNodeN(EXPR, 3, $1, 
																	   ast_new_iNode(OP, $2), $3);
															}
				|	term
				;



term			:	term mulOp factor						{ $$ = ast_new_bodyNodeN(EXPR, 3, $1, 
																	   ast_new_iNode(OP, $2), $3);
															}
				|	factor
				;



factor 			:	Token_Integer 							{ $$ = ast_new_iNode(INT_CONST, $<iValue>1);}
				| 	Token_Real 								{ $$ = ast_new_fNode(REAL_CONST, $<fValue>1);	}
				|	Token_String 							{ $$ = ast_new_strNode(STRING_CONST, $<identifier>1);}
				|	Token_false 							{ $$ = ast_new_iNode(BOOL_CONST, $<iValue>1);}
				|	Token_true 								{ $$ = ast_new_iNode(BOOL_CONST, $<iValue>1);}
				|	Token_identifier						{ $$ = ast_new_strNode(IDENTIFIER, $<identifier>1); }
				|	Token_identifier index  				{ $$ = ast_new_bodyNodeN(ARRAY_IDENTIFIER, 2,
																	   		ast_new_strNode(Token_identifier, $<identifier>1),
																	   		$2
																	   	);
															}
				| 	Token_not factor  						{ $$ = ast_new_bodyNode(FACTOR, $2);}
				| 	Token_sub factor 						{ $$ = ast_new_bodyNode(FACTOR, $2); }
				| 	Token_lBracket expr Token_rBracket 		{ $$ = ast_new_bodyNode(BRACKET_EXPR, $2); }
				;



relOp 			: 	Token_less			{ $$ = LT; }
				| 	Token_leq			{ $$ = LE; }
				| 	Token_bigger		{ $$ = GT; }
				| 	Token_beq			{ $$ = GE; }
				| 	Token_eq			{ $$ = EQ; }
				| 	Token_noteq			{ $$ = NE; }
				;



addOp 			:	Token_add			{ $$ = PLUS; }
				| 	Token_sub			{ $$ = MINUS; }
				|	Token_or			{ $$ = OR; }
				;



mulOp 			: 	Token_mult 			{ $$ = MUL; }
				|	Token_divide		{ $$ = DIV; }
				|	Token_div			{ $$ = DIV; }
				| 	Token_mod			{ $$ = MOD; }
				| 	Token_and			{ $$ = AND; }
				;


%%

int yyerror(const char *s) {
	errorFound = 1;
  	fprintf(stderr, "%s at line: %d\n", s, yylineno);
  	return 0;
}

int main() {
	yyparse();
	if (errorFound)
		printf("\n\nDone - Some errors occurred\n");
	else
		printf("\n\nDone - No errors\n");

	ast_nice_print(ast);
	printf("\n");

	return 0;
}