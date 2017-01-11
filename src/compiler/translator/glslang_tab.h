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
    SAMPLER2DMS = 320,
    ISAMPLER2D = 321,
    ISAMPLER3D = 322,
    ISAMPLERCUBE = 323,
    ISAMPLER2DARRAY = 324,
    ISAMPLER2DMS = 325,
    USAMPLER2D = 326,
    USAMPLER3D = 327,
    USAMPLERCUBE = 328,
    USAMPLER2DARRAY = 329,
    USAMPLER2DMS = 330,
    SAMPLER3D = 331,
    SAMPLER3DRECT = 332,
    SAMPLER2DSHADOW = 333,
    SAMPLERCUBESHADOW = 334,
    SAMPLER2DARRAYSHADOW = 335,
    LAYOUT = 336,
    IDENTIFIER = 337,
    TYPE_NAME = 338,
    FLOATCONSTANT = 339,
    INTCONSTANT = 340,
    UINTCONSTANT = 341,
    BOOLCONSTANT = 342,
    FIELD_SELECTION = 343,
    LEFT_OP = 344,
    RIGHT_OP = 345,
    INC_OP = 346,
    DEC_OP = 347,
    LE_OP = 348,
    GE_OP = 349,
    EQ_OP = 350,
    NE_OP = 351,
    AND_OP = 352,
    OR_OP = 353,
    XOR_OP = 354,
    MUL_ASSIGN = 355,
    DIV_ASSIGN = 356,
    ADD_ASSIGN = 357,
    MOD_ASSIGN = 358,
    LEFT_ASSIGN = 359,
    RIGHT_ASSIGN = 360,
    AND_ASSIGN = 361,
    XOR_ASSIGN = 362,
    OR_ASSIGN = 363,
    SUB_ASSIGN = 364,
    LEFT_PAREN = 365,
    RIGHT_PAREN = 366,
    LEFT_BRACKET = 367,
    RIGHT_BRACKET = 368,
    LEFT_BRACE = 369,
    RIGHT_BRACE = 370,
    DOT = 371,
    COMMA = 372,
    COLON = 373,
    EQUAL = 374,
    SEMICOLON = 375,
    BANG = 376,
    DASH = 377,
    TILDE = 378,
    PLUS = 379,
    STAR = 380,
    SLASH = 381,
    PERCENT = 382,
    LEFT_ANGLE = 383,
    RIGHT_ANGLE = 384,
    VERTICAL_BAR = 385,
    CARET = 386,
    AMPERSAND = 387,
    QUESTION = 388
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
