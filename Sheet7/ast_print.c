#include "ast_print.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOOL unsigned char
#define TRUE 1
#define FALSE 0
#define MAX_INDENT 50

//#define PRInode_astYPES

#ifdef PRInode_astYPES
#define ast_nice_printNodeType(ntStr) printf("%s{", ast_indentToStr(indent)); ast_printNodeType(node); printf("}")
#define ast_nice_printNodeTypeEx(ntStr) printf("{"); ast_printNodeType(node); printf("}")
#else
#define ast_nice_printNodeType(ntStr) printf("%s", ast_indentToStr(indent))
#define ast_nice_printNodeTypeEx(ntStr) 
#endif

unsigned int nodeCnt = 0;

void ast_printNode(const node_ast* node, const unsigned char indent);

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

char* ast_getNodeType(const node_ast* const node)
{
    switch (node->type) {
        case ASSIGN:
            return "ASSIGN       ";
        case IF: 
            return "IF           ";
        case WHILE:
            return "WHILE        ";
        case FOR:
            return "FOR          ";
        case STATEMENT:
            return "STATEMENT    ";
        case EXPR:
            return "EXPR         ";
        case OP:
            return "OP           ";
        case READ:
            return "READ         ";
        case WRITE:
            return "WRITE        ";
        case SYMBOL:
            return "SYMBOL       ";
        default:
            return "Unknown         ";
    }
}

void ast_printOpNode(const node_ast* const node, const unsigned char indent)
{
    printf("%s  op:           \"", ast_indentToStr(indent));
    switch (node->op) {
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
            printf("mod");
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
            printf("and");
            break;
        case OR:
            printf("or");
            break;
        default: 
            printf("unknown");
    }
    printf("\"\n");
} 

void ast_printEntryType(const entry_type_t entryType)
{
    switch (entryType) {
        case ET_CONST:
            printf("   ET_CONST    |");
            break;
        case ET_DECL:
            printf("    ET_DECL    |");
            break;
        case ET_CONST_DECL:
            printf(" ET_CONST_DECL |");
            break;
        default: 
            printf("    unknown    |");
    }
}

void ast_printDataType(const data_type_t dataType)
{
    switch (dataType) {
        case DT_BOOL:
            printf("   DT_BOOL  |");
            break;
        case DT_INT:
            printf("   DT_INT   |");
            break;
        case DT_REAL:
            printf("   DT_REAL  |");           
            break;
        case DT_STRING:
            printf("  DT_STRING |");           
            break;
        case DT_UNDEF:
            printf("  DT_UNDEF  |");        
            break;
        case DT_NOTDECL:
            printf(" DT_NOTDECL |");
            break;
        default: 
            printf("   unknown  |");
    }
}

void ast_printSymValue(symtab_entry_t* entry)
{
    switch (entry->entryType) {
        case ET_CONST:
            switch (entry->dataType) {
                case DT_BOOL:
                case DT_INT:
                    printf("  iValue   | %d", entry->symbol.iValue);
                    break;
                case DT_REAL:
                    printf("  fValue   | %f", entry->symbol.fValue);
                    break;
                case DT_STRING:
                    printf("  sValue   | %s", entry->symbol.sValue);
                    break;
                default:
                    printf("  unknown  | ?");
            }
            break;
        case ET_DECL:
        case ET_CONST_DECL:
            if (!symtab_isArray(entry))
                printf("   decl    | '%s'", entry->symbol.decl->ident);
            else
                printf("   decl    | '%s[%d]'", entry->symbol.decl->ident, entry->symbol.decl->size);
            break;
        default:
            printf("  unknown  | ?");
    }
}

void ast_printSymTab(symtab_tab_t* symTab, unsigned char indent)
{
    unsigned int i;
    symtab_entry_t* entry;

    if (!symTab) {
        printf("NULL\n");
        return;
    }
    printf("\n%s   idx |   entryType   |  dataType  | valueType |       value       "
        "\n%s  ------------------------------------------------------------------",    
        ast_indentToStr(indent), ast_indentToStr(indent));
    for (i = 0; i < SYMTAB_MAX_BUCKETS; i++) {
        entry = symTab[i];
        while (entry) {
            printf("\n%s   %3d |", ast_indentToStr(indent), i);
            ast_printEntryType(entry->entryType);
            ast_printDataType(entry->dataType);
            ast_printSymValue(entry);
            entry = entry->next;
        }
    }
    printf("\n");
}

void ast_printBody(const node_ast* node, const unsigned char indent)
{
    node = node->body;
    while (node) {
        ast_printNode(node, indent);
        node = node->next;
    }
}

void ast_printBodyNode(const node_ast* const node, const unsigned char indent)
{
    printf("%s  body:\n", ast_indentToStr(indent));
    ast_printBody(node, indent + 3);
} 

void ast_printSymNode(const node_ast* const node, const unsigned char indent)
{
    printf("%s  symbol:       ", ast_indentToStr(indent));
    
    printf("DataType: %s", DATA_TYPE[node->symbol->dataType]);
    printf("EntryType: %s", DATA_TYPE[node->symbol->entryType]);    
    switch (node->symbol->entryType) {
        case ET_CONST:
            switch (node->symbol->dataType) {
                case DT_BOOL:
                    printf("%d (ET_CONST, DT_BOOL -> iValue)\n", node->symbol->symbol.iValue);
                    break;
                case DT_INT:
                    printf("%d (ET_CONST, DT_INT -> iValue)\n", node->symbol->symbol.iValue);
                    break;
                case DT_REAL:
                    printf("%f (ET_CONST, DT_REAL -> fValue)\n", node->symbol->symbol.fValue);
                    break;
                case DT_STRING:
                    printf("%s (ET_CONST, DT_STRING -> sValue)\n", node->symbol->symbol.sValue);
                    break;
                default:
                    printf("unknown (ET_CONST, ?)\n");
            }
            break;
        case ET_DECL:
        case ET_CONST_DECL:
            if (!symtab_isArray(node->symbol))
                printf("'%s' (", node->symbol->symbol.decl->ident);
            else
                printf("'%s[%d]' (", node->symbol->symbol.decl->ident, node->symbol->symbol.decl->size);
            if (node->symbol->entryType == ET_DECL)
                printf("ET_DECL, ");
            else
                printf("ET_CONST_DECL, ");
            switch (node->symbol->dataType) {
                case DT_BOOL:
                    printf("DT_BOOL -> decl)\n");
                    break;
                case DT_INT:
                    printf("DT_INT -> decl)\n");
                    break;
                case DT_REAL:
                    printf("DT_REAL -> decl)\n");
                    break;
                case DT_NOTDECL:
                    printf("DT_NOTDECL -> decl)\n");
                    break;
                default:
                    printf("unknown -> decl)\n");
            }
            break;
        default:
            printf("unknown (?)\n");
    }
} 

void ast_printNode(const node_ast* const node, const unsigned char indent)
{
    if (!node) {
        printf("%s[Warning {%s}: Node is NULL!]\n", ast_indentToStr(indent), __FUNCTION__);
        return;
    }
    nodeCnt++;
//    printf("%s- node-type:    %s\n%s  Outer scope:  %s\n", ast_indentToStr(indent), 
//        ast_getNodeType(node), ast_indentToStr(indent), node->outerScope ? "true" : "false");
    printf("%s  Symbol table: ", ast_indentToStr(indent));
    ast_printSymTab(node->symTab, indent + 3);
    printf("--------%s ---------", STRING_NODE[node->type]);
    switch (node->type) {
        case PROGRAM:
        case ASSIGN:
        case IF:
        case WHILE:
        case FOR:
        case STATEMENT:
        case EXPR:
        case READ:
        case WRITE:
            ast_printBodyNode(node, indent);
            break;
        case OP:
            ast_printOpNode(node, indent);
            break;
        case SYMBOL:
            ast_printSymNode(node, indent);
            break;
        default:
            printf("%s[Warning {%s}: Unknown node type \"%d\"]\n", ast_indentToStr(indent), __FUNCTION__,
                node->type);
    }
}

void ast_printNextNode(const node_ast* const node)
{
    if (node->next) 
        ast_printNextNode(node->next);
    ast_printNode(node, 0);
}

void ast_print(const ast_t* const ast)
{
    if (!ast || !ast->root) 
        printf("Warning: Empty abstract syntax tree!\n");
    else {
        printf("---------------------------------Abstract syntax tree----------------------------------"
            "\n\n");
        ast_printNextNode(ast->root);
        printf("\nNodes: %d\n", nodeCnt);
    }
}

//
//void ast_printEntryType(entry_type_t entryType)
//{
//    switch (entryType) {
//        case ET_CONST:
//            printf("   ET_CONST    |");
//            break;
//        case ET_DECL:
//            printf("    ET_DECL    |");
//            break;
//        case ET_CONST_DECL:
//            printf(" ET_CONST_DECL |");
//            break;
//        default: 
//            printf("    unknown    |");
//    }
//}
//
//void ast_printDataType(data_type_t dataType)
//{
//    switch (dataType) {
//        case DT_BOOL:
//            printf("   DT_BOOL  |");
//            break;
//        case DT_INT:
//            printf("   DT_INT   |");
//            break;
//        case DT_REAL:
//            printf("   DT_REAL  |");           
//            break;
//        case DT_STRING:
//            printf("  DT_STRING |");           
//            break;
//        case DT_UNDEF:
//            printf("  DT_UNDEF  |");        
//            break;
//        case DT_NOTDECL:
//            printf(" DT_NOTDECL |");
//            break;
//        default: 
//            printf("   unknown  |");
//    }
//}
//
//void ast_printSymValue(symtab_entry_t* entry)
//{
//    switch (entry->entryType) {
//        case ET_CONST:
//            switch (entry->dataType) {
//                case DT_BOOL:
//                case DT_INT:
//                    printf("  iValue   | %d", entry->symbol.iValue);
//                    break;
//                case DT_REAL:
//                    printf("  fValue   | %f", entry->symbol.fValue);
//                    break;
//                case DT_STRING:
//                    printf("  sValue   | %s", entry->symbol.sValue);
//                    break;
//                default:
//                    printf("  unknown  | ?");
//            }
//            break;
//        case ET_DECL:
//        case ET_CONST_DECL:
//            if (!symtab_isArray(entry))
//                printf("   decl    | '%s'", entry->symbol.decl->ident);
//            else
//                printf("   decl    | '%s[%d]'", entry->symbol.decl->ident, entry->symbol.decl->size);
//            break;
//        default:
//            printf("  unknown  | ?");
//    }
//}
//
//void ast_printSymTab(symtab_tab_t* symTab, unsigned char indent)
//{
//    unsigned int i;
//    symtab_entry_t* entry;
//
//    if (!symTab) {
//        printf("NULL\n");
//        return;
//    }
//    printf("\n%s   idx |   entryType   |  dataType  | valueType |       value       "
//        "\n%s  ------------------------------------------------------------------",    
//        ast_indentToStr(indent), ast_indentToStr(indent));
//    for (i = 0; i < SYMTAB_MAX_BUCKETS; i++) {
//        entry = symTab[i];
//        while (entry) {
//            printf("\n%s   %3d |", ast_indentToStr(indent), i);
//            ast_printEntryType(entry->entryType);
//            ast_printDataType(entry->dataType);
//            ast_printSymValue(entry);
//            entry = entry->next;
//        }
//    }
//    printf("\n");
//}

