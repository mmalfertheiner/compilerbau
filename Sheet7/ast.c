#include "ast.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ast_t* ast_new()
{
	ast_t *ast = (ast_t*)malloc(sizeof(ast_t));

	if (!ast) {
		printf("Out of memory!");
		exit(EXIT_FAILURE);
	}
	ast->root = NULL;
	ast->currScope = ast_new_rawNode(SYM_TAB);
	ast->currScope->symTab = symtab_new();

	return ast;
}

node_ast* ast_setRoot(ast_t* ast, node_ast *root)
{
	ast->root = root;
	return root;
}

node_ast* ast_new_rawNode(node_type type)
{
	node_ast *node = (node_ast*)malloc(sizeof(node_ast));

	node->type = type;
	node->symTab = NULL;
	node->outerScope = NULL;
	node->next = NULL;
	return node;
}

node_ast* ast_getScope(const ast_t* const ast)
{
	return ast->currScope;
}

node_ast* ast_getOuterScope(const ast_t* const ast)
{
	return ast->currScope ? ast->currScope->outerScope : NULL;
}

node_ast* ast_pushScope(ast_t* const ast)
{
	node_ast *node = ast_new_rawNode(VAR_LIST);

	node->symTab = symtab_new();
	node->outerScope = ast->currScope;
	ast->currScope = node;
	return node;
}

node_ast* ast_popScope(ast_t* const ast, node_ast *declList, node_ast *stmt)
{
	node_ast *node = ast->currScope;

	node->body = declList;
	ast_addNode(declList, stmt);
	ast->currScope = ast->currScope->outerScope;		
	return node;
}

node_ast* ast_new_iNode(ast_t* ast, node_type type, int iValue)
{
	node_ast *node = ast_new_rawNode(type);

	symtab_insert(ast->currScope->symTab, ET_CONST, DT_INT, &iValue, NULL);
	return node;
}	

node_ast* ast_new_fNode(ast_t* ast, node_type type, float fValue)
{
	node_ast *node = ast_new_rawNode(type);
	
	symtab_insert(ast->currScope->symTab, ET_CONST, DT_REAL, &fValue, NULL);
	return node;
}

node_ast* ast_new_strNode(ast_t* ast, node_type type, char* str)
{
	node_ast *node = ast_new_rawNode(type);

	
	switch(type){
		case STRING_CONST:
			symtab_insert(ast->currScope->symTab, ET_CONST, DT_STRING, str, NULL);
			break;
		case IDENTIFIER:
			symtab_insert(ast->currScope->symTab, ET_DECL, DT_STRING, str, NULL);
			break;
		default:
			break;
	}
	
	
	return node;
}

node_ast* ast_new_bodyNodeN(node_type type, unsigned char n, ...)
{
	node_ast *node;
	va_list bodies;

	va_start(bodies, n);
	node = ast_new_vBodyNodeN(type, n, bodies);
	va_end(bodies);
	return node;
}

node_ast* ast_new_bodyNode(node_type type, node_ast *body)
{
	return ast_new_bodyNodeN(type, 1, body);
}


node_ast* ast_new_vBodyNodeN(node_type type, unsigned char n, va_list bodies)
{
	node_ast *node = ast_new_rawNode(type);
	node_ast *curr;
	unsigned char i;

	node->body = curr = va_arg(bodies, node_ast*);
	for (i = 1; i < n; i++) 
		curr = ast_addNode(curr, va_arg(bodies, node_ast*));
	return node;
}

node_ast* ast_addNode(node_ast *front, node_ast *newNode)
{
	if (!newNode)
		return front;
	while (front->next) 
		front = front->next;
	front->next = newNode;
	return newNode;
}

symtab_entry_t* ast_findSymInScope(node_ast* scope, entry_type_t entryType, data_type_t dataType, void *val)
{
	if (!scope)
		return NULL;

	unsigned int idx = symtab_hashToIdx(symtab_hash(entryType, dataType, val));
	symtab_entry_t *entry = symtab_findByIdx(scope->symTab, idx, entryType, dataType, val);

	return entry;
}

node_ast* ast_new_symNodeEx(ast_t* ast, node_type nodeType, symtab_entry_t *entry)
{
	node_ast *node;

	node = ast_new_rawNode(nodeType);
	node->outerScope = ast->currScope->outerScope;
	node->symbol = entry;
	return node;
}

node_ast* ast_new_symNode(ast_t* ast, entry_type_t entryType, data_type_t dataType, void *val, void *val2)
{
	return ast_new_symNodeEx(ast, SYMBOL, symtab_insert(ast->currScope->symTab, entryType, dataType, val, val2));
}