#ifndef TOKEN_DEF_H
#define TOKEN_DEF_H
#include "Parser.h"

#define CNT_TOKEN 47
#define BASE_TOKEN 258

#include <string>
#include <vector>

extern std::vector<std::string> strList;
extern int strListCnt;

std::string getTokenName(int tokenType);
#endif
