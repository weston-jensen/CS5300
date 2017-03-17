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
#line 25 "parser.y" /* yacc.c:1909  */

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

#line 130 "/home/wjensen/Coding_Projects/CS5300/CS5300/parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_WJENSEN_CODING_PROJECTS_CS5300_CS5300_PARSER_HPP_INCLUDED  */
