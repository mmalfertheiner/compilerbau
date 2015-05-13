/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define Token_add 258
#define Token_and 259
#define Token_array 260
#define Token_assign 261
#define Token_begin 262
#define Token_beq 263
#define Token_bigger 264
#define Token_colon 265
#define Token_comma 266
#define Token_div 267
#define Token_divide 268
#define Token_do 269
#define Token_dot 270
#define Token_downTo 271
#define Token_else 272
#define Token_end 273
#define Token_eq 274
#define Token_error 275
#define Token_false 276
#define Token_for 277
#define Token_identifier 278
#define Token_if 279
#define Token_Integer 280
#define Token_integer 281
#define Token_lBracket 282
#define Token_leq 283
#define Token_less 284
#define Token_lRectBracket 285
#define Token_mod 286
#define Token_mult 287
#define Token_not 288
#define Token_noteq 289
#define Token_of 290
#define Token_or 291
#define Token_program 292
#define Token_rBracket 293
#define Token_read 294
#define Token_Real 295
#define Token_real 296
#define Token_repeat 297
#define Token_rRectBracket 298
#define Token_semicolon 299
#define Token_String 300
#define Token_string 301
#define Token_sub 302
#define Token_then 303
#define Token_to 304
#define Token_true 305
#define Token_until 306
#define Token_var 307
#define Token_while 308
#define Token_write 309




/* Copy the first part of user declarations.  */
#line 1 "parser.y"
 

int yylex(void);

#include <stdio.h>
#include "ast.h"
#include "ast_print.h"

#define YYERROR_VERBOSE

extern int yylineno;

int yyerror (const char *s);

unsigned int errorFound = 0;
node_ast *ast = NULL;

int yydebug=1;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "parser.y"
{
	int iValue; 		/* integer, true, false, compOp, addOp, mulOp */
	float fValue;		/* number */		
	char *identifier;	/* string, identifier */
	struct _node *body; /* list of BNF right-hand side symbols of nonterminal type */
}
/* Line 193 of yacc.c.  */
#line 232 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 245 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    13,    14,    18,    21,    25,    29,
      31,    33,    43,    45,    47,    49,    53,    57,    59,    61,
      63,    65,    67,    69,    74,    79,    83,    88,    92,    98,
     101,   102,   107,   116,   118,   120,   124,   126,   130,   132,
     136,   138,   142,   144,   146,   148,   150,   152,   154,   156,
     159,   162,   165,   169,   171,   173,   175,   177,   179,   181,
     183,   185,   187,   189,   191,   193,   195
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    37,    23,    44,    57,    63,    15,    -1,
      52,    58,    -1,    -1,    58,    59,    44,    -1,    59,    44,
      -1,    60,    10,    61,    -1,    60,    11,    23,    -1,    23,
      -1,    62,    -1,     5,    30,    25,    15,    15,    25,    43,
      35,    62,    -1,    26,    -1,    41,    -1,    46,    -1,     7,
      64,    18,    -1,    64,    44,    65,    -1,    65,    -1,    66,
      -1,    63,    -1,    68,    -1,    70,    -1,    71,    -1,    39,
      27,    73,    38,    -1,    54,    27,    73,    38,    -1,    23,
       6,    74,    -1,    23,    67,     6,    74,    -1,    30,    74,
      43,    -1,    24,    74,    48,    65,    69,    -1,    17,    65,
      -1,    -1,    53,    74,    14,    65,    -1,    22,    23,     6,
      74,    72,    74,    14,    65,    -1,    49,    -1,    16,    -1,
      73,    11,    74,    -1,    74,    -1,    75,    78,    75,    -1,
      75,    -1,    75,    79,    76,    -1,    76,    -1,    76,    80,
      77,    -1,    77,    -1,    25,    -1,    40,    -1,    45,    -1,
      21,    -1,    50,    -1,    23,    -1,    23,    67,    -1,    33,
      77,    -1,    47,    77,    -1,    27,    74,    38,    -1,    29,
      -1,    28,    -1,     9,    -1,     8,    -1,    19,    -1,    34,
      -1,     3,    -1,    47,    -1,    36,    -1,    32,    -1,    13,
      -1,    12,    -1,    31,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   107,   108,   111,   114,   118,   122,   125,
     128,   129,   138,   139,   140,   145,   150,   153,   158,   159,
     160,   161,   162,   163,   164,   167,   170,   181,   186,   191,
     192,   197,   202,   210,   211,   216,   219,   224,   227,   232,
     235,   240,   243,   248,   249,   250,   251,   252,   253,   254,
     259,   260,   261,   266,   267,   268,   269,   270,   271,   276,
     277,   278,   283,   284,   285,   286,   287
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Token_add", "Token_and", "Token_array",
  "Token_assign", "Token_begin", "Token_beq", "Token_bigger",
  "Token_colon", "Token_comma", "Token_div", "Token_divide", "Token_do",
  "Token_dot", "Token_downTo", "Token_else", "Token_end", "Token_eq",
  "Token_error", "Token_false", "Token_for", "Token_identifier",
  "Token_if", "Token_Integer", "Token_integer", "Token_lBracket",
  "Token_leq", "Token_less", "Token_lRectBracket", "Token_mod",
  "Token_mult", "Token_not", "Token_noteq", "Token_of", "Token_or",
  "Token_program", "Token_rBracket", "Token_read", "Token_Real",
  "Token_real", "Token_repeat", "Token_rRectBracket", "Token_semicolon",
  "Token_String", "Token_string", "Token_sub", "Token_then", "Token_to",
  "Token_true", "Token_until", "Token_var", "Token_while", "Token_write",
  "$accept", "start", "varDec", "varDecList", "identListType", "identList",
  "type", "simpleType", "compStmt", "stmtList", "statement", "assignStmt",
  "index", "ifStmt", "elsePart", "whileStmt", "forStmt", "toPart",
  "exprList", "expr", "simpleExpr", "term", "factor", "relOp", "addOp",
  "mulOp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     3,     2,     3,     3,     1,
       1,     9,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     4,     3,     5,     2,
       0,     4,     8,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,     9,     3,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,    17,    18,    20,    21,
      22,     2,     5,     0,    12,    13,    14,     7,    10,     8,
       0,     0,     0,     0,    46,    48,    43,     0,     0,    44,
      45,     0,    47,     0,    38,    40,    42,     0,     0,     0,
      15,     0,     0,     0,    25,     0,     0,    49,     0,    50,
      51,     0,    59,    56,    55,    57,    54,    53,    58,    61,
      60,     0,     0,    66,    64,    63,    65,    62,     0,     0,
      36,     0,     0,    16,     0,     0,    27,    26,    52,    30,
      37,    39,    41,     0,    23,    31,    24,     0,    34,    33,
       0,     0,    28,    35,     0,     0,    29,     0,     0,     0,
      32,     0,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    11,    37,    38,    24,    25,
      26,    27,    43,    28,   112,    29,    30,   110,    89,    90,
      54,    55,    56,    81,    82,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -61
static const yytype_int8 yypact[] =
{
     -25,    -6,    28,   -15,   -61,   -22,    32,    50,   -61,    32,
      16,    15,    -4,    46,    22,   -61,    18,    39,    45,    10,
      42,    43,    42,    47,   -61,   -12,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,    48,   -61,   -61,   -61,   -61,   -61,   -61,
      71,    42,    42,    73,   -61,    51,   -61,    42,    42,   -61,
     -61,    42,   -61,    36,     5,    41,   -61,    42,    66,    42,
     -61,    -4,    60,    42,   -61,    52,    42,   -61,    53,   -61,
     -61,    -4,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,    42,    42,   -61,   -61,   -61,   -61,   -61,    42,    -2,
     -61,    -4,     4,   -61,    78,   -11,   -61,   -61,   -61,    69,
       1,    41,   -61,    42,   -61,   -61,   -61,    79,   -61,   -61,
      42,    -4,   -61,   -61,    63,    82,   -61,    54,    -4,    64,
     -61,    30,   -61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,    89,   -61,   -61,   -21,    94,   -61,
     -60,   -61,    57,   -61,   -61,   -61,   -61,   -61,    44,   -20,
      23,    24,   -41,   -61,   -61,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,    93,    58,    12,    72,   108,    60,    69,    72,   103,
      70,    99,     1,    73,    74,   103,    41,     3,    18,    19,
      20,    64,    65,    33,    75,    16,    17,    68,     4,     5,
       6,   105,    61,    76,    77,    21,   104,    79,   109,    78,
      42,    79,   106,    95,    34,    83,    97,   102,    80,    22,
      23,   116,    80,    84,    85,     8,    34,    12,   120,    35,
      15,    31,    39,    44,    36,    45,    32,    46,    40,    47,
      57,    35,    86,    87,    59,    48,    36,    63,    62,    66,
      91,    42,    49,   113,    71,    94,   111,    50,   117,    51,
     115,    98,    52,   107,   114,    96,   118,   119,    14,   121,
     122,    13,    67,    92,   100,     0,   101
};

static const yytype_int8 yycheck[] =
{
      20,    61,    22,     7,     3,    16,    18,    48,     3,    11,
      51,    71,    37,     8,     9,    11,     6,    23,    22,    23,
      24,    41,    42,     5,    19,    10,    11,    47,     0,    44,
      52,    91,    44,    28,    29,    39,    38,    36,    49,    34,
      30,    36,    38,    63,    26,     4,    66,    88,    47,    53,
      54,   111,    47,    12,    13,    23,    26,     7,   118,    41,
      44,    15,    23,    21,    46,    23,    44,    25,    23,    27,
      27,    41,    31,    32,    27,    33,    46,     6,    30,     6,
      14,    30,    40,   103,    48,    25,    17,    45,    25,    47,
     110,    38,    50,    15,    15,    43,    14,    43,     9,    35,
     121,     7,    45,    59,    81,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    56,    23,     0,    44,    52,    57,    23,    58,
      59,    60,     7,    63,    59,    44,    10,    11,    22,    23,
      24,    39,    53,    54,    63,    64,    65,    66,    68,    70,
      71,    15,    44,     5,    26,    41,    46,    61,    62,    23,
      23,     6,    30,    67,    21,    23,    25,    27,    33,    40,
      45,    47,    50,    74,    75,    76,    77,    27,    74,    27,
      18,    44,    30,     6,    74,    74,     6,    67,    74,    77,
      77,    48,     3,     8,     9,    19,    28,    29,    34,    36,
      47,    78,    79,     4,    12,    13,    31,    32,    80,    73,
      74,    14,    73,    65,    25,    74,    43,    74,    38,    65,
      75,    76,    77,    11,    38,    65,    38,    15,    16,    49,
      72,    17,    69,    74,    15,    74,    65,    25,    14,    43,
      65,    35,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 101 "parser.y"
    { ast = ast_new_bodyNodeN(PROGRAM, 3, 
			 												   				ast_new_strNode(IDENTIFIER, (yyvsp[(2) - (6)].identifier)),
																	   		(yyvsp[(4) - (6)].body), (yyvsp[(5) - (6)].body));
																		;}
    break;

  case 3:
#line 107 "parser.y"
    { (yyval.body) = ast_new_bodyNode(VAR_LIST, (yyvsp[(2) - (2)].body)); ;}
    break;

  case 4:
#line 108 "parser.y"
    { (yyval.body) = NULL; ;}
    break;

  case 5:
#line 111 "parser.y"
    { (yyval.body) = (yyvsp[(1) - (3)].body);
																			ast_addNode((yyvsp[(1) - (3)].body), (yyvsp[(2) - (3)].body)); 
																		;}
    break;

  case 6:
#line 114 "parser.y"
    { (yyval.body) = (yyvsp[(1) - (2)].body); ;}
    break;

  case 7:
#line 118 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(IDENTIFIER_LIST, 2, (yyvsp[(1) - (3)].body), (yyvsp[(3) - (3)].body)); ;}
    break;

  case 8:
#line 122 "parser.y"
    { (yyval.body) = (yyvsp[(1) - (3)].body);
																			ast_addNode((yyvsp[(1) - (3)].body), ast_new_strNode(IDENTIFIER, (yyvsp[(3) - (3)].identifier)));
																		;}
    break;

  case 9:
#line 125 "parser.y"
    { (yyval.body) = ast_new_strNode(IDENTIFIER, (yyvsp[(1) - (1)].identifier)); ;}
    break;

  case 11:
#line 131 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(VAR, 2, 
					 												   		ast_new_iNode(INT_CONST, (yyvsp[(3) - (9)].iValue)), (yyvsp[(9) - (9)].body));
					 													;}
    break;

  case 12:
#line 138 "parser.y"
    { (yyval.body) = ast_new_strNode(TYPE, "integer"); ;}
    break;

  case 13:
#line 139 "parser.y"
    { (yyval.body) = ast_new_strNode(TYPE, "real"); ;}
    break;

  case 14:
#line 140 "parser.y"
    { (yyval.body) = ast_new_strNode(TYPE, "string"); ;}
    break;

  case 15:
#line 145 "parser.y"
    { (yyval.body) = (yyvsp[(2) - (3)].body); ;}
    break;

  case 16:
#line 150 "parser.y"
    { (yyval.body) = (yyvsp[(1) - (3)].body);
																					ast_addNode((yyvsp[(1) - (3)].body), (yyvsp[(3) - (3)].body));
																				;}
    break;

  case 23:
#line 163 "parser.y"
    { (yyval.body) = ast_new_bodyNode(READ, (yyvsp[(3) - (4)].body)); ;}
    break;

  case 24:
#line 164 "parser.y"
    { (yyval.body) = ast_new_bodyNode(WRITE, (yyvsp[(3) - (4)].body)); ;}
    break;

  case 25:
#line 167 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(ASSIGN, 2, 
																						ast_new_strNode(IDENTIFIER, (yyvsp[(1) - (3)].identifier)), (yyvsp[(3) - (3)].body));
																				;}
    break;

  case 26:
#line 170 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(ASSIGN, 2, 	
																				   		ast_new_bodyNodeN(ARRAY_IDENTIFIER, 2,
																				       		 ast_new_strNode(IDENTIFIER, 
																				   	   		 (yyvsp[(1) - (4)].identifier))
																				   	   		 , (yyvsp[(2) - (4)].body))
																				   		, (yyvsp[(4) - (4)].body));
																				;}
    break;

  case 27:
#line 181 "parser.y"
    { (yyval.body) = (yyvsp[(2) - (3)].body); ;}
    break;

  case 28:
#line 186 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(IF, 3, (yyvsp[(2) - (5)].body), (yyvsp[(4) - (5)].body), (yyvsp[(5) - (5)].body)); ;}
    break;

  case 29:
#line 191 "parser.y"
    { (yyval.body) = (yyvsp[(2) - (2)].body); ;}
    break;

  case 30:
#line 192 "parser.y"
    { (yyval.body) = NULL; ;}
    break;

  case 31:
#line 197 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(WHILE, 2, (yyvsp[(2) - (4)].body), (yyvsp[(4) - (4)].body)); ;}
    break;

  case 32:
#line 203 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(FOR, 4,
					 												   ast_new_strNode(IDENTIFIER, (yyvsp[(2) - (8)].identifier)),
																	   (yyvsp[(4) - (8)].body), (yyvsp[(6) - (8)].body), (yyvsp[(8) - (8)].body)); ;}
    break;

  case 33:
#line 210 "parser.y"
    { (yyval.body) = ast_new_strNode(CONST, "to"); ;}
    break;

  case 34:
#line 211 "parser.y"
    { (yyval.body) = ast_new_strNode(CONST, "downto"); ;}
    break;

  case 35:
#line 216 "parser.y"
    { (yyval.body) = (yyvsp[(1) - (3)].body);
																ast_addNode((yyvsp[(1) - (3)].body), (yyvsp[(3) - (3)].body));
															;}
    break;

  case 37:
#line 224 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(EXPR, 3, (yyvsp[(1) - (3)].body), 
																		ast_new_iNode(OP, (yyvsp[(2) - (3)].iValue)), (yyvsp[(3) - (3)].body));
															;}
    break;

  case 39:
#line 232 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(EXPR, 3, (yyvsp[(1) - (3)].body), 
																	   ast_new_iNode(OP, (yyvsp[(2) - (3)].iValue)), (yyvsp[(3) - (3)].body));
															;}
    break;

  case 41:
#line 240 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(EXPR, 3, (yyvsp[(1) - (3)].body), 
																	   ast_new_iNode(OP, (yyvsp[(2) - (3)].iValue)), (yyvsp[(3) - (3)].body));
															;}
    break;

  case 43:
#line 248 "parser.y"
    { (yyval.body) = ast_new_iNode(INT_CONST, (yyvsp[(1) - (1)].iValue));;}
    break;

  case 44:
#line 249 "parser.y"
    { (yyval.body) = ast_new_fNode(REAL_CONST, (yyvsp[(1) - (1)].fValue));	;}
    break;

  case 45:
#line 250 "parser.y"
    { (yyval.body) = ast_new_strNode(STRING_CONST, (yyvsp[(1) - (1)].identifier));;}
    break;

  case 46:
#line 251 "parser.y"
    { (yyval.body) = ast_new_iNode(Token_false, (yyvsp[(0) - (1)].iValue));;}
    break;

  case 47:
#line 252 "parser.y"
    { (yyval.body) = ast_new_iNode(Token_true, (yyvsp[(1) - (1)].iValue)); ;}
    break;

  case 48:
#line 253 "parser.y"
    { (yyval.body) = ast_new_strNode(Token_identifier, (yyvsp[(1) - (1)].identifier)); ;}
    break;

  case 49:
#line 254 "parser.y"
    { (yyval.body) = ast_new_bodyNodeN(ARRAY_IDENTIFIER, 2,
																	   		ast_new_strNode(Token_identifier, (yyvsp[(1) - (2)].identifier)),
																	   		(yyvsp[(2) - (2)].body)
																	   	);
															;}
    break;

  case 50:
#line 259 "parser.y"
    { (yyval.body) = ast_new_bodyNode(FACTOR, (yyvsp[(2) - (2)].body));;}
    break;

  case 51:
#line 260 "parser.y"
    { (yyval.body) = ast_new_bodyNode(FACTOR, (yyvsp[(2) - (2)].body)); ;}
    break;

  case 52:
#line 261 "parser.y"
    { (yyval.body) = ast_new_bodyNode(EXPR, (yyvsp[(2) - (3)].body)); ;}
    break;

  case 53:
#line 266 "parser.y"
    { (yyval.iValue) = LT; ;}
    break;

  case 54:
#line 267 "parser.y"
    { (yyval.iValue) = LE; ;}
    break;

  case 55:
#line 268 "parser.y"
    { (yyval.iValue) = GT; ;}
    break;

  case 56:
#line 269 "parser.y"
    { (yyval.iValue) = GE; ;}
    break;

  case 57:
#line 270 "parser.y"
    { (yyval.iValue) = EQ; ;}
    break;

  case 58:
#line 271 "parser.y"
    { (yyval.iValue) = NE; ;}
    break;

  case 59:
#line 276 "parser.y"
    { (yyval.iValue) = PLUS; ;}
    break;

  case 60:
#line 277 "parser.y"
    { (yyval.iValue) = MINUS; ;}
    break;

  case 61:
#line 278 "parser.y"
    { (yyval.iValue) = OR; ;}
    break;

  case 62:
#line 283 "parser.y"
    { (yyval.iValue) = MUL; ;}
    break;

  case 63:
#line 284 "parser.y"
    { (yyval.iValue) = DIV; ;}
    break;

  case 64:
#line 285 "parser.y"
    { (yyval.iValue) = DIV; ;}
    break;

  case 65:
#line 286 "parser.y"
    { (yyval.iValue) = MOD; ;}
    break;

  case 66:
#line 287 "parser.y"
    { (yyval.iValue) = AND; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1855 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 291 "parser.y"


int yyerror(const char *s) {
	errorFound = 1;
  	fprintf(stderr, "%s at line: %d\n", s, yylineno);
  	return 0;
}

int main() {
	yyparse();
	if (errorFound)
		printf("\n\nDone - Some errors occurred\n");
	else
		printf("\n\nDone - No errors\n");

	ast_nice_print(ast);
	printf("\n");

	return 0;
}
