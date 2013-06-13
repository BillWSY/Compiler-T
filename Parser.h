/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ARRAY = 258,
     TOK_BREAK = 259,
     TOK_DO = 260,
     TOK_ELSE = 261,
     TOK_END = 262,
     TOK_FOR = 263,
     TOK_FUNCTION = 264,
     TOK_IF = 265,
     TOK_IN = 266,
     TOK_LET = 267,
     TOK_NIL = 268,
     TOK_OF = 269,
     TOK_THEN = 270,
     TOK_TO = 271,
     TOK_TYPE = 272,
     TOK_VAR = 273,
     TOK_WHILE = 274,
     TOK_PLUS_SIGN = 275,
     TOK_MINUS_SIGN = 276,
     TOK_MULT_SIGN = 277,
     TOK_DIV_SIGN = 278,
     TOK_AND = 279,
     TOK_OR = 280,
     TOK_EQUALS = 281,
     TOK_NEQ = 282,
     TOK_LT = 283,
     TOK_LTE = 284,
     TOK_GT = 285,
     TOK_GTE = 286,
     TOK_ASSIGN = 287,
     TOK_SEMIC = 288,
     TOK_COMMA = 289,
     TOK_COLON = 290,
     TOK_DOT = 291,
     TOK_LBR = 292,
     TOK_RBR = 293,
     TOK_LSQB = 294,
     TOK_RSQB = 295,
     TOK_LCURLB = 296,
     TOK_RCURLB = 297,
     TOK_INTEGER = 298,
     TOK_ID = 299,
     TOK_STRING = 300,
     EXP_REDUCE_PREC = 301,
     IF_WO_ELSE_PREC = 302,
     UNIOP_PREC = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 30 "Grammar.y"

    string *strPtr;
    TInt integer;
    Expression* exp;
    Dec* dec;
    IdSqB* idSqB;
    LVal* lVal;
    ExpList* expList;
    ArgList* argList;
    FieldList* fieldList;
    FieldExpList* fieldExpList;
    DecList* decList;
    Ty* ty;
    BinOpType binOpType;
    UnOpType unOpType;


/* Line 2058 of yacc.c  */
#line 123 "Parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_H_INCLUDED  */
