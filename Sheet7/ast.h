#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "sym_tab.h"


typedef enum { 
	PROGRAM, ASSIGN, READ, WRITE, IF, WHILE, FOR, COMP_STMT, STATEMENT, CONST, VAR, TYPE,
	EXPR, INT_CONST, REAL_CONST, FACTOR, BOOL_CONST, STRING_CONST, ARRAY_IDENTIFIER, ARRAY_TYPE,
	IDENTIFIER, OP, VAR_LIST, IDENTIFIER_LIST, IDENT_LIST_TYPE, STATEMENT_LIST, EXPR_LIST, BRACKET_EXPR, SYMBOL, SYM_TAB
	} node_type;

typedef enum { 
	PLUS, MINUS, MUL, DIV, MOD, LT, LE, GT, GE, EQ, NE, AND, OR
	} operator_t;

typedef struct _node {
	node_type type;
	symtab_tab_t *symTab;			/* symbol table for let statements */
	union {
		operator_t op;
		symtab_entry_t *symbol;
		struct _node *body; 		/* list of BNF right-hand side symbols of nonterminal type */
	};
	struct _node *next;				/* decl-list, stmt-list */
} node_ast;

typedef struct _ast {
	node_ast *root;
	node_ast *currScope;
} ast_t;

ast_t* ast_new();

node_ast* ast_setRoot(ast_t* ast, node_ast *root);

/* Node creation/manipulation functions */
node_ast* ast_new_rawNode(node_type type);

node_ast* ast_new_iNode(ast_t* ast, node_type type, int iValue);

node_ast* ast_new_fNode(ast_t* ast, node_type type, float fValue);

node_ast* ast_new_strNode(ast_t* ast, node_type type, char* str);

node_ast* ast_new_identListType(ast_t* ast, node_type type, node_ast *identifierList, data_type_t listType);

node_ast* ast_new_vBodyNodeN(node_type type, unsigned char n, va_list bodies);

node_ast* ast_new_bodyNodeN(node_type type, unsigned char n, ...);

node_ast* ast_new_bodyNode(node_type type, node_ast *body);

node_ast* ast_addNode(node_ast *front, node_ast *newEnd);

node_ast* ast_new_symNodeEx(ast_t* ast, node_type nodeType, symtab_entry_t *entry);

node_ast* ast_new_symNode(ast_t* ast, entry_type_t entryType, data_type_t dataType, void *val, void *val2);

#endif