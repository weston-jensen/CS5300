/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "Expressions.hpp"
#include "symbol_table.hpp"
#include "Constant.hpp"
#include "Type.hpp"
#include "Array_Type.hpp"
#include "TreeParser.hpp"
#include <algorithm>

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>


extern int num_lines;
extern void yyerror(const char *str);
extern int yylex();
extern int yylineno;
extern char* yytext;

#line 89 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_HOME_WJENSEN_CODING_PROJECTS_CS5300_CS5300_PARSER_HPP_INCLUDED
# define YY_YY_HOME_WJENSEN_CODING_PROJECTS_CS5300_CS5300_PARSER_HPP_INCLUDED
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
    ARRAY_SYM = 258,
    ASSIGN_SYM = 259,
    BEGIN_SYM = 260,
    CHAR_SYM = 261,
    CHR_SYM = 262,
    COLON_SYM = 263,
    COMMA_SYM = 264,
    CONST_SYM = 265,
    DIV_SYM = 266,
    DO_SYM = 267,
    DOT_SYM = 268,
    DOWNTO_SYM = 269,
    ELSEIF_SYM = 270,
    ELSE_SYM = 271,
    END_SYM = 272,
    EQ_SYM = 273,
    FOR_SYM = 274,
    FORWARD_SYM = 275,
    FUNCTION_SYM = 276,
    GTE_SYM = 277,
    GT_SYM = 278,
    IDENT_SYM = 279,
    IF_SYM = 280,
    INT_SYM = 281,
    LBRACKET_SYM = 282,
    LPAREN_SYM = 283,
    LTE_SYM = 284,
    LT_SYM = 285,
    MINUS_SYM = 286,
    MOD_SYM = 287,
    MULT_SYM = 288,
    NOT_SYM = 289,
    OF_SYM = 290,
    ORD_SYM = 291,
    PLUS_SYM = 292,
    PRED_SYM = 293,
    PROCEDURE_SYM = 294,
    RBRACKET_SYM = 295,
    READ_SYM = 296,
    RECORD_SYM = 297,
    REF_SYM = 298,
    REPEAT_SYM = 299,
    RETURN_SYM = 300,
    RPAREN_SYM = 301,
    SEMICOLON_SYM = 302,
    STOP_SYM = 303,
    STRING_SYM = 304,
    SUCC_SYM = 305,
    THEN_SYM = 306,
    TO_SYM = 307,
    TYPE_SYM = 308,
    UNTIL_SYM = 309,
    VAR_SYM = 310,
    WHILE_SYM = 311,
    WRITE_SYM = 312,
    AND_SYM = 313,
    OR_SYM = 314,
    NEQ_SYM = 315,
    UMINUS_SYM = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 25 "parser.y" /* yacc.c:355  */

  int intVal;
  char *strVal;
  std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>> *typeList;
  std::vector<std::string> *identList;
  std::vector<Expression> *exprList;
  Type *typeVal;
  Array_Type *arrVal;
  Record *recVal;
  Constant *constVal;
  Expression *expr;
  void *none;

#line 205 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_WJENSEN_CODING_PROJECTS_CS5300_CS5300_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   669

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   133,   136,   137,   144,   149,   152,   153,
     154,   157,   158,   161,   162,   165,   166,   169,   170,   173,
     176,   177,   178,   182,   185,   186,   193,   194,   201,   208,
     209,   212,   213,   216,   217,   218,   221,   224,   227,   228,
     235,   238,   247,   250,   258,   259,   275,   276,   294,   297,
     298,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   314,   321,   327,   333,   340,   341,   347,
     353,   359,   360,   366,   371,   377,   383,   389,   396,   399,
     406,   407,   410,   418,   425,   432,   439,   457,   460,   461,
     465,   473,   474,   481,   490,   494,   502,   505,   506,   509,
     510,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   563,   566,   576,   577,
     584,   592
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY_SYM", "ASSIGN_SYM", "BEGIN_SYM",
  "CHAR_SYM", "CHR_SYM", "COLON_SYM", "COMMA_SYM", "CONST_SYM", "DIV_SYM",
  "DO_SYM", "DOT_SYM", "DOWNTO_SYM", "ELSEIF_SYM", "ELSE_SYM", "END_SYM",
  "EQ_SYM", "FOR_SYM", "FORWARD_SYM", "FUNCTION_SYM", "GTE_SYM", "GT_SYM",
  "IDENT_SYM", "IF_SYM", "INT_SYM", "LBRACKET_SYM", "LPAREN_SYM",
  "LTE_SYM", "LT_SYM", "MINUS_SYM", "MOD_SYM", "MULT_SYM", "NOT_SYM",
  "OF_SYM", "ORD_SYM", "PLUS_SYM", "PRED_SYM", "PROCEDURE_SYM",
  "RBRACKET_SYM", "READ_SYM", "RECORD_SYM", "REF_SYM", "REPEAT_SYM",
  "RETURN_SYM", "RPAREN_SYM", "SEMICOLON_SYM", "STOP_SYM", "STRING_SYM",
  "SUCC_SYM", "THEN_SYM", "TO_SYM", "TYPE_SYM", "UNTIL_SYM", "VAR_SYM",
  "WHILE_SYM", "WRITE_SYM", "AND_SYM", "OR_SYM", "NEQ_SYM", "UMINUS_SYM",
  "$accept", "Program", "ProgramStart", "ConstDecl", "ConstDecls",
  "Optional_ProcOrFuncDecls", "ProcedureDecl", "FunctionDecl",
  "Optional_FormalParameters", "FormalParameters", "FormalParameter",
  "Optional_Var", "Body", "Optional_ConstDecl", "Optional_ConstDecls",
  "Block", "TypeDecl", "TypeDecls", "Type", "SimpleType", "RecordType",
  "RecordTypeDecls", "ArrayType", "IdentList", "IdentLists", "VarDecl",
  "VarDecls", "StatementSequence", "StatementSequences", "Statement",
  "Assignment", "IfStatement", "IfHead", "IfBegin", "ElseIfList",
  "ElseIfHead", "ElseBegin", "ElseClause", "ElseStart", "WhileStatement",
  "WhileBegin", "WhileHead", "RepeatStatement", "RepeatStatementMiddle",
  "RepeatStatementBegin", "ForStatement", "ForInc", "ForIncGuts", "ForDec",
  "ForDecGuts", "ForBegin", "StopStatement", "ReturnStatement",
  "ReadStatement", "ReadArgs", "WriteStatement", "WriteArgs",
  "ProcedureCall", "Optional_Arguments", "Arguments", "Expression",
  "ConstExpression", "FunctionCall", "LValue", "LValues", "NullStatement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -226

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-226)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-97)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,  -226,    18,    21,   -21,    11,  -226,  -226,    27,  -226,
     -13,    25,    64,   175,  -226,    59,  -226,  -226,   149,  -226,
    -226,    61,    93,    66,   619,  -226,   619,   619,   619,    90,
      94,    95,  -226,   619,  -226,  -226,    96,  -226,   101,    83,
    -226,  -226,  -226,    82,  -226,   619,   122,  -226,    81,  -226,
    -226,  -226,   126,  -226,   129,     5,  -226,  -226,  -226,  -226,
    -226,   553,  -226,   144,  -226,   132,  -226,    57,  -226,  -226,
    -226,   149,   149,   149,  -226,   249,   619,   155,   143,   619,
     619,  -226,   138,   553,  -226,   281,  -226,    16,   619,   619,
    -226,   553,   619,  -226,  -226,    -5,  -226,   553,  -226,   619,
    -226,  -226,  -226,   619,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   619,    12,
     161,   146,   147,   148,  -226,  -226,   313,  -226,   577,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   154,
     149,   149,   149,   345,   619,     3,   377,   133,   176,   553,
     619,  -226,   401,   433,   162,   465,   619,  -226,  -226,   136,
     619,   171,  -226,  -226,   178,   553,   179,   180,   553,   553,
      68,    97,    97,    97,    97,    97,   114,    68,    68,   114,
      16,    16,    97,   553,   165,  -226,  -226,   157,  -226,  -226,
    -226,    12,   184,   174,   177,  -226,   235,    97,    97,    97,
      97,    97,   606,   235,   235,   606,   577,   577,    97,  -226,
     553,  -226,     3,    -3,   619,   166,  -226,  -226,     3,    22,
    -226,   217,  -226,   553,  -226,  -226,  -226,  -226,  -226,   149,
     190,   191,   167,  -226,   -18,   -18,  -226,   553,  -226,  -226,
    -226,  -226,  -226,  -226,   131,  -226,   200,   194,  -226,  -226,
     181,   182,  -226,  -226,   187,   149,    12,   213,   -22,   214,
     183,   497,   189,    12,  -226,    12,    67,   199,  -226,   195,
    -226,  -226,   196,   197,   -21,    12,   111,   221,  -226,  -226,
     -13,  -226,   204,   205,   219,    21,  -226,  -226,   149,  -226,
     521,   231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     7,     0,     0,    29,     0,     1,    49,     0,    31,
      44,     0,     0,   151,     2,     0,    46,    10,     0,    28,
     116,     0,     0,   148,     0,   115,     0,     0,     0,     0,
       0,     0,    79,    89,    87,   117,     0,    75,     0,    48,
      51,    52,    67,     0,    53,     0,     0,    54,     0,    49,
      55,    80,     0,    81,     0,     0,    56,    57,    58,    59,
      60,    61,   118,   101,    62,     0,    42,     3,   127,   129,
     126,     0,     0,     0,   128,     0,     0,     0,     0,     0,
      98,   147,   148,    66,   101,     0,   120,   121,     0,     0,
      91,    88,     0,    94,    50,    71,    49,    76,    49,     0,
      78,    49,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,     0,   145,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,   148,     0,     0,    97,   100,
      98,   119,     0,     0,     0,     0,     0,    70,    73,     0,
       0,     0,    49,    65,     0,    77,     0,     0,    85,    83,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   114,
     102,   113,   112,    63,     0,    36,    38,     0,    33,    34,
      35,     0,    41,     0,     0,   143,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   142,   130,   141,   140,   125,
      86,   149,   148,   146,     0,     0,   122,   123,   148,     0,
     124,     0,    49,    69,    64,    72,    74,    82,    84,     0,
      42,    30,     0,    43,    16,    16,   150,    99,   146,    92,
      90,    95,    93,    68,     0,    37,     0,    45,    21,    20,
       0,    15,    17,    42,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,    18,     0,    24,     0,    39,     0,
      19,    26,     0,     0,    29,     0,    24,     0,    11,    12,
      44,    40,     0,     0,     0,     0,    13,    14,     0,    23,
       0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,     6,  -226,
     -20,  -226,   -17,  -226,  -226,   -29,   -12,  -226,  -183,  -226,
    -226,  -226,  -226,  -225,  -226,   -19,  -226,   -46,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,   116,  -226,
      -4,   -71,  -226,    -9,  -138,  -226
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    67,   124,   125,   250,   251,
     252,   253,   273,   274,   277,     8,    10,    15,   187,   188,
     189,   230,   190,   120,   121,    17,    66,    12,    13,    39,
      40,    41,    42,    43,    95,   159,   160,   161,   162,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   154,    59,   156,    60,   147,   148,
     149,    75,    62,    84,    81,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     126,   127,   128,   100,    63,   246,   -22,   211,   232,    61,
     157,   158,   -96,   -96,   -96,   184,    78,     1,     6,   103,
      83,   248,    85,    86,    87,   248,     7,   105,   259,    91,
      79,   239,     9,   249,   106,    11,   185,   249,   107,   108,
      14,    97,    16,    18,   -96,   109,   110,   111,   112,   113,
     163,   -96,   164,   114,   186,   166,   167,   104,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   240,   206,
     207,   208,   143,   262,   236,   146,   117,   271,   122,    78,
     269,    19,   270,    65,   152,   153,   106,   272,   155,    76,
     107,   108,   281,    79,    80,   165,   123,   109,   110,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   -97,   225,    77,    88,   -97,
     -97,   271,    89,    90,    92,   105,   -97,   -97,   117,    93,
      94,   282,   106,    96,    98,    99,   107,   108,   101,   255,
     210,   102,   129,   109,   110,   219,   112,   113,   118,   130,
     119,    78,   221,   131,   132,    68,   223,   -97,   244,   144,
     133,   134,   135,   136,   137,    79,   150,   145,   138,   191,
     192,   193,   194,    69,   117,    70,   243,    71,    -6,   213,
      72,    20,    21,    73,   261,   214,   218,   222,   224,   140,
     141,   142,   229,   233,    22,   226,   227,   228,    74,    23,
      24,    25,   234,    26,   231,   235,    27,   245,   256,    28,
     237,    29,   238,    30,   247,   -32,    31,   290,   -47,    32,
      33,   263,   265,    34,    35,    36,   241,   257,   105,   258,
     266,    37,    38,   260,   275,   106,   268,   288,   264,   107,
     108,   254,   276,   278,   279,   284,   109,   110,   111,   112,
     113,   286,   287,   130,   114,   -27,   289,   131,   132,   283,
     129,   285,   280,   242,   133,   134,   215,   130,     0,     0,
       0,   131,   132,     0,     0,   115,   116,   117,   133,   134,
     135,   136,   137,     0,     0,     0,   138,     0,     0,     0,
       0,     0,   105,     0,     0,   142,   139,     0,     0,   106,
       0,     0,     0,   107,   108,     0,     0,   140,   141,   142,
     109,   110,   111,   112,   113,     0,     0,     0,   114,     0,
       0,     0,     0,     0,   129,     0,     0,   151,     0,     0,
       0,   130,     0,     0,     0,   131,   132,     0,     0,   115,
     116,   117,   133,   134,   135,   136,   137,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   105,     0,     0,   195,
       0,     0,     0,   106,     0,     0,     0,   107,   108,     0,
       0,   140,   141,   142,   109,   110,   111,   112,   113,     0,
       0,     0,   114,     0,     0,     0,     0,     0,   105,     0,
       0,   209,     0,     0,     0,   106,     0,     0,     0,   107,
     108,     0,     0,   115,   116,   117,   109,   110,   111,   112,
     113,     0,   105,     0,   114,     0,     0,   212,     0,   106,
       0,     0,     0,   107,   108,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   115,   116,   117,   114,     0,
       0,     0,     0,     0,   105,     0,     0,   216,     0,     0,
       0,   106,     0,     0,     0,   107,   108,     0,     0,   115,
     116,   117,   109,   110,   111,   112,   113,     0,     0,     0,
     114,     0,     0,     0,     0,     0,   105,     0,     0,   217,
       0,     0,     0,   106,     0,     0,     0,   107,   108,     0,
       0,   115,   116,   117,   109,   110,   111,   112,   113,     0,
       0,     0,   114,     0,     0,     0,     0,     0,   129,     0,
       0,   220,     0,     0,     0,   130,     0,     0,     0,   131,
     132,     0,     0,   115,   116,   117,   133,   134,   135,   136,
     137,     0,   129,     0,   138,     0,     0,   267,     0,   130,
       0,     0,     0,   131,   132,     0,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   140,   141,   142,   138,     0,
       0,     0,     0,     0,   105,     0,     0,     0,   291,     0,
       0,   106,     0,     0,     0,   107,   108,     0,     0,   140,
     141,   142,   109,   110,   111,   112,   113,     0,   129,     0,
     114,     0,     0,     0,     0,   130,     0,     0,     0,   131,
     132,     0,     0,     0,     0,     0,   133,   134,   135,   136,
     137,   115,   116,   117,   138,     0,     0,   129,     0,     0,
       0,     0,     0,     0,   130,    20,    21,     0,   131,   132,
       0,     0,     0,     0,     0,   133,   134,   142,   136,   137,
       0,     0,     0,    82,     0,    25,     0,    26,     0,     0,
      27,     0,     0,    28,     0,    29,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,    35,    36
};

static const yytype_int16 yycheck[] =
{
      71,    72,    73,    49,    13,   230,    24,   145,   191,    13,
      15,    16,    15,    16,    17,     3,    13,    10,     0,    14,
      24,    43,    26,    27,    28,    43,     5,    11,   253,    33,
      27,     9,    53,    55,    18,    24,    24,    55,    22,    23,
      13,    45,    55,    18,    47,    29,    30,    31,    32,    33,
      96,    54,    98,    37,    42,   101,   102,    52,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    46,   140,
     141,   142,    76,   256,   212,    79,    60,    10,    21,    13,
     263,    17,   265,    24,    88,    89,    18,    20,    92,    28,
      22,    23,   275,    27,    28,    99,    39,    29,    30,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    18,   162,    24,    28,    22,
      23,    10,    28,    28,    28,    11,    29,    30,    60,    28,
      47,    20,    18,    51,    12,    54,    22,    23,    12,     8,
     144,    12,    11,    29,    30,   154,    32,    33,     4,    18,
      18,    13,   156,    22,    23,     6,   160,    60,   229,     4,
      29,    30,    31,    32,    33,    27,    28,    24,    37,     8,
      24,    24,    24,    24,    60,    26,   222,    28,    24,    46,
      31,     6,     7,    34,   255,     9,    24,    51,    17,    58,
      59,    60,    27,     9,    19,    17,    17,    17,    49,    24,
      25,    26,    28,    28,    47,    28,    31,    17,     8,    34,
     214,    36,    46,    38,    47,    24,    41,   288,    24,    44,
      45,     8,     8,    48,    49,    50,     9,    46,    11,    47,
      47,    56,    57,    46,    35,    18,    47,    18,   258,    22,
      23,   235,    47,    47,    47,    24,    29,    30,    31,    32,
      33,    47,    47,    18,    37,    24,   285,    22,    23,   276,
      11,   280,   274,    46,    29,    30,   150,    18,    -1,    -1,
      -1,    22,    23,    -1,    -1,    58,    59,    60,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    60,    47,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    -1,    -1,    58,    59,    60,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    46,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,    58,
      59,    60,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    46,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    -1,
      -1,    58,    59,    60,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    46,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    -1,    -1,    58,    59,    60,    29,    30,    31,    32,
      33,    -1,    11,    -1,    37,    -1,    -1,    40,    -1,    18,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    58,    59,    60,    37,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    46,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,    58,
      59,    60,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    46,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    -1,
      -1,    58,    59,    60,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    46,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    -1,    -1,    58,    59,    60,    29,    30,    31,    32,
      33,    -1,    11,    -1,    37,    -1,    -1,    40,    -1,    18,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    58,    59,    60,    37,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    47,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    -1,    -1,    58,
      59,    60,    29,    30,    31,    32,    33,    -1,    11,    -1,
      37,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    58,    59,    60,    37,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,     6,     7,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    60,    32,    33,
      -1,    -1,    -1,    24,    -1,    26,    -1,    28,    -1,    -1,
      31,    -1,    -1,    34,    -1,    36,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    63,    64,    65,    66,     0,     5,    77,    53,
      78,    24,    89,    90,    13,    79,    55,    87,    18,    17,
       6,     7,    19,    24,    25,    26,    28,    31,    34,    36,
      38,    41,    44,    45,    48,    49,    50,    56,    57,    91,
      92,    93,    94,    95,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   117,
     119,   122,   124,   125,   127,    24,    88,    67,     6,    24,
      26,    28,    31,    34,    49,   123,    28,    24,    13,    27,
      28,   126,    24,   122,   125,   122,   122,   122,    28,    28,
      28,   122,    28,    28,    47,    96,    51,   122,    12,    54,
      89,    12,    12,    14,    52,    11,    18,    22,    23,    29,
      30,    31,    32,    33,    37,    58,    59,    60,     4,    18,
      85,    86,    21,    39,    68,    69,   123,   123,   123,    11,
      18,    22,    23,    29,    30,    31,    32,    33,    37,    47,
      58,    59,    60,   122,     4,    24,   122,   120,   121,   122,
      28,    46,   122,   122,   116,   122,   118,    15,    16,    97,
      98,    99,   100,    89,    89,   122,    89,    89,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,     3,    24,    42,    80,    81,    82,
      84,     8,    24,    24,    24,    46,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,    46,
     122,   126,    40,    46,     9,   120,    46,    46,    24,   125,
      46,   122,    51,   122,    17,    89,    17,    17,    17,    27,
      83,    47,    80,     9,    28,    28,   126,   122,    46,     9,
      46,     9,    46,    89,   123,    17,    85,    47,    43,    55,
      70,    71,    72,    73,    70,     8,     8,    46,    47,    85,
      46,   123,    80,     8,    72,     8,    47,    40,    47,    80,
      80,    10,    20,    74,    75,    35,    47,    76,    47,    47,
      78,    80,    20,    74,    24,    87,    47,    47,    18,    77,
     123,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    73,    74,    75,    75,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    80,    81,    82,    83,    83,
      84,    85,    86,    86,    87,    87,    88,    88,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    93,    94,    95,    96,    96,    97,
      98,    99,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   107,   108,   109,   110,   111,   112,   113,   114,   114,
     115,   116,   116,   117,   118,   118,   119,   120,   120,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   125,   126,   126,
     126,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     0,     6,     5,     0,     2,     2,
       0,     8,     8,    10,    10,     1,     0,     1,     3,     4,
       1,     1,     0,     4,     0,     6,     0,     5,     3,     0,
       6,     0,     5,     1,     1,     1,     1,     3,     0,     5,
       8,     2,     0,     3,     0,     6,     0,     5,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     0,     4,     2,
       1,     0,     2,     1,     4,     1,     2,     3,     2,     1,
       1,     1,     4,     3,     4,     3,     4,     1,     2,     1,
       5,     0,     3,     5,     0,     3,     4,     1,     0,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     3,
       2,     2,     4,     4,     4,     4,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     2,     0,     3,
       4,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 125 "parser.y" /* yacc.c:1646  */
    {
			std::cout<<"in parser.y"<<std::endl;
			SymbolTable::getInstance()->popScope();
			SymbolTable::getInstance()->popScope();
			SymbolTable::getInstance()->emitEnd();
		}
#line 1602 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 133 "parser.y" /* yacc.c:1646  */
    { ProgramStart();}
#line 1608 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "parser.y" /* yacc.c:1646  */
    {
			(yyvsp[-1].constVal)->name = (yyvsp[-3].strVal);
			SymbolTable::getInstance()->addSymbol((yyvsp[-3].strVal),*(yyvsp[-1].constVal),true);
		  }
#line 1617 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 145 "parser.y" /* yacc.c:1646  */
    {
				(yyvsp[-1].constVal)->name = (yyvsp[-3].strVal);
				SymbolTable::getInstance()->addSymbol((yyvsp[-3].strVal),*(yyvsp[-1].constVal),true);
		   }
#line 1626 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 157 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1632 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1638 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1644 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1650 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "parser.y" /* yacc.c:1646  */
    {std::cout<<"optinal formal params\n";}
#line 1656 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 166 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1662 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1668 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 170 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1674 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 173 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1680 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1686 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1692 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 1698 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 187 "parser.y" /* yacc.c:1646  */
    {
						(yyvsp[-1].constVal)->name=(yyvsp[-3].strVal);
						SymbolTable::getInstance()->addSymbol((yyvsp[-3].strVal), *(yyvsp[-1].constVal), true);
				   }
#line 1707 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 195 "parser.y" /* yacc.c:1646  */
    {
						(yyvsp[-1].constVal)->name=(yyvsp[-3].strVal);
						SymbolTable::getInstance()->addSymbol((yyvsp[-3].strVal), *(yyvsp[-1].constVal), true);
					}
#line 1716 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "parser.y" /* yacc.c:1646  */
    { TypeDeclaration((yyvsp[-3].strVal), (yyvsp[-1].typeVal));	}
#line 1722 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 213 "parser.y" /* yacc.c:1646  */
    {TypeDeclaration((yyvsp[-3].strVal), (yyvsp[-1].typeVal));}
#line 1728 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.typeVal)=(yyvsp[0].typeVal);}
#line 1734 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 217 "parser.y" /* yacc.c:1646  */
    { addRecord((yyvsp[0].recVal)); (yyval.recVal)=(yyvsp[0].recVal);}
#line 1740 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 218 "parser.y" /* yacc.c:1646  */
    { addArray_Type((yyvsp[0].arrVal)); (yyval.arrVal)=(yyvsp[0].arrVal);}
#line 1746 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.typeVal) = newSimpleType((yyvsp[0].strVal));}
#line 1752 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.recVal) = new Record(*(yyvsp[-1].typeList));}
#line 1758 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 227 "parser.y" /* yacc.c:1646  */
    {  (yyval.typeList)=new std::vector<std::pair<std::vector<std::string>, std::shared_ptr<Type>>>();}
#line 1764 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 229 "parser.y" /* yacc.c:1646  */
    {
					(yyvsp[-4].typeList)->push_back(std::make_pair(*(yyvsp[-3].identList), std::make_shared<Type>(*(yyvsp[-1].typeVal))));
					(yyval.typeList)=(yyvsp[-4].typeList);
				}
#line 1773 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 235 "parser.y" /* yacc.c:1646  */
    {(yyval.arrVal) = new Array_Type((yyvsp[0].typeVal), *(yyvsp[-5].constVal), *(yyvsp[-3].constVal));}
#line 1779 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 239 "parser.y" /* yacc.c:1646  */
    {
			std::cout<<"ident list"<<std::endl;
			(yyvsp[-1].identList)->push_back((yyvsp[0].strVal));
			(yyval.identList)=(yyvsp[-1].identList);
		  }
#line 1789 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 247 "parser.y" /* yacc.c:1646  */
    {
			 (yyval.identList) = new std::vector<std::string>();
		   }
#line 1797 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 251 "parser.y" /* yacc.c:1646  */
    {
		    std::cout<<"ident lists"<<std::endl;
			(yyvsp[-2].identList)->push_back((yyvsp[-1].strVal));
			(yyval.identList)=(yyvsp[-2].identList);
		   }
#line 1807 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 260 "parser.y" /* yacc.c:1646  */
    {
			std::cout<<"found a var"<<std::endl;
			std::for_each((yyvsp[-3].identList)->begin(), (yyvsp[-3].identList)->end(), [&](std::string val)
			{
				if(!SymbolTable::getInstance()->lookup((yyvsp[-1].typeVal)->name))
				{
					VariableDeclaration((yyvsp[-3].identList), (yyvsp[-1].typeVal), val);
				}
				Var var(*(yyvsp[-1].typeVal), SymbolTable::getInstance()->offset.back(), val);
				SymbolTable::getInstance()->offset.back()+=(yyvsp[-1].typeVal)->size;
				SymbolTable::getInstance()->addSymbol(val, var, true);
			});
		}
#line 1825 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 276 "parser.y" /* yacc.c:1646  */
    {
			std::cout<<"Found Var"<<std::endl;
			std::for_each((yyvsp[-3].identList)->begin(), (yyvsp[-3].identList)->end(),[&](std::string val)
			{
				MoreVariableDeclarations((yyvsp[-1].typeVal), val);
			});
	     }
#line 1837 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 300 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1843 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 301 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1849 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 302 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1855 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 303 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1861 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 304 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1867 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 305 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1873 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 306 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1879 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 307 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1885 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 308 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1891 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 309 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1897 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1903 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 311 "parser.y" /* yacc.c:1646  */
    { SymbolTable::getInstance()->clearReg();}
#line 1909 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 315 "parser.y" /* yacc.c:1646  */
    {
		     create((yyvsp[-2].expr), (yyvsp[0].expr));
			 std::cout<<"after Assignment create()"<<std::endl;
		   }
#line 1918 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 322 "parser.y" /* yacc.c:1646  */
    {
			   endIf();
			}
#line 1926 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 328 "parser.y" /* yacc.c:1646  */
    {
      	   ifBranchEnd();
	   }
#line 1934 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 334 "parser.y" /* yacc.c:1646  */
    {
		   ifBegin();
		   ifBranch((yyvsp[0].expr));
		}
#line 1943 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 342 "parser.y" /* yacc.c:1646  */
    {
		      ifBranchEnd();
		   }
#line 1951 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 348 "parser.y" /* yacc.c:1646  */
    {
		      ifBranch((yyvsp[0].expr));
		   }
#line 1959 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 354 "parser.y" /* yacc.c:1646  */
    {
		     labelIfBranch();
		  }
#line 1967 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 361 "parser.y" /* yacc.c:1646  */
    {
		      ifBranchEnd();
		   }
#line 1975 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 367 "parser.y" /* yacc.c:1646  */
    {
			labelIfBranch();
		  }
#line 1983 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 372 "parser.y" /* yacc.c:1646  */
    {
			      loopEnd();
			   }
#line 1991 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 378 "parser.y" /* yacc.c:1646  */
    {
		      loopBegin();
		   }
#line 1999 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 384 "parser.y" /* yacc.c:1646  */
    {
		     whileStmt((yyvsp[0].expr),true);
		  }
#line 2007 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 390 "parser.y" /* yacc.c:1646  */
    {
				   std::cout<<"RepeatStatement ending"<<std::endl;
				   repeatStmt((yyvsp[0].expr));
				}
#line 2016 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 400 "parser.y" /* yacc.c:1646  */
    {
						std::cout<<"RepeatStatementBegin"<<std::endl;
					    loopBegin();
					 }
#line 2025 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 411 "parser.y" /* yacc.c:1646  */
    {
	      create((yyvsp[-3].expr), AddExpr((yyvsp[-3].expr),(new Expression(1,Expression::intType,true))));
	      loopEnd();
	   }
#line 2034 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 419 "parser.y" /* yacc.c:1646  */
    {
		     forStmt(GtExpr((yyvsp[-2].expr),(yyvsp[0].expr)));
		     (yyval.expr) = (yyvsp[-2].expr);
		   }
#line 2043 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 426 "parser.y" /* yacc.c:1646  */
    {
	      create((yyvsp[-3].expr), SubExpr((yyvsp[-3].expr),(new Expression(1, Expression::intType,true))));
	      loopEnd();
	   }
#line 2052 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 433 "parser.y" /* yacc.c:1646  */
    {
		     forStmt(LtExpr((yyvsp[-2].expr),(yyvsp[0].expr)));
		     (yyval.expr) = (yyvsp[-2].expr);
		   }
#line 2061 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 440 "parser.y" /* yacc.c:1646  */
    {
		    auto newExpr = new Expression(std::string((yyvsp[-2].strVal)),Expression::stringType);
			auto newExprVec = new std::vector<Expression>();
			
			newExprVec->push_back(*newExpr);
			auto temp = genLValue(*newExprVec);
			
			create(temp,(yyvsp[0].expr));
			loopBegin();
			(yyval.expr) = temp;
		 }
#line 2077 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 457 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2083 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 460 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2089 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 466 "parser.y" /* yacc.c:1646  */
    {
			    std::cout<<"finished read statement"<<std::endl;
				(yyvsp[-2].exprList)->push_back(*(yyvsp[-1].expr));
				readStmt(*(yyvsp[-2].exprList));
			  }
#line 2099 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 473 "parser.y" /* yacc.c:1646  */
    {(yyval.exprList) = new std::vector<Expression>();}
#line 2105 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 475 "parser.y" /* yacc.c:1646  */
    {
			(yyvsp[-2].exprList)->push_back(*(yyvsp[-1].expr));
			(yyval.exprList) = (yyvsp[-2].exprList);
		 }
#line 2114 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 482 "parser.y" /* yacc.c:1646  */
    {
				  std::cout<<"finished write statement"<<std::endl;
			      (yyvsp[-2].exprList)->push_back(*(yyvsp[-1].expr));
				  writeStmt(*(yyvsp[-2].exprList));
			   }
#line 2124 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 490 "parser.y" /* yacc.c:1646  */
    {
			 std::cout<<"WriteArgs, new vector"<<std::endl;
		     (yyval.exprList) = new std::vector<Expression>();
		  }
#line 2133 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 495 "parser.y" /* yacc.c:1646  */
    {
			 std::cout<<"WriteArgs, pushing another back"<<std::endl;
			 (yyvsp[-2].exprList)->push_back(*(yyvsp[-1].expr));
			 (yyval.exprList) = (yyvsp[-2].exprList);
		  }
#line 2143 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 502 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2149 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 505 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2155 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 506 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2161 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 509 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2167 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 510 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2173 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 513 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 2179 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 514 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = AndExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2185 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 515 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = DivExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2191 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 516 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = EqExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2197 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 517 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = GteExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2203 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 518 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = GtExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2209 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 519 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = LteExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2215 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 520 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = LtExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2221 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 521 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = SubExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2227 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 522 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = ModExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2233 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 523 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = MultExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2239 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 524 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = NeqExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2245 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 525 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = OrExpr((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2251 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 526 "parser.y" /* yacc.c:1646  */
    {{(yyval.expr) = AddExpr((yyvsp[-2].expr),(yyvsp[0].expr));}std::cout<<"after PlusExpression"<<std::endl;}
#line 2257 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 527 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = IntExpr((yyvsp[0].intVal));}
#line 2263 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 528 "parser.y" /* yacc.c:1646  */
    {{(yyval.expr) = CharExpr((yyvsp[0].strVal));}std::cout<<"after charexpr"<<std::endl;}
#line 2269 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 529 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = StrExpr((yyvsp[0].strVal));}
#line 2275 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 530 "parser.y" /* yacc.c:1646  */
    {}
#line 2281 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 531 "parser.y" /* yacc.c:1646  */
    {{std::cout<<"( exp )"<<std::endl;}(yyval.expr)=(yyvsp[-1].expr);}
#line 2287 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 532 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2293 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 533 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2299 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 541 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = new Constant((yyvsp[0].intVal));}
#line 2305 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 542 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = new Constant((yyvsp[0].strVal)[1]);}
#line 2311 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 543 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = new Constant(std::string((yyvsp[0].strVal)),std::string((yyvsp[0].strVal)));}
#line 2317 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 544 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = new Constant(std::string((yyvsp[0].strVal)),Constant::identType);}
#line 2323 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 545 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstAndExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2329 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 546 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstDivExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2335 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 547 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstEqExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2341 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 548 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstGteExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2347 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 549 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstGtExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2353 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 550 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstLteExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2359 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 551 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstLtExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2365 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 552 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstSubExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2371 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 553 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstModExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2377 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 554 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstMultExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2383 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 555 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstNeqExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2389 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 556 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstOrExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2395 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 557 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstAddExpr(*(yyvsp[-2].constVal),*(yyvsp[0].constVal));}
#line 2401 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 558 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = (yyvsp[-1].constVal);}
#line 2407 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 559 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstNotExpr(*(yyvsp[0].constVal));}
#line 2413 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 560 "parser.y" /* yacc.c:1646  */
    {(yyval.constVal) = ConstUminusExpr(*(yyvsp[0].constVal));}
#line 2419 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 563 "parser.y" /* yacc.c:1646  */
    {std::cout<<"Empty"<<std::endl;}
#line 2425 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 567 "parser.y" /* yacc.c:1646  */
    {
		  std::cout<<"***LValue"<<std::endl;
	      auto temp = new Expression(std::string((yyvsp[-1].strVal)), Expression::stringType);
		  (yyvsp[0].exprList)->push_back(*temp);
		  std::reverse((yyvsp[0].exprList)->begin(), (yyvsp[0].exprList)->end());
		  (yyval.expr) = genLValue(*(yyvsp[0].exprList));
	   }
#line 2437 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 576 "parser.y" /* yacc.c:1646  */
    {(yyval.exprList) = new std::vector<Expression>();}
#line 2443 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 578 "parser.y" /* yacc.c:1646  */
    {
			std::cout<<"LValues"<<std::endl;
			auto temp = new Expression(std::string((yyvsp[-1].strVal)), Expression::stringType);
			(yyvsp[0].exprList)->push_back(*temp);
			(yyval.exprList) = (yyvsp[0].exprList);
		}
#line 2454 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 585 "parser.y" /* yacc.c:1646  */
    {
			std::cout<<"LValues"<<std::endl;
			(yyvsp[0].exprList)->push_back(*(yyvsp[-2].expr));
			(yyval.exprList)=(yyvsp[0].exprList);
		}
#line 2464 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
    break;


#line 2468 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 594 "parser.y" /* yacc.c:1906  */


void yyerror(const char* msg)
{
	std::cout<<"ERROR! "<< msg << " "<<num_lines<<std::endl;
}




