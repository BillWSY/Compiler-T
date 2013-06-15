#ifndef ASTCLASS_H_
#define ASTCLASS_H_

#include <vector>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

typedef long long TInt;

class Expression;
class ExpLValue;
class ExpInteger;
class ExpNil;
class ExpString;
class ExpFuncCall;
class ExpBinOp;
class ExpUnOp;
class ExpRecord;
class ExpExpList;
class ExpAssign;
class ExpIf;
class ExpWhile;
class ExpFor;
class ExpBreak;
class ExpLet;
class ExpArray;
class Dec;
class TyDec;
class Ty;
class VarDec;
class FuncDec;
class LVal;
class LValID;
class LValMember;
class LValElement;
class ExpList;
class ArgList;
class FieldList;
class FieldExpList;
class DecList;
typedef pair<string, Expression*> IdSqB;
typedef pair<string, string> FieldEle;
typedef pair<string, Expression*> FieldExpEle;

#include "BasicNode.h"
#include "ClassEnum.h"
#include "DecClass.h"
#include "ExpClass.h"
#include "LValClass.h"
#include "MiscClass.h"

#endif // ASTCLASS_H
