#ifndef EXPCLASS_H_
#define EXPCLASS_H_

#include "ASTClass.h"

class Expression : public BasicNode {
  private:
      ExpNodeType expNodeType;
  protected:
      Expression(ExpNodeType nType);
  public:
      ExpNodeType getExpType() ;
};

class ExpLValue : public Expression {
  public:
      LVal* lValue;
      ExpLValue();
      ExpLValue(LVal* _lValue);
      ~ExpLValue() ;
};

class ExpInteger : public Expression {
  public:
      TInt num;
      ExpInteger();
      ExpInteger(TInt _num);
};

class ExpNil : public Expression {
  public:
      ExpNil();
};

class ExpString : public Expression {
  public:
      string str;
      ExpString(const string& _str);
};

class ExpFuncCall : public Expression {
  public:
      string funcName;
      ArgList* argList;
      ExpFuncCall(const string& _funcName, ArgList* _argList);
      ExpFuncCall();
      ~ExpFuncCall();
};

class ExpBinOp : public Expression {
  public:
      Expression *exp0, *exp1;
      BinOpType binOp;
      ExpBinOp(Expression* _exp0, Expression* _exp1, BinOpType _binOp);
      ExpBinOp();
      ~ExpBinOp();
};

class ExpUnOp : public Expression {
  public:
      Expression *exp;
      UnOpType unOp;
      ExpUnOp(Expression* _exp, UnOpType _unOp);
      ExpUnOp();
      ~ExpUnOp();
};

class ExpRecord : public Expression {
  public:
      string typeName;
      FieldExpList *fieldExpList;
      ExpRecord(const string& _typeName, FieldExpList *_fieldExpList);
      ExpRecord();
      ~ExpRecord();
};

class ExpExpList : public Expression {
  public:
      ExpList* expList;
      ExpExpList(ExpList* _expList);
      ExpExpList();
      ~ExpExpList();
};

class ExpAssign : public Expression {
  public:
      LVal* lValue;
      Expression* rhsValue;
      ExpAssign();
      ExpAssign(LVal* _lValue, Expression* _rhsValue);
      ~ExpAssign();
};

class ExpIf : public Expression {
  public:
      Expression *cond, *trueStatement, *falseStatement;
      bool hasElse;
      ExpIf(Expression *_cond, Expression *_trueStatement, Expression *_falseStatement = NULL);
      ExpIf();
      ~ExpIf();
};

class ExpWhile : public Expression {
  public:
      Expression *cond, *loopStatement;
      ExpWhile(Expression *_cond, Expression *_loopStatement);
      ExpWhile();
      ~ExpWhile();
};

class ExpFor : public Expression {
  public:
      Expression *beg, *end, *loopStatement;
      string loopVar;
      ExpFor(const string& _loopVar, Expression *_beg, Expression *_end, Expression *_loopStatement);
      ExpFor();
      ~ExpFor();
};

class ExpBreak : public Expression {
  public:
      ExpBreak();
};

class ExpLet : public Expression {
  public:
      DecList* decList;
      ExpList* expList;
      ExpLet(DecList* _decList, ExpList* _expList);
      ExpLet();
      ~ExpLet();
};

class ExpArray : public Expression {
  public:
      string typeName;
      Expression *expSize, *expInitVal;
      ExpArray(const string& _typeName, Expression *_expSize, Expression *_expInitVal);
      ExpArray();
      ~ExpArray();
};

#endif // EXPCLASS_H_
