#ifndef EXPCLASS_H_
#define EXPCLASS_H_

#include "BasicNode.h"
#include "ASTClass.h"
#include "ClassEnum.h"

class Expression : public BasicNode {
  private:
      ExpNodeType expNodeType;
  protected:
      Expression(ExpNodeType nType):BasicNode(N_Exp) {
          expNodeType = nType;
      }
  public:
      ExpNodeType getExpType() {
          return expNodeType;
      }
};

class ExpLValue : public Expression {
  public:
      LVal* lValue;
      ExpLValue():Expression(E_LValue) {
          lValue = NULL;
      }
      ExpLValue(LVal* _lValue):Expression(E_LValue) {
          lValue = _lValue;
      }
};

class ExpInteger : public Expression {
  public:
      TInt num;
      ExpInteger():Expression(E_Integer) {
          num = 0;
      }
      ExpInteger(TInt _num):Expression(E_Integer) {
          num = _num;
      }
};

class ExpNil : public Expression {
  public:
      ExpNil():Expression(E_Nil) {
          // do nothing, just instance the father class
      }
};

class ExpString : public Expression {
  public:
      string str;
      ExpString(const string& _str):Expression(E_String) {
          str = _str;
      }
};

class ExpFuncCall : public Expression {
  public:
      string funcName;
      ArgList* argList;
      ExpFuncCall(const string& _funcName, ArgList* _argList):Expression(E_FuncCall) {
          argList = _argList;
          funcName = _funcName;
      }
      ExpFuncCall():Expression(E_FuncCall) {
          argList = NULL;
      }
};

class ExpBinOp : public Expression {
  public:
      Expression *exp0, *exp1;
      BinOpType binOp;
      ExpBinOp(Expression* _exp0, Expression* _exp1, BinOpType _binOp):Expression(E_BinOp) {
          exp0 = _exp0;
          exp1 = _exp1;
          binOp = _binOp;
      }
      ExpBinOp():Expression(E_BinOp) {
          exp0 = NULL;
          exp1 = NULL;
          binOp = BO_None;
      }
};

class ExpUnOp : public Expression {
  public:
      Expression *exp;
      UnOpType unOp;
      ExpUnOp(Expression* _exp, UnOpType _unOp):Expression(E_UnOp) {
          exp = _exp;
          unOp = _unOp;
      }
      ExpUnOp():Expression(E_UnOp) {
          exp = NULL;
          unOp = UO_None;
      }
};

class ExpRecord : public Expression {
  public:
      string typeName;
      FieldExpList *fieldExpList;
      ExpRecord(const string& _typeName, FieldExpList *_fieldExpList):Expression(E_Record) {
          typeName = _typeName;
          fieldExpList = _fieldExpList;
      }
      ExpRecord():Expression(E_Record) {
          fieldExpList = NULL;
      }
};

class ExpExpList : public Expression {
  public:
      ExpList* expList;
      ExpExpList(ExpList* _expList):Expression(E_ExpList){
          expList = _expList;
      }
      ExpExpList():Expression(E_ExpList) {
          expList = NULL;
      }
};

class ExpAssign : public Expression {
  public:
      LVal* lValue;
      Expression* rhsValue;
      ExpAssign():Expression(E_Assign) {
          lValue = NULL;
          rhsValue = NULL;
      }
      ExpAssign(LVal* _lValue, Expression* _rhsValue):Expression(E_Assign) {
          lValue = _lValue;
          rhsValue = _rhsValue;
      }
};

class ExpIf : public Expression {
  public:
      Expression *cond, *trueStatement, *falseStatement;
      ExpIf(Expression *_cond, Expression *_trueStatement, Expression *_falseStatement = NULL):Expression(E_If) {
          cond = _cond;
          trueStatement = _trueStatement;
          falseStatement = _falseStatement;
      }
      ExpIf():Expression(E_If) {
          cond = NULL;
          trueStatement = NULL;
          falseStatement = NULL;
      }
};

class ExpWhile : public Expression {
  public:
      Expression *cond, *loopStatement;
      ExpWhile(Expression *_cond, Expression *_loopStatement):Expression(E_While) {
          cond = _cond;
          loopStatement = _loopStatement;
      }
      ExpWhile():Expression(E_While) {
          cond = NULL;
          loopStatement = NULL;
      }
};

class ExpFor : public Expression {
  public:
      Expression *beg, *end, *loopStatement;
      string loopVar;
      ExpFor(const string& _loopVar, Expression *_beg, Expression *_end, Expression *_loopStatement):Expression(E_For) {
          loopVar = _loopVar;
          beg = _beg;
          end = _end;
          loopStatement = _loopStatement;
      }
      ExpFor():Expression(E_For) {
          beg = NULL;
          end = NULL;
          loopStatement = NULL;
      }
};

class ExpBreak : public Expression {
  public:
      ExpBreak():Expression(E_Break) {
          // do nothing, just instance the father class
      }
};

class ExpLet : public Expression {
  public:
      DecList* decList;
      ExpList* expList;
      ExpLet(DecList* _decList, ExpList* _expList):Expression(E_Let) {
          decList = _decList;
          expList = _expList;
      }
      ExpLet():Expression(E_Let) {
          decList = NULL;
          expList = NULL;
      }
};

class ExpArray : public Expression {
  public:
      string typeName;
      Expression *expSize, *expInitVal;
      ExpArray(const string& _typeName, Expression *_expSize, Expression *_expInitVal):Expression(E_Array) {
          expSize = _expSize;
          expInitVal = _expInitVal;
      }
      ExpArray():Expression(E_Array) {
          expSize = NULL;
          expInitVal = NULL;
      }
};

#endif // EXPCLASS_H_
