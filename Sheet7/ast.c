#include "ast.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

node_ast* ast_new_rawNode(node_type type)
{
	node_ast *node = (node_ast*)malloc(sizeof(node_ast));

	node->type = type;
	node->next = NULL;
	return node;
}

node_ast* ast_new_iNode(node_type type, int iValue)
{
	node_ast *node = ast_new_rawNode(type);

	node->iValue = iValue;
	return node;
}	

node_ast* ast_new_fNode(node_type type, float fValue)
{
	node_ast *node = ast_new_rawNode(type);

	node->fValue = fValue;
	return node;
}

node_ast* ast_new_strNode(node_type type, char* str)
{
	node_ast *node = ast_new_rawNode(type);

	node->identifier = str;
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
	while (front->next) 
		front = front->next;
	front->next = newNode;
	return newNode;
}