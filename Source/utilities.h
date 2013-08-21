#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "ASTClass.h"
#include <sstream>

using namespace std;

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
void string_replace(string & strBig, const string & strsrc, const string &strdst);

#endif // UTILITIES_H

