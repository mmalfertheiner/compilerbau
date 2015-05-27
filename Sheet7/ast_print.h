#ifndef AST_PRINT_H
#define AST_PRINT_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"

/* Abstract-syntax-tree print-functions */
void ast_print(const ast_t* const ast);
void ast_printSymTab(symtab_tab_t* symTab, unsigned char indent);

#endif