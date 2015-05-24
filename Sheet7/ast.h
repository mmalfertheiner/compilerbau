#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


typedef enum { 
	PROGRAM, ASSIGN, READ, WRITE, IF, WHILE, FOR, COMP_STMT, STATEMENT, CONST, VAR, TYPE,
	EXPR, INT_CONST, REAL_CONST, FACTOR, BOOL_CONST, STRING_CONST, ARRAY_IDENTIFIER, ARRAY_TYPE,
	IDENTIFIER, OP, VAR_LIST, IDENTIFIER_LIST, IDENT_LIST_TYPE, STATEMENT_LIST, EXPR_LIST, BRACKET_EXPR
	} node_type;

typedef enum { 
	PLUS, MINUS, MUL, DIV, MOD, LT, LE, GT, GE, EQ, NE, AND, OR
	} operator;

typedef struct _node {
	node_type type;
	union {
		int iValue; 		/* integer, true, false, compOp, addOp, mulOp */
		float fValue;		/* number */		
		char *identifier;	/* string, identifier */
		struct _node *body; /* list of BNF right-hand side symbols of nonterminal type */
	};
	struct _node *next;		/* decl-list, stmt-list */
} node_ast;

/* Node creation/manipulation functions */
node_ast* ast_new_rawNode(node_type type);

node_ast* ast_new_iNode(node_type type, int iValue);

node_ast* ast_new_fNode(node_type type, float fValue);

node_ast* ast_new_strNode(node_type type, char* str);

node_ast* ast_new_vBodyNodeN(node_type type, unsigned char n, va_list bodies);

node_ast* ast_new_bodyNodeN(node_type type, unsigned char n, ...);

node_ast* ast_new_bodyNode(node_type type, node_ast *body);

node_ast* ast_addNode(node_ast *front, node_ast *newEnd);

#endif