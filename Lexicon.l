%{

#include "ASTClass.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

int commentNesting = 0;
string lexStr;
int convTmp;

%}
ID              [a-zA-Z][0-9a-zA-z_]*
BLANK           [ \t\n\r\f]
OCTCH           \\[0-7]{3}
HEXCH           \\x[0-9a-fA-F]{2}

%x              COMMENT
%x              STRING
%%

"array"         {   return  TOK_ARRAY;              }
"break"         {   return  TOK_BREAK;              }
"do"            {   return  TOK_DO;                 }
"else"          {   return  TOK_ELSE;               }
"end"           {   return  TOK_END;                }
"for"           {   return  TOK_FOR;                }
"function"      {   return  TOK_FUNCTION;           }
"if"            {   return  TOK_IF;                 }
"in"            {   return  TOK_IN;                 }
"let"           {   return  TOK_LET;                }
"nil"           {   return  TOK_NIL;                }
"of"            {   return  TOK_OF;                 }
"then"          {   return  TOK_THEN;               }
"to"            {   return  TOK_TO;                 }
"type"          {   return  TOK_TYPE;               }
"var"           {   return  TOK_VAR;                }
"while"         {   return  TOK_WHILE;              }
"+"             {   return  TOK_PLUS_SIGN;          }
"-"             {   return  TOK_MINUS_SIGN;         }
"*"             {   return  TOK_MULT_SIGN;          }
"/"             {   return  TOK_DIV_SIGN;           }
"&"             {   return  TOK_AND;                }
"|"             {   return  TOK_OR;                 }
"="             {   return  TOK_EQUALS;             }
"<>"            {   return  TOK_NEQ;                }
"<"             {   return  TOK_LT;                 }
"<="            {   return  TOK_LTE;                }
">"             {   return  TOK_GT;                 }
">="            {   return  TOK_GTE;                }
":="            {   return  TOK_ASSIGN;             }
";"             {   return  TOK_SEMIC;              }
","             {   return  TOK_COMMA;              }
":"             {   return  TOK_COLON;              }
"."             {   return  TOK_DOT;                }
"("             {   return  TOK_LBR;                }
")"             {   return  TOK_RBR;                }
"["             {   return  TOK_LSQB;               }
"]"             {   return  TOK_RSQB;               }
"{"             {   return  TOK_LCURLB;             }
"}"             {   return  TOK_RCURLB;             }
[0-9]+          {   
                    yylval.integer = strToTInt(string(yytext));
                    return  TOK_INTEGER;
                }
{ID}            {   
                    yylval.strPtr = new string(yytext);
                    return  TOK_ID;
                }
{BLANK}         {   /* ignore */                    }
"/*"            {   BEGIN COMMENT;
                    ++ commentNesting;
                }
<COMMENT>"/*"   {   ++ commentNesting;              }
<COMMENT>"*/"   {   -- commentNesting;
                    if (commentNesting == 0) BEGIN INITIAL;
                }
<COMMENT>.      |
<COMMENT>"\n"   {   /* do nothing */                }

"\""            {   
                    BEGIN STRING;
                    lexStr = "";
                }

<STRING>"\""    {   
                    BEGIN INITIAL;
                    yylval.strPtr = new string(lexStr);
                    return TOK_STRING;
                }
<STRING>"\\a"   {   lexStr += '\a';                 }
<STRING>"\\b"   {   lexStr += '\b';                 }
<STRING>"\\f"   {   lexStr += '\f';                 }
<STRING>"\\n"   {   lexStr += '\n';                 }
<STRING>"\\r"   {   lexStr += '\r';                 }
<STRING>"\\t"   {   lexStr += '\t';                 }
<STRING>"\\v"   {   lexStr += '\v';                 }
<STRING>"\\'"   {   lexStr += '\'';                 }
<STRING>"\\\""  {   lexStr += '\"';                 }
<STRING>"\\\\"  {   lexStr += '\\';                 }
<STRING>"\\?"   {   lexStr += '\?';                 }
<STRING>{OCTCH} {   assert(strlen(yytext) == 4);
                    assert(yytext[0] == '\\');
                    char tmpChr = 0;
                    for (int i = 1; i < 4; ++ i) {
                        assert((yytext[i] <= '7') && (yytext[i] >= '0'));
                        tmpChr = tmpChr * 8 + yytext[i] - '0';
                    }
                    lexStr += tmpChr;
                }
<STRING>{HEXCH} {   assert(strlen(yytext) == 4);
                    assert(yytext[0] == '\\');
                    assert(yytext[1] == 'x');
                    char tmpChr = 0;
                    for (int i = 2; i < 4; ++ i) {
                        yytext[i] = toupper(yytext[i]);
                        assert(((yytext[i] <= '9') && (yytext[i] >= '0'))
                                    || ((yytext[i] <= 'F') && (yytext[i] >= 'A')) );
                        if ((yytext[i] <= '9') && (yytext[i] >= '0')) {
                            tmpChr = tmpChr * 16 + yytext[i] - '0';
                        } else {
                            tmpChr = tmpChr * 16 + yytext[i] - 'A' + 10;
                        }
                    }
                    lexStr += tmpChr;
                }
<STRING>.       {   lexStr += yytext;               }

%%
/*
int main()
{
    int t;
    while (t = yylex()) {
        cout << yytext << " " << t << " " << getTokenName(t) << endl;
        if (t == TOK_STRING) cout << lexStr << endl;
    }
}
*/


