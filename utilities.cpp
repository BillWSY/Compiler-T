#include <string>
#include <sstream>
#include "ASTClass.h"

using namespace std;

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
        case BO_Mul:
            return string("*");
        case BO_Div:
            return string("/");
        case BO_Plus:
            return string("+");
        case BO_Minus:
            return string("-");
        case BO_Neq:
            return string("<>");
        case BO_LT:
            return string("<");
        case BO_LTE:
            return string("<=");
        case BO_GT:
            return string(">");
        case BO_GTE:
            return string(">=");
        case BO_Equal:
            return string("=");
        case BO_And:
            return string("&");
        case BO_Or:
            return string("|");
        default:
            return string("WRONG_BINOP");
    }
}

string unOpToStr(UnOpType unOp)
{
    switch (unOp) {
        case UO_Neg:
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

