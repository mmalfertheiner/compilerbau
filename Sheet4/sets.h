#ifndef _SETS_H_
#define _SETS_H_

// define list of FirstSets
const Token First_Start = { Token_program }
const Token First_VarDecList = { Token_identifier }
#define First_IdenListType = First_VarDecList
#define First_IdenList = First_VarDecList
const Token First_Type = { Token_array, Token_integer, Token_real, Token_string }
const Token First_SimpleType = { Token_integer, Token_real, Token_string }
const Token First_CompStmt = { Token_begin }
const Token First_StmtList = { Token_begin, Token_read, Token_write, Token_identifier, Token_if, Token_while, Token_for}
#define First_Statement = First_StmtList
const Token First_AssignStmt = { Token_identifier }
const Token First_Index = { Token_lBracket }
const Token First_IfStmt = { Token_if }
const Token First_WhileStmt = { Token_while }
const Token First_ForStmt = { Token_for }
const Token First_ToPart = { Token_to, Token_downTo }
const Token First_ExprList = { Token_Integer, Token_Real, Token_String, Token_true, Token_false, Token_identifier, Token_not, Token_sub, Token_lBracket }
#define First_Expr = First_ExprList
#define First_SimpleExpr = First_Expr
#define First_Term = First_SimpleExpr
#define First_Factor = First_Term
const Token First_RelOp = { Token_less, Token_leq, Token_bigger, Token_beq, Token_eq, Token_noteq}
const Token First_AddOp = { Token_add, Token_sub, Token_or }
const Token First_MulOp = { Token_mult, Token_div, Token_divide, Token_mod, Token_and }

#endif /* _SETS_H_ */