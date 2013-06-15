#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "ASTClass.h"
#include <sstream>

template <typename T> string toStr(const T& content)
{
    stringstream ss;
    ss << content;
    return ss.str();
}

TInt strToTInt(string str);
string binOpToStr(BinOpType binOp);
string binOpToStrEsc(BinOpType binOp);
string unOpToStr(UnOpType unOp);
string makeIndent(int n);

#endif // UTILITIES_H

