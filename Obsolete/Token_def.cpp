#include "Token_def.h"
#include <cassert>

std::vector<std::string> strList;

int strListCnt;
const std::string tokenNameTable[] = {
    "TOK_ARRAY",
    "TOK_BREAK",
    "TOK_DO",
    "TOK_ELSE",
    "TOK_END",
    "TOK_FOR",
    "TOK_FUNCTION",
    "TOK_IF",
    "TOK_IN",
    "TOK_LET",
    "TOK_NIL",
    "TOK_OF",
    "TOK_THEN",
    "TOK_TO",
    "TOK_TYPE",
    "TOK_VAR",
    "TOK_WHILE",
    "TOK_PLUS_SIGN",
    "TOK_MINUS_SIGN",
    "TOK_MULT_SIGN",
    "TOK_DIV",
    "TOK_AND",
    "TOK_OR",
    "TOK_EQUALS",
    "TOK_NEQ",
    "TOK_LT",
    "TOK_LTE",
    "TOK_GT",
    "TOK_GTE",
    "TOK_ASSIGN",
    "TOK_SEMIC",
    "TOK_COMMA",
    "TOK_COLON",
    "TOK_DOT",
    "TOK_LBR",
    "TOK_RBR",
    "TOK_LSQB",
    "TOK_RSQB",
    "TOK_LCURLB",
    "TOK_RCURLB",
    "TOK_INTEGER",
    "TOK_ID",
    "TOK_BLANK",
    "TOK_COMMENT_IN",
    "TOK_COMMENT_OUT",
    "TOK_COMMENT_CONTENT",
    "TOK_STRING"
};

std::string getTokenName(int tokenType)
{
    assert((tokenType >= BASE_TOKEN) && (tokenType < (BASE_TOKEN + CNT_TOKEN)));
    return tokenNameTable[tokenType - BASE_TOKEN];
}

