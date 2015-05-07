#include "ast_print.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOOL unsigned char
#define TRUE 1
#define FALSE 0
#define MAX_INDENT 50

//#define PRINT_NODE_TYPES

#ifdef PRINT_NODE_TYPES
#define ast_nice_printNodeType(ntStr) printf("%s{", ast_indentToStr(indent)); ast_printNodeType(node); printf("}")
#define ast_nice_printNodeTypeEx(ntStr) printf("{"); ast_printNodeType(node); printf("}")
#else
#define ast_nice_printNodeType(ntStr) printf("%s", ast_indentToStr(indent))
#define ast_nice_printNodeTypeEx(ntStr) 
#endif


void ast_nice_printNode(node_t* const node, const unsigned char indent);
void ast_nice_printNextNode(node_t* const node);
void ast_tree_printNode(node_t* const node, const unsigned char indent);
void ast_tree_printNextNode(node_t* const node);

unsigned int nodeCnt = 0;


char* ast_indentToStr(const unsigned char indent)
{
    static char indentStr[MAX_INDENT];
    size_t len = (indent > MAX_INDENT - 1 ? MAX_INDENT - 1 : indent);
    unsigned char i;

    for (i = 0; i < len; i++)
        indentStr[i] = ' ';
    indentStr[len] = '\0';
    return indentStr;
}

static inline char ast_strLast(const char *str)
{
    size_t len = strlen(str);

    return len > 0 ? str[len - 1] : '\0';
}

void ast_printNodeType(node_t* const node)
{
    switch (node->type) {
        case NT_LET:
            printf("NT_LET");
            break;
        case NT_ASSIGN:
            printf("NT_ASSIGN");
            break;
        case NT_IF:
            printf("NT_IF");
            break;
        case NT_WHILE:
            printf("NT_WHILE");
            break;
        case NT_FOR:
            printf("NT_FOR");
            break;
        case NT_STATEMENT:
            printf("NT_STATEMENT");
            break;
        case NT_CONST:
            printf("NT_CONST");
            break;
        case NT_VAR:
            printf("NT_VAR");
            break;
        case NT_TYPE:
            printf("NT_TYPE");
            break;
        case NT_EXPR:
            printf("NT_EXPR");
            break;
        case NT_INT_CONST:
            printf("NT_INT_CONST");
            break;
        case NT_REAL_CONST:
            printf("NT_REAL_CONST");
            break;
        case NT_BOOL_CONST:
            printf("NT_BOOL_CONST");
            break;
        case NT_STRING_CONST:
            printf("NT_STRING_CONST");
            break;
        case NT_IDENTIFIER:
            printf("NT_IDENTIFIER");
            break;
        case NT_ARRAY_IDENTIFIER:
            printf("NT_ARRAY_IDENTIFIER");
            break;
        case NT_OP:
            printf("NT_OP");
            break;
        case NT_READ:
            printf("NT_READ");
            break;
        case NT_WRITE:
            printf("NT_WRITE");
            break;
        case NT_DECL_LIST:
            printf("NT_DECL_LIST");
            break;
        default:
            printf("Unknown node type \"%d\"", node->type);
    }
    
}

void ast_nice_printBody(node_t* const node, const unsigned char indent, const char *delim, 
    const BOOL skipLastDelim)
{
    if (!node)
        printf("%s[Warning {%s}: Node is NULL!]", ast_indentToStr(indent), __FUNCTION__);
    else {
        node_t *curr = node->body;

        while (curr) {
            ast_nice_printNode(curr, indent);
            curr = curr->next;
            if (curr || !skipLastDelim)
                printf("%s%s", delim, ast_strLast(delim) == '\n' ? ast_indentToStr(indent) : "");
        }
    }
}

void ast_nice_printBodyEx(node_t* const node, const unsigned char indent, const char *delims, 
    const unsigned char delimLen)
{
    if (!node)
        printf("%s[Warning {%s}: Node is NULL!]", ast_indentToStr(indent), __FUNCTION__);
    else {
        node_t *curr = node->body;
        unsigned char delimPos = 0;

        while (curr) {
            ast_nice_printNode(curr, indent);
            curr = curr->next;
            if (curr && delimPos < strlen(delims)) {
                printf("%*s", delimLen, &delims[delimPos]);
                delimPos += delimLen;
            }
        }
    }
}

void ast_nice_printLetNode(node_t* const node, const unsigned char indent)
{
    char *newIndent[50];

    ast_nice_printNodeType();
    printf("\n%sLET ", ast_indentToStr(indent));
    ast_nice_printNodeTypeEx();
    ast_nice_printBody(node->body, 0, "; ", TRUE);
    printf(" IN BEGIN\n");
    ast_nice_printNode(node->body ? node->body->next : NULL, indent + 3);
    printf("%sEND;\n", ast_indentToStr(indent));
} 

static inline void ast_nice_printAssignNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    ast_nice_printBodyEx(node, 0, " := ", 4);
    printf(";\n");
} 

void ast_nice_printIfNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("IF (");
    ast_nice_printNode(node->body, 0);
    printf(") THEN BEGIN\n");
    ast_nice_printNode(node->body ? node->body->next : NULL, indent + 3);
    if (node->body && node->body->next && node->body->next->next) {
        printf("%sEND\n%sELSE BEGIN\n", ast_indentToStr(indent), ast_indentToStr(indent));
        ast_nice_printNode(node->body->next->next, indent + 3);
        printf("%sEND;\n", ast_indentToStr(indent));
    }
    else
        printf("%sEND;\n", ast_indentToStr(indent));
} 

void ast_nice_printWhileNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("WHILE (");
    ast_nice_printNode(node->body, 0);
    printf(") DO BEGIN\n");
    ast_nice_printNode(node->body ? node->body->next : NULL, indent + 3);
    printf("%sEND;\n", ast_indentToStr(indent));
} 

void ast_nice_printForNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("FOR ");
    ast_nice_printNode(node->body, 0);
    printf(" := ");
    ast_nice_printNode(node->body ? node->body->next : NULL, 0);
    printf(" TO ");
    ast_nice_printNode(node->body && node->body->next ? node->body->next->next : NULL, 0);
    printf(" DO BEGIN\n");
    ast_nice_printNode(node->body && node->body->next && node->body->next->next ? 
        node->body->next->next->next : NULL, indent + 3);
    printf("%sEND;\n", ast_indentToStr(indent));
} 

static inline void ast_nice_printReadNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("READ ");
    ast_nice_printBody(node, 0, ", ", TRUE);
    printf(";\n");
} 

static inline void ast_nice_printWriteNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("WRITE ");
    ast_nice_printBody(node, 0, ", ", TRUE);
    printf(";\n");
} 

static inline void ast_nice_printStatementNode(node_t* const node, const unsigned char indent)
{    
    ast_nice_printBody(node, indent, "", TRUE);
} 

void ast_nice_printConstNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("CONST ");
    ast_nice_printNode(node->body, 0);
    printf(" = ");
    ast_nice_printNode(node->body ? node->body->next : NULL, 0);
} 

void ast_nice_printVarNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("VAR ");
    ast_nice_printNode(node->body, 0);
    printf(": ");
    ast_nice_printNode(node->body ? node->body->next : NULL, 0);
} 

static inline void ast_nice_printTypeNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%s", node->strValue);
} 

static inline void ast_nice_printExprNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    ast_nice_printBody(node, indent, "", TRUE);
} 

static inline void ast_nice_printIntConstNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%d", node->iValue);
} 

static inline void ast_nice_printRealConstNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%f", node->fValue);
} 

static inline void ast_nice_printBoolConstNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%s", node->iValue ? "TRUE" : "FALSE");
} 

static inline void ast_nice_printStringConstNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%s", node->strValue);
} 

static inline void ast_nice_printIdentifierNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%s", node->strValue);
} 

void ast_nice_printArrayIdentifierNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%s[", node->body->strValue);
    ast_nice_printNode(node->body->next, 0);
    printf("]");
} 

void ast_nice_printOpNode(node_t* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    switch (node->iValue) {
        case OP_PLUS:
            printf(" + ");
            break;
        case OP_MINUS:
            printf(" - ");
            break;
        case OP_MUL:
            printf(" * ");
            break;
        case OP_DIV:
            printf(" / ");
            break;
        case OP_MOD:
            printf(" mod ");
            break;
        case OP_LT:
            printf(" < ");
            break;
        case OP_LE:
            printf(" <= ");
            break;
        case OP_GT:
            printf(" > ");
            break;
        case OP_GE:
            printf(" >= ");
            break;
        case OP_EQ:
            printf(" = ");
            break;
        case OP_NE:
            printf(" <> ");
            break;
        case OP_AND:
            printf(" and ");
            break;
        case OP_OR:
            printf(" or ");
            break;
    }
} 

void ast_nice_print(ast_t* ast)
{
    if (!ast) 
        printf("Warning: Empty abstract syntax tree!\n");
    else {
        printf("\n---------------------------------Abstract syntax tree [nice]--------------------------"
            "--------\n\n");
        ast_nice_printNextNode(ast);
        printf(".\n\n");
    }
}

void ast_nice_printNextNode(node_t* node)
{
    if (node->next) 
        ast_nice_printNextNode(node->next);
    ast_nice_printNode(node, 0);
}

void ast_nice_printNode(node_t* node, unsigned char indent)
{
    if (!node) {
        printf("%s[Warning: Node is NULL!]", ast_indentToStr(indent));
        return;
    }
    switch (node->type) {
        case NT_LET: 
            ast_nice_printLetNode(node, indent);
            break; 
        case NT_ASSIGN: 
            ast_nice_printAssignNode(node, indent);
            break; 
        case NT_IF: 
            ast_nice_printIfNode(node, indent);
            break; 
        case NT_WHILE: 
            ast_nice_printWhileNode(node, indent);
            break; 
        case NT_FOR: 
            ast_nice_printForNode(node, indent);
            break; 
        case NT_STATEMENT: 
            ast_nice_printStatementNode(node, indent);
            break; 
        case NT_CONST: 
            ast_nice_printConstNode(node, indent);
            break; 
        case NT_VAR: 
            ast_nice_printVarNode(node, indent);
            break; 
        case NT_TYPE: 
            ast_nice_printTypeNode(node, indent);
            break; 
        case NT_EXPR: 
            ast_nice_printExprNode(node, indent);
            break; 
        case NT_INT_CONST: 
            ast_nice_printIntConstNode(node, indent);
            break; 
        case NT_REAL_CONST: 
            ast_nice_printRealConstNode(node, indent);
            break; 
        case NT_BOOL_CONST: 
            ast_nice_printBoolConstNode(node, indent);
            break; 
        case NT_STRING_CONST:
            ast_nice_printStringConstNode(node, indent);
            break; 
        case NT_IDENTIFIER: 
            ast_nice_printIdentifierNode(node, indent);
            break; 
        case NT_ARRAY_IDENTIFIER: 
            ast_nice_printArrayIdentifierNode(node, indent);
            break; 
        case NT_OP: 
            ast_nice_printOpNode(node, indent);
            break; 
        case NT_READ: 
            ast_nice_printReadNode(node, indent);
            break; 
        case NT_WRITE:
            ast_nice_printWriteNode(node, indent);
            break;
        default:
            printf("%s[Warning {%s}: Unknown node type \"%d\"]", ast_indentToStr(indent), __FUNCTION__,
                node->type);
    }
}


void ast_tree_printBody(node_t* const node, const unsigned char indent)
{
    node_t *curr = node->body;

    while (curr) {
        ast_tree_printNode(curr, indent);
        curr = curr->next;
    }
}

void ast_tree_printBodyNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  body:\n", ast_indentToStr(indent));
    ast_tree_printBody(node, indent + 3);
} 

static inline void ast_tree_printTypeNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  strValue: \"%s\"\n", ast_indentToStr(indent), node->strValue);
} 

static inline void ast_tree_printIntConstNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  iValue: %d\n", ast_indentToStr(indent), node->iValue);
} 

static inline void ast_tree_printRealConstNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  iValue: %f\n", ast_indentToStr(indent), node->fValue);
}

static inline void ast_tree_printBoolConstNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  iValue: %d (\"%s\")\n", ast_indentToStr(indent), node->iValue,
        node->iValue ? "TRUE" : "FALSE");
} 

static inline void ast_tree_printStringConstNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  strValue: %s\n", ast_indentToStr(indent), node->strValue);
} 

static inline void ast_tree_printIdentifierNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  strValue: \"%s\"\n", ast_indentToStr(indent), node->strValue);
} 

void ast_tree_printOpNode(node_t* const node, const unsigned char indent)
{
    printf("%s- node-type: \"", ast_indentToStr(indent));
    ast_printNodeType(node);
    printf("\"\n%s  iValue: %d (\"", ast_indentToStr(indent), node->iValue);
    switch (node->iValue) {
        case OP_PLUS:
            printf("+");
            break;
        case OP_MINUS:
            printf("-");
            break;
        case OP_MUL:
            printf("*");
            break;
        case OP_DIV:
            printf("/");
            break;
        case OP_MOD:
            printf("mod");
            break;
        case OP_LT:
            printf("<");
            break;
        case OP_LE:
            printf("<=");
            break;
        case OP_GT:
            printf(">");
            break;
        case OP_GE:
            printf(">=");
            break;
        case OP_EQ:
            printf("=");
            break;
        case OP_NE:
            printf("<>");
            break;
        case OP_AND:
            printf("and");
            break;
        case OP_OR:
            printf("or");
            break;
    }
    printf("\")\n");
} 

void ast_tree_print(ast_t* const ast)
{
    if (!ast) 
        printf("Warning: Empty abstract syntax tree!\n");
    else {
        printf("---------------------------------Abstract syntax tree [tree]--------------------------"
            "--------\n\n");
        ast_tree_printNextNode(ast);
        printf("\nNodes: %d\n", nodeCnt);
    }
}

void ast_tree_printNextNode(node_t* const node)
{
    if (node->next) 
        ast_tree_printNextNode(node->next);
    ast_tree_printNode(node, 0);
}

void ast_tree_printNode(node_t* const node, const unsigned char indent)
{
    if (!node) {
        printf("%s[Warning {%s}: Node is NULL!]", ast_indentToStr(indent), __FUNCTION__);
        return;
    }
    nodeCnt++;
    switch (node->type) {
        case NT_LET: 
        case NT_ASSIGN: 
        case NT_IF: 
        case NT_WHILE: 
        case NT_FOR: 
        case NT_STATEMENT: 
        case NT_CONST: 
        case NT_VAR: 
        case NT_DECL_LIST:
            ast_tree_printBodyNode(node, indent);
            break;
        case NT_TYPE: 
            ast_tree_printTypeNode(node, indent);
            break; 
        case NT_EXPR: 
            ast_tree_printBodyNode(node, indent);
            break; 
        case NT_INT_CONST: 
            ast_tree_printIntConstNode(node, indent);
            break; 
        case NT_REAL_CONST: 
            ast_tree_printRealConstNode(node, indent);
            break; 
        case NT_BOOL_CONST: 
            ast_tree_printBoolConstNode(node, indent);
            break; 
        case NT_STRING_CONST:
            ast_tree_printStringConstNode(node, indent);
            break; 
        case NT_IDENTIFIER: 
            ast_tree_printIdentifierNode(node, indent);
            break; 
        case NT_ARRAY_IDENTIFIER: 
            ast_tree_printBodyNode(node, indent);
            break; 
        case NT_OP: 
            ast_tree_printOpNode(node, indent);
            break; 
        case NT_READ: 
            ast_tree_printBodyNode(node, indent);
            break; 
        case NT_WRITE:
            ast_tree_printBodyNode(node, indent);
            break;
        default:
            printf("%s[Warning {%s}: Unknown node type \"%d\"]", ast_indentToStr(indent), __FUNCTION__,
                node->type);
    }
}
