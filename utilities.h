#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "ASTClass.h"

template <typename T> toStr(const T& content);
TInt strToTInt(string str);
string binOpToStr(BinOpType binOp);
string unOpToStr(UnOpType unOp);
string makeIndent(int n);

#endif // UTILITIES_H

