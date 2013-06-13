#ifndef ASTCLASS_H_
#define ASTCLASS_H_

#include <vector>
#include <utility>
#include <string>

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
typedef vector<Expression*> ExpList;
typedef vector<Expression*> ArgList;
typedef pair<string, string> FieldEle;
typedef vector<FieldEle> FieldList;
typedef pair<string, Expression*> IdSqB;
typedef pair<string, Expression*> FieldExpEle;
typedef vector<FieldExpEle> FieldExpList;
typedef vector<Dec*> DecList;

#include "BasicNode.h"
#include "ClassEnum.h"
#include "DecClass.h"
#include "ExpClass.h"
#include "LValClass.h"

#endif // ASTCLASS_H
