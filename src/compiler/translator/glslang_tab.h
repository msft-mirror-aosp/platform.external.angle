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

#ifndef YY_YY_GLSLANG_TAB_H_INCLUDED
# define YY_YY_GLSLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */


#define YYLTYPE TSourceLoc
#define YYLTYPE_IS_DECLARED 1



/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INVARIANT = 258,
    HIGH_PRECISION = 259,
    MEDIUM_PRECISION = 260,
    LOW_PRECISION = 261,
    PRECISION = 262,
    ATTRIBUTE = 263,
    CONST_QUAL = 264,
    BOOL_TYPE = 265,
    FLOAT_TYPE = 266,
    INT_TYPE = 267,
    UINT_TYPE = 268,
    BREAK = 269,
    CONTINUE = 270,
    DO = 271,
    ELSE = 272,
    FOR = 273,
    IF = 274,
    DISCARD = 275,
    RETURN = 276,
    SWITCH = 277,
    CASE = 278,
    DEFAULT = 279,
    BVEC2 = 280,
    BVEC3 = 281,
    BVEC4 = 282,
    IVEC2 = 283,
    IVEC3 = 284,
    IVEC4 = 285,
    VEC2 = 286,
    VEC3 = 287,
    VEC4 = 288,
    UVEC2 = 289,
    UVEC3 = 290,
    UVEC4 = 291,
    MATRIX2 = 292,
    MATRIX3 = 293,
    MATRIX4 = 294,
    IN_QUAL = 295,
    OUT_QUAL = 296,
    INOUT_QUAL = 297,
    OUTPUT_QUAL = 298,
    INPUT_QUAL = 299,
    UNIFORM = 300,
    BUFFER = 301,
    VARYING = 302,
    MATRIX2x3 = 303,
    MATRIX3x2 = 304,
    MATRIX2x4 = 305,
    MATRIX4x2 = 306,
    MATRIX3x4 = 307,
    MATRIX4x3 = 308,
    CENTROID = 309,
    FLAT = 310,
    SMOOTH = 311,
    STRUCT = 312,
    VOID_TYPE = 313,
    WHILE = 314,
    SAMPLER2D = 315,
    SAMPLERCUBE = 316,
    SAMPLER_EXTERNAL_OES = 317,
    SAMPLER2DRECT = 318,
    SAMPLER2DARRAY = 319,
    ISAMPLER2D = 320,
    ISAMPLER3D = 321,
    ISAMPLERCUBE = 322,
    ISAMPLER2DARRAY = 323,
    USAMPLER2D = 324,
    USAMPLER3D = 325,
    USAMPLERCUBE = 326,
    USAMPLER2DARRAY = 327,
    SAMPLER3D = 328,
    SAMPLER3DRECT = 329,
    SAMPLER2DSHADOW = 330,
    SAMPLERCUBESHADOW = 331,
    SAMPLER2DARRAYSHADOW = 332,
    LAYOUT = 333,
    IDENTIFIER = 334,
    TYPE_NAME = 335,
    FLOATCONSTANT = 336,
    INTCONSTANT = 337,
    UINTCONSTANT = 338,
    BOOLCONSTANT = 339,
    FIELD_SELECTION = 340,
    LEFT_OP = 341,
    RIGHT_OP = 342,
    INC_OP = 343,
    DEC_OP = 344,
    LE_OP = 345,
    GE_OP = 346,
    EQ_OP = 347,
    NE_OP = 348,
    AND_OP = 349,
    OR_OP = 350,
    XOR_OP = 351,
    MUL_ASSIGN = 352,
    DIV_ASSIGN = 353,
    ADD_ASSIGN = 354,
    MOD_ASSIGN = 355,
    LEFT_ASSIGN = 356,
    RIGHT_ASSIGN = 357,
    AND_ASSIGN = 358,
    XOR_ASSIGN = 359,
    OR_ASSIGN = 360,
    SUB_ASSIGN = 361,
    LEFT_PAREN = 362,
    RIGHT_PAREN = 363,
    LEFT_BRACKET = 364,
    RIGHT_BRACKET = 365,
    LEFT_BRACE = 366,
    RIGHT_BRACE = 367,
    DOT = 368,
    COMMA = 369,
    COLON = 370,
    EQUAL = 371,
    SEMICOLON = 372,
    BANG = 373,
    DASH = 374,
    TILDE = 375,
    PLUS = 376,
    STAR = 377,
    SLASH = 378,
    PERCENT = 379,
    LEFT_ANGLE = 380,
    RIGHT_ANGLE = 381,
    VERTICAL_BAR = 382,
    CARET = 383,
    AMPERSAND = 384,
    QUESTION = 385
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{


    struct {
        union {
            TString *string;
            float f;
            int i;
            unsigned int u;
            bool b;
        };
        TSymbol* symbol;
    } lex;
    struct {
        TOperator op;
        union {
            TIntermNode* intermNode;
            TIntermNodePair nodePair;
            TIntermTyped* intermTypedNode;
            TIntermAggregate* intermAggregate;
            TIntermSwitch* intermSwitch;
            TIntermCase* intermCase;
        };
        union {
            TPublicType type;
            TPrecision precision;
            TLayoutQualifier layoutQualifier;
            TQualifier qualifier;
            TFunction* function;
            TParameter param;
            TField* field;
            TFieldList* fieldList;
        };
    } interm;


};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (TParseContext* context, void *scanner);

#endif /* !YY_YY_GLSLANG_TAB_H_INCLUDED  */
