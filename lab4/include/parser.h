/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 10 "src/parser.y"

    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"

#line 55 "include/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INTEGER = 259,                 /* INTEGER  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    BREAK = 262,                   /* BREAK  */
    CONTINUE = 263,                /* CONTINUE  */
    WHILE = 264,                   /* WHILE  */
    INT = 265,                     /* INT  */
    VOID = 266,                    /* VOID  */
    CONST = 267,                   /* CONST  */
    POUND = 268,                   /* POUND  */
    LPAREN = 269,                  /* LPAREN  */
    RPAREN = 270,                  /* RPAREN  */
    LBRACE = 271,                  /* LBRACE  */
    RBRACE = 272,                  /* RBRACE  */
    SEMICOLON = 273,               /* SEMICOLON  */
    COMMA = 274,                   /* COMMA  */
    LSQR = 275,                    /* LSQR  */
    RSQR = 276,                    /* RSQR  */
    ADD = 277,                     /* ADD  */
    SUB = 278,                     /* SUB  */
    DIV = 279,                     /* DIV  */
    MUL = 280,                     /* MUL  */
    MOD = 281,                     /* MOD  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    NOT = 284,                     /* NOT  */
    LESS = 285,                    /* LESS  */
    MORE = 286,                    /* MORE  */
    ASSIGN = 287,                  /* ASSIGN  */
    PLUSASSIGN = 288,              /* PLUSASSIGN  */
    MINUSASSIGN = 289,             /* MINUSASSIGN  */
    MULASSIGN = 290,               /* MULASSIGN  */
    DIVASSIGN = 291,               /* DIVASSIGN  */
    EQU = 292,                     /* EQU  */
    GEQ = 293,                     /* GEQ  */
    LEQ = 294,                     /* LEQ  */
    NEQ = 295,                     /* NEQ  */
    RETURN = 296,                  /* RETURN  */
    LINECOMMENTBEGIN = 297,        /* LINECOMMENTBEGIN  */
    LINECOMMENTELEMENT = 298,      /* LINECOMMENTELEMENT  */
    LINECOMMENTEND = 299,          /* LINECOMMENTEND  */
    COMMENTBEIGN = 300,            /* COMMENTBEIGN  */
    COMMENTELEMENT = 301,          /* COMMENTELEMENT  */
    COMMENTEND = 302,              /* COMMENTEND  */
    THEN = 303                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "src/parser.y"

    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
    IdQueue* idqueuetype;
    FuncFParams* Fstype;
    FuncRParams* FRtype;
    ConstIdQueue* constidtype;

#line 132 "include/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_PARSER_H_INCLUDED  */
