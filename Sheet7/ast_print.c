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


void ast_nice_printNode(node_ast* const node, const unsigned char indent);
void ast_nice_printNextNode(node_ast* const node);
void ast_tree_printNode(node_ast* const node, const unsigned char indent);
void ast_tree_printNextNode(node_ast* const node);

unsigned int nodeCnt = 0;


char* ast_indentToStr(const unsigned char indent)
{
    static char indentStr[MAX_INDENT];
    size_t len = (indent > MAX_INDENT - 1 ? MAX_INDENT - 1 : indent);
    unsigned char i;
//printf("%zd", len);
    for (i = 0; i < len; i++)
        indentStr[i] = ' ';
    indentStr[len] = '\0';
    return indentStr;
}

char ast_strLast(const char *str)
{
    size_t len = strlen(str);

    return len > 0 ? str[len - 1] : '\0';
}


void ast_printNodeType(node_ast* const node)
{
    switch (node->type) {
        case PROGRAM:
            printf("PROGRAM");
            break;
        case ASSIGN:
            printf("ASSIGN");
            break;
        case READ:
            printf("READ");
            break;
        case WRITE:
            printf("WRITE");
            break;
        case IF:
            printf("IF");
            break;
        case WHILE:
            printf("WHILE");
            break;
        case FOR:
            printf("FOR");
            break;
        case COMP_STMT:
            printf("COMP_STMT");
            break;
        case STATEMENT:
            printf("STATEMENT");
            break;
        case CONST:
            printf("CONST");
            break;
        case VAR_LIST:
            printf("VAR_LIST");
            break;
        case VAR:
            printf("VAR");
            break;
        case TYPE:
            printf("TYPE");
            break;
        case EXPR:
            printf("EXPR");
            break;
        case INT_CONST:
            printf("INT_CONST");
            break;
        case REAL_CONST:
            printf("REAL_CONST");
            break;
        case FACTOR:
            printf("FACTOR");
            break;
        case BOOL_CONST:
            printf("BOOL_CONST");
            break;
        case STRING_CONST:
            printf("STRING_CONST");
            break;
        case ARRAY_TYPE:
            printf("ARRAY_TYPE");
            break;
        case ARRAY_IDENTIFIER:
            printf("ARRAY_IDENTIFIER");
            break;
        case IDENT_LIST_TYPE:
            printf("IDENT_LIST_TYPE");
            break;
        case IDENTIFIER_LIST:
            printf("IDENTIFIER_LIST");
            break;
        case IDENTIFIER:
            printf("IDENTIFIER");
            break;
        case OP:
            printf("OP");
            break;
        default:
            printf("Unknown node type \"%d\"", node->type);
    }
    
}

void ast_nice_printBody(node_ast* const node, const unsigned char indent, const char *delim, 
    const BOOL skipLastDelim)
{
    if (!node)
        printf("%s[Warning {%s}: Node is NULL!]", ast_indentToStr(indent), __FUNCTION__);
    else {
        node_ast *curr = node->body;

        while (curr) {
            ast_nice_printNode(curr, indent);
            curr = curr->next;
            if (curr || !skipLastDelim)
                printf("%s%s", delim, ast_strLast(delim) == '\n' ? ast_indentToStr(indent) : "");
        }
    }
}

void ast_nice_printBodyEx(node_ast* const node, const unsigned char indent, const char *delims, 
    const unsigned char delimLen)
{
    if (!node)
        printf("%s[Warning {%s}: Node is NULL!]", ast_indentToStr(indent), __FUNCTION__);
    else {
        node_ast *curr = node->body;
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

void ast_nice_printProgramNode(node_ast* const node, const unsigned char indent)
{
    char *newIndent[50];

    ast_nice_printNodeType();
    printf("\n%sPROGRAM ", ast_indentToStr(indent));
    ast_nice_printNode(node->body, 0);
    printf(" ;\n");

    ast_nice_printNode(node->body ? node->body->next : NULL, indent + 3);
    ast_nice_printNode(node->body->next ? node->body->next->next : NULL, indent);

    printf("%s.\n", ast_indentToStr(indent));
} 

void ast_nice_printAssignNode(node_ast* const node, const unsigned char indent)
{
    printf("\n");
    ast_nice_printNodeType();
    ast_nice_printBodyEx(node, 0, " := ", 4);
} 

void ast_nice_printIfNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("IF ");
    ast_nice_printNode(node->body, 0);
    printf(" THEN\n");
    ast_nice_printNode(node->body ? node->body->next : NULL, indent + 3);
    if (node->body && node->body->next && node->body->next->next) {
        printf("\n%sELSE\n", ast_indentToStr(indent + 3));
        ast_nice_printNode(node->body->next->next, indent + 3);
    }
} 

void ast_nice_printWhileNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("WHILE ");
    ast_nice_printNode(node->body, 0);
    printf(" DO\n");
    ast_nice_printNode(node->body ? node->body->next : NULL, indent + 3);
} 

void ast_nice_printForNode(node_ast* const node, const unsigned char indent)
{
    printf("\n");
    ast_nice_printNodeType();
    printf("FOR ");
    ast_nice_printNode(node->body, 0);
    printf(" := ");
    ast_nice_printNode(node->body ? node->body->next : NULL, 0);
    printf(" TO ");
    ast_nice_printNode(node->body && node->body->next ? node->body->next->next : NULL, 0);
    printf(" DO\n");
    ast_nice_printNode(node->body && node->body->next && node->body->next->next ? 
        node->body->next->next->next : NULL, indent + 3);
} 

void ast_nice_printReadNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%sREAD (", ast_indentToStr(indent));
    ast_nice_printBody(node, 0, ", ", TRUE);
    printf(")");
} 

void ast_nice_printWriteNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("%sWRITE (", ast_indentToStr(indent));
    ast_nice_printBody(node, 0, ", ", TRUE);
    printf(")");
}

void ast_nice_printCompStmtNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("BEGIN\n");
    ast_nice_printBody(node, indent+3, ";\n", TRUE);
    printf("\n%sEND", ast_indentToStr(indent));
}

void ast_nice_printStatementNode(node_ast* const node, const unsigned char indent)
{   
    ast_nice_printNodeType(); 
    ast_nice_printBody(node, indent, "", TRUE);
} 

void ast_nice_printConstNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("CONST ");
    ast_nice_printNode(node->body, 0);
    printf("=");
    ast_nice_printNode(node->body ? node->body->next : NULL, 0);
}

void ast_nice_printVarListNode(node_ast* const node, const unsigned char indent) {
    ast_nice_printNodeType();
    printf("VAR ");
    ast_nice_printBody(node, 0, ";\n   ", FALSE);
}

void ast_nice_printVarNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    ast_nice_printNode(node->body, 0);
} 

void ast_nice_printTypeNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%s", node->identifier);
} 

void ast_nice_printExprNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    ast_nice_printBody(node, 0, " ", TRUE);
} 

void ast_nice_printBracketExprNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    printf("(");
    ast_nice_printBody(node, 0, " ", TRUE);
    printf(")");
} 

void ast_nice_printIntConstNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%d", node->iValue);
} 

void ast_nice_printRealConstNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%f", node->fValue);
} 

void ast_nice_printBoolConstNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%s", node->iValue == 1 ? "TRUE" : "FALSE");
} 

void ast_nice_printStringConstNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%s", node->identifier);
}

void ast_nice_printIdentListType(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    ast_nice_printNode(node->body, 0);
    printf(" :");
    ast_nice_printNode(node->body->next, 0);
}

void ast_nice_printIdentifierList(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    ast_nice_printBody(node, 0, ", ", TRUE);
} 

void ast_nice_printIdentifierNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%s", node->identifier);
}

void ast_nice_printArrayType(node_ast* const node, const unsigned char indent) {
    ast_nice_printNodeType();
    printf("ARRAY [");
    ast_nice_printNode(node->body, 0);
    printf("..");
    ast_nice_printNode(node->body->next, 0);
    printf("] OF ");
    ast_nice_printNode(node->body->next->next, 0);
}

void ast_nice_printArrayIdentifierNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    //printf("%s[", node->body->identifier);
    ast_nice_printNode(node->body->next, 0);
    printf("]");
}

void ast_nice_printOpNode(node_ast* const node, const unsigned char indent)
{
    ast_nice_printNodeType();
    /**switch (node->iValue) {
        case PLUS:
            printf("+");
            break;
        case MINUS:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("MOD");
            break;
        case LT:
            printf("<");
            break;
        case LE:
            printf("<=");
            break;
        case GT:
            printf(">");
            break;
        case GE:
            printf(">=");
            break;
        case EQ:
            printf("=");
            break;
        case NE:
            printf("<>");
            break;
        case AND:
            printf("AND");
            break;
        case OR:
            printf("OR");
            break;
    }**/
} 

void ast_nice_print(node_ast* ast)
{
    if (!ast) 
        printf("Warning: Empty abstract syntax tree!\n");
    else {
        printf("\n---------------------------------Abstract syntax tree [nice]--------------------------"
            "--------\n\n");
        ast_nice_printNextNode(ast);
    }
}

void ast_nice_printNextNode(node_ast* node)
{
    if (node->next) 
        ast_nice_printNextNode(node->next);
    ast_nice_printNode(node, 0);
}


/*
PROGRAM, ASSIGN, READ, WRITE, IF, WHILE, FOR, STATEMENT, CONST, VAR, TYPE,
    EXPR, INT_CONST, REAL_CONST, FACTOR, BOOL_CONST, STRING_CONST, ARRAY_IDENTIFIER, IDENTIFIER, OP
*/

void ast_nice_printNode(node_ast* node, unsigned char indent)
{
    if (!node) {
        printf("%s[Warning: Node is NULL!]", ast_indentToStr(indent));
        return;
    }
    switch (node->type) {
        case PROGRAM: 
            ast_nice_printProgramNode(node, indent);
            break;
        case ASSIGN: 
            ast_nice_printAssignNode(node, indent);
            break;
        case READ: 
            ast_nice_printReadNode(node, indent);
            break; 
        case WRITE:
            ast_nice_printWriteNode(node, indent);
            break;
        case IF: 
            ast_nice_printIfNode(node, indent);
            break; 
        case WHILE: 
            ast_nice_printWhileNode(node, indent);
            break; 
        case FOR: 
            ast_nice_printForNode(node, indent);
            break;
        case COMP_STMT:
            ast_nice_printCompStmtNode(node, indent);
            break;
        case STATEMENT: 
            ast_nice_printStatementNode(node, indent);
            break; 
        case CONST: 
            ast_nice_printConstNode(node, indent);
            break;
        case VAR_LIST: 
            ast_nice_printVarListNode(node, indent);
            break;
        case VAR: 
            ast_nice_printVarNode(node, indent);
            break;
        case TYPE: 
            ast_nice_printTypeNode(node, indent);
            break; 
        case EXPR: 
            ast_nice_printExprNode(node, indent);
            break;
        case BRACKET_EXPR:
            ast_nice_printBracketExprNode(node, indent);
            break;
        case INT_CONST: 
            ast_nice_printIntConstNode(node, indent);
            break; 
        case REAL_CONST: 
            ast_nice_printRealConstNode(node, indent);
            break; 
        case BOOL_CONST: 
            ast_nice_printBoolConstNode(node, indent);
            break; 
        case STRING_CONST:
            ast_nice_printStringConstNode(node, indent);
            break;
        case IDENT_LIST_TYPE:
            ast_nice_printIdentListType(node, indent);
            break;
        case IDENTIFIER_LIST:
            ast_nice_printIdentifierList(node, indent);
            break;
        case IDENTIFIER: 
            ast_nice_printIdentifierNode(node, indent);
            break;
        case ARRAY_TYPE:
            ast_nice_printArrayType(node, indent);
            break;
        case ARRAY_IDENTIFIER: 
            ast_nice_printArrayIdentifierNode(node, indent);
            break; 
        case OP: 
            ast_nice_printOpNode(node, indent);
            break; 
        
        default:
            printf("%s[Warning {%s}: Unknown node type \"%d\"]", ast_indentToStr(indent), __FUNCTION__,
                node->type);
    }
}
