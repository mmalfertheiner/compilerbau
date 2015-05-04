#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


typedef enum { 
	PROGRAM, ASSIGN, IF, WHILE, STATEMENT, CONST, VAR, TYPE,
	EXPR, INT_CONST, REAL_CONST, BOOL_CONST, STRING_CONST, IDENTIFIER, OP
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
} node_ast, ast;

/* Node creation/manipulation functions */
static inline node_ast* ast_new_rawNode(const node_type type)
{
	node_ast *node = (node_ast*)malloc(sizeof(node_ast));

	node->type = type;
	node->next = NULL;
	return node;
}

static inline node_ast* ast_new_iNode(const node_type type, const int iValue)
{
	node_ast *node = ast_new_rawNode(type);

	node->iValue = iValue;
	return node;
}	

static inline node_ast* ast_new_fNode(const node_type type, const float fValue)
{
	node_ast *node = ast_new_rawNode(type);

	node->fValue = fValue;
	return node;
}

static inline node_ast* ast_new_strNode(const node_type type, char* str)
{
	node_ast *node = ast_new_rawNode(type);

	node->identifier = str;
	return node;
}

node_ast* ast_new_vBodyNodeN(const node_type type, const unsigned char n, va_list bodies);

static inline node_ast* ast_new_bodyNodeN(const node_type type, unsigned char n, ...)
{
	node_ast *node;
	va_list bodies;

	va_start(bodies, n);
	node = ast_new_vBodyNodeN(type, n, bodies);
	va_end(bodies);
	return node;
}

static inline node_ast* ast_new_bodyNode(const node_type type, node_ast *body)
{
	return ast_new_bodyNodeN(type, 1, body);
}

node_ast* ast_addNode(node_ast *front, node_ast *newEnd);

#endif