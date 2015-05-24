#ifndef AST_PRINT_H
#define AST_PRINT_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"

/* Abstract-syntax-tree print-functions */
void ast_print(node_ast* const ast);
void ast_nice_print(node_ast* const ast);

#endif