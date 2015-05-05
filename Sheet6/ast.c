#include "ast.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

node_ast* ast_new_vBodyNodeN(const node_type type, const unsigned char n, va_list bodies)
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