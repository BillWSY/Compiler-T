#include <string>
#include <sstream>
#include "ASTClass.h"

using namespace std;

template <typename T> toStr(const T& content)
{
    stringstream ss;
    ss << content;
    return ss.str();
}

TInt strToTInt(string str)
{
    TInt rtn;
    stringstream ss(str);
    ss >> rtn;
    return rtn;
}

string binOpToStr(BinOpType binOp)
{
    switch(binOp) {
        BO_Mul:
            return string("*");
        BO_Div:
            return string("/");
        BO_Plus:
            return string("+");
        BO_Minus:
            return string("-");
        BO_Neq:
            return string("<>");
        BO_LT:
            return string("<");
        BO_LTE:
            return string("<=");
        BO_GT:
            return string(">");
        BO_GTE:
            return string(">=");
        BO_Equal:
            return string("=");
        BO_And:
            return string("&");
        BO_Or:
            return string("|");
        default:
            return string("WRONG_BINOP");
    }
}

string unOpToStr(UnOpType unOp)
{
    switch (unOp) {
        UO_Neg:
            return string("-");
        default:
            return string("WRONG_UNOP");
    }
}

string makeIndent(int n)
{
    string rtn;
    for(int i = 0; i < n; ++ i) {
        rtn += "    ";
    }
    return rtn;
}

