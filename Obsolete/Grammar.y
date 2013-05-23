%{
#include <stdio.h>
#include <string.h>
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
%token TOK_DIV TOK_AND TOK_OR TOK_EQUALS TOK_NEQ
%token TOK_LT TOK_LTE TOK_GT TOK_GTE TOK_ASSIGN
%token TOK_SEMIC TOK_COMMA TOK_COLON TOK_DOT TOK_LBR
%token TOK_RBR TOK_LSQB TOK_RSQB TOK_LCURLB TOK_RCURLB
%token TOK_INTEGER TOK_ID TOK_BLANK TOK_COMMENT_IN TOK_COMMENT_OUT
%token TOK_COMMENT_CONTENT TOK_STRING

%%

vardec : TOK_VAR TOK_ID TOK_ASSIGN TOK_INTEGER
       ;
