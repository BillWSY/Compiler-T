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
typedef vector<pair<string, string> > FieldList;
typedef vector<pair<string, Expression*> > FieldExpList;
typedef vector<Dec> DecList;


























