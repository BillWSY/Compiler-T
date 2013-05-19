#define TOK_ARRAY 1000
#define TOK_BREAK 1001
#define TOK_DO 1002
#define TOK_ELSE 1003
#define TOK_END 1004
#define TOK_FOR 1005
#define TOK_FUNCTION 1006
#define TOK_IF 1007
#define TOK_IN 1008
#define TOK_LET 1009
#define TOK_NIL 1010
#define TOK_OF 1011
#define TOK_THEN 1012
#define TOK_TO 1013
#define TOK_TYPE 1014
#define TOK_VAR 1015
#define TOK_WHILE 1016
#define TOK_PLUS_SIGN 1017
#define TOK_MINUS_SIGN 1018
#define TOK_MULT_SIGN 1019
#define TOK_DIV 1020
#define TOK_AND 1021
#define TOK_OR 1022
#define TOK_EQUALS 1023
#define TOK_NEQ 1024
#define TOK_LT 1025
#define TOK_LTE 1026
#define TOK_GT 1027
#define TOK_GTE 1028
#define TOK_ASSIGN 1029
#define TOK_SEMIC 1030
#define TOK_COMMA 1031
#define TOK_COLON 1032
#define TOK_DOT 1033
#define TOK_LBR 1034
#define TOK_RBR 1035
#define TOK_LSQB 1036
#define TOK_RSQB 1037
#define TOK_LCURLB 1038
#define TOK_RCURLB 1039
#define TOK_INTEGER 1040
#define TOK_ID 1041
#define TOK_STRING 1042

#define CNT_TOKEN 43

#include <string>
#include <map>

typedef std::map<int, std::string> TokDesMap_t;
extern const TokDesMap_t tokDesMap;