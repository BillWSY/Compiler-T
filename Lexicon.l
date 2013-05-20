%{

#include <iostream>
#include "global.h"

using namespace std;

int commentNesting = 0;

%}

%%

"array"     { return TOK_ARRAY; }
"break"     { return TOK_BREAK; }
"do"        { return TOK_DO; }
"else"      { return TOK_ELSE; }
"end"       { return TOK_END; }
"for"       { return TOK_FOR; }
"function"  { return TOK_FUNCTION; }
"if"        { return TOK_IF; }
"in"        { return TOK_IN; }
"let"       { return TOK_LET; }
"nil"       { return TOK_NIL; }
"of"        { return TOK_OF; }
"then"      { return TOK_THEN; }
"to"        { return TOK_TO; }
"type"      { return TOK_TYPE; }
"var"       { return TOK_VAR; }
"while"     { return TOK_WHILE; }
"+"         { return TOK_PLUS_SIGN; }
"-"         { return TOK_MINUS_SIGN; }
"*"         { return TOK_MULT_SIGN; }
"/"         { return TOK_DIV; }
"&"         { return TOK_AND; }
"|"         { return TOK_OR; }
"="         { return TOK_EQUALS; }
"<>"        { return TOK_NEQ; }
"<"         { return TOK_LT; }
"<="        { return TOK_LTE; }
">"         { return TOK_GT; }
">="        { return TOK_GTE; }
":="        { return TOK_ASSIGN; }
";"         { return TOK_SEMIC; }
","         { return TOK_COMMA; }
":"         { return TOK_COLON; }
"."         { return TOK_DOT; }
"("         { return TOK_LBR; }
")"         { return TOK_RBR; }
"["         { return TOK_LSQB; }
"]"         { return TOK_RSQB; }
"{"         { return TOK_LCURLB; }
"}"         { return TOK_RCURLB; }
[0-9]+      { return TOK_INTEGER; }
[a-zA-Z][0-9a-zA-z_]*       { return TOK_ID; }
\"([^\"]|\\\")*\"           { return TOK_STRING; }
[" "\t\n\r\f]   { return TOK_BLANK; }
"/*"(([^\/\*])|(\/[^\*])|(\*[^\/]))* { ++ commentNesting; return TOK_COMMENT_IN; }
"*/"        { -- commentNesting; return TOK_COMMENT_OUT; }

%%

int main()
{
    int t;
    while (t = yylex()) {
        cout << yytext << " " << t << " " << getTokenName(t) << endl;
    }
}

