/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Token_add = 258,
    Token_and = 259,
    Token_array = 260,
    Token_assign = 261,
    Token_begin = 262,
    Token_beq = 263,
    Token_bigger = 264,
    Token_colon = 265,
    Token_comma = 266,
    Token_div = 267,
    Token_divide = 268,
    Token_do = 269,
    Token_dot = 270,
    Token_downTo = 271,
    Token_else = 272,
    Token_end = 273,
    Token_eq = 274,
    Token_error = 275,
    Token_false = 276,
    Token_for = 277,
    Token_identifier = 278,
    Token_if = 279,
    Token_Integer = 280,
    Token_integer = 281,
    Token_lBracket = 282,
    Token_leq = 283,
    Token_less = 284,
    Token_lRectBracket = 285,
    Token_mod = 286,
    Token_mult = 287,
    Token_not = 288,
    Token_noteq = 289,
    Token_of = 290,
    Token_or = 291,
    Token_program = 292,
    Token_rBracket = 293,
    Token_read = 294,
    Token_Real = 295,
    Token_real = 296,
    Token_repeat = 297,
    Token_rRectBracket = 298,
    Token_semicolon = 299,
    Token_String = 300,
    Token_string = 301,
    Token_sub = 302,
    Token_then = 303,
    Token_to = 304,
    Token_true = 305,
    Token_until = 306,
    Token_var = 307,
    Token_while = 308,
    Token_write = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:1909  */

	int iValue; 		/* integer, true, false, compOp, addOp, mulOp */
	float fValue;		/* number */		
	char *identifier;	/* string, identifier */
	struct _node *body; /* list of BNF right-hand side symbols of nonterminal type */

#line 116 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
