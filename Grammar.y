%{
#include stdio.h
#include string.h
#include "Tokeniser.h"

extern int yyparse ();

void yyerror(const char *str)
{
    fprintf(stderr,"error: %s\n",str);
}

int yywrap()
{
    return 1;
}
/*
int main()
{
    yyparse();
}
*/

%}

%token TOK_ARRAY TOK_BREAK TOK_DO TOK_ELSE TOK_END
%token TOK_FOR TOK_FUNCTION TOK_IF TOK_IN TOK_LET
%token TOK_NIL TOK_OF TOK_THEN TOK_TO TOK_TYPE
%token TOK_VAR TOK_WHILE TOK_PLUS_SIGN TOK_MINUS_SIGN TOK_MULT_SIGN
%token TOK_DIV_SIGN TOK_AND TOK_OR TOK_EQUALS TOK_NEQ
%token TOK_LT TOK_LTE TOK_GT TOK_GTE TOK_ASSIGN
%token TOK_SEMIC TOK_COMMA TOK_COLON TOK_DOT TOK_LBR
%token TOK_RBR TOK_LSQB TOK_RSQB TOK_LCURLB TOK_RCURLB
%token TOK_INTEGER TOK_ID TOK_STRING

%%

Prog            :       Exp
                ;

Exp             :       LValue
                |       TOK_INTEGER
                |       TOK_NIL
                |       TOK_STRING
                |       TOK_ID TOK_LBR ArgList TOK_RBR
                |       Exp BinOp Exp
                |       UnOp Exp
                |       TOK_ID TOK_LCURLB FieldExpList TOK_RCURLB
                |       TOK_LBR ExpList TOK_RBR
                |       LValue TOK_ASSIGN Exp
                |       TOK_IF Exp TOK_THEN Exp
                |       TOK_IF Exp TOK_THEN Exp TOK_ELSE Exp
                |       TOK_WHILE Exp TOK_DO Exp
                |       TOK_FOR TOK_ID TOK_ASSIGN Exp TOK_TO Exp TOK_DO Exp
                |       TOK_BREAK
                |       TOK_LET DecList TOK_IN ExpList TOK_END
                |       TOK_ID TOK_LSQB Exp TOK_RSQB TOK_OF Exp
                ;

DecList         :       /* nothing */
                |       Dec DecList
                ;

Dec             :       TyDec
                |       VarDec
                |       FunDec
                ;

TyDec           :       TOK_TYPE TOK_ID TOK_EQUALS Ty
                ;

Ty              :       TOK_ID
                |       TOK_LCURLB FieldList TOK_RCURLB
                |       TOK_ARRAY TOK_OF TOK_ID
                ;

VarDec          :       TOK_VAR TOK_ID TOK_ASSIGN Exp
                |       TOK_VAR TOK_ID TOK_COLON TOK_ID TOK_ASSIGN Exp
                ;

FunDec          :       TOK_FUNCTION TOK_ID TOK_LBR FieldList TOK_RBR Exp
                |       TOK_FUNCTION TOK_ID TOK_LBR FieldList TOK_RBR TOK_COLON TOK_ID TOK_EQUALS Exp
                ;

LValue          :       TOK_ID
                |       LValue TOK_DOT TOK_ID
                |       LValue TOK_LSQB Exp TOK_RSQB
                ;

ExpList         :       /* nothing */
                |       Exp ExpListPr
                ;

ExpListPr       :       /* nothing */
                |       TOK_SEMIC Exp ExpListPr
                ;

ArgList         :       /* nothing */
                |       Exp ArgListPr
                ;

ArgListPr       :       /* nothing */
                |       TOK_COMMA Exp ArgListPr
                ;

FieldList       :       /* nothing */
                |       TOK_ID TOK_COLON TOK_ID FieldListPr
                ;

FieldListPr     :       /* nothing */
                |       TOK_COMMA TOK_ID TOK_COLON TOK_ID FieldListPr
                ;

FieldExpList    :       /* nothing */
                |       TOK_ID TOK_EQUALS Exp FieldExpListPr
                ;

FieldExpListPr  :       /* nothing */
                |       TOK_COMMA TOK_ID TOK_EQUALS Exp FieldExpListPr
                ;

BinOp           :       TOK_PLUS_SIGN
                |       TOK_MINUS_SIGN
                |       TOK_MULT_SIGN
                |       TOK_DIV_SIGN
                |       TOK_AND
                |       TOK_OR
                |       TOK_EQUALS
                |       TOK_NEQ
                |       TOK_LT
                |       TOK_LTE
                |       TOK_GT
                |       TOK_GTE
                ;


UnOp            :       TOK_MINUS_SIGN
                ;

