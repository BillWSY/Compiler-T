#include "ASTClass.h"
#include "BasicNode.h"
#include "ClassEnum.h"
#include "ExpClass.h"
#include "DecClass.h"
#include "LValClass.h"
#include "MiscClass.h"

Expression::Expression(ExpNodeType nType):BasicNode(N_Exp) {
    expNodeType = nType;
}
ExpNodeType Expression::getExpType() {
    return expNodeType;
}

ExpLValue::ExpLValue():Expression(E_LValue) {
    lValue = NULL;
}
ExpLValue::ExpLValue(LVal* _lValue):Expression(E_LValue) {
    lValue = _lValue;
}
ExpLValue::~ExpLValue() {
    if (lValue) delete lValue;
    lValue = NULL;
}

ExpInteger::ExpInteger():Expression(E_Integer) {
    num = 0;
}
ExpInteger::ExpInteger(TInt _num):Expression(E_Integer) {
    num = _num;
}

ExpNil::ExpNil():Expression(E_Nil) {
    // do nothing, just instance the father class
}

ExpString::ExpString(const string& _str):Expression(E_String) {
    str = _str;
}

ExpFuncCall::ExpFuncCall(const string& _funcName, ArgList* _argList):Expression(E_FuncCall) {
    argList = _argList;
    funcName = _funcName;
}
ExpFuncCall::ExpFuncCall():Expression(E_FuncCall) {
    argList = NULL;
}
ExpFuncCall::~ExpFuncCall(){
    if (argList) delete argList;
    argList = NULL;
}

ExpBinOp::ExpBinOp(Expression* _exp0, Expression* _exp1, BinOpType _binOp):Expression(E_BinOp) {
    exp0 = _exp0;
    exp1 = _exp1;
    binOp = _binOp;
}
ExpBinOp::ExpBinOp():Expression(E_BinOp) {
    exp0 = NULL;
    exp1 = NULL;
    binOp = BO_None;
}
ExpBinOp::~ExpBinOp(){
    if (exp0) delete exp0;
    exp0 = NULL;
    if (exp1) delete exp1;
    exp1 = NULL;
}

ExpUnOp::ExpUnOp(Expression* _exp, UnOpType _unOp):Expression(E_UnOp) {
    exp = _exp;
    unOp = _unOp;
}
ExpUnOp::ExpUnOp():Expression(E_UnOp) {
    exp = NULL;
    unOp = UO_None;
}
ExpUnOp::~ExpUnOp(){
    if (exp) delete exp;
    exp = NULL;
}

ExpRecord::ExpRecord(const string& _typeName, FieldExpList *_fieldExpList):Expression(E_Record) {
    typeName = _typeName;
    fieldExpList = _fieldExpList;
}
ExpRecord::ExpRecord():Expression(E_Record) {
    fieldExpList = NULL;
}
ExpRecord::~ExpRecord(){
    if (fieldExpList) delete fieldExpList;
    fieldExpList = NULL;
}

ExpExpList::ExpExpList(ExpList* _expList):Expression(E_ExpList){
    expList = _expList;
}
ExpExpList::ExpExpList():Expression(E_ExpList) {
    expList = NULL;
}
ExpExpList::~ExpExpList(){
    if (expList) delete expList;
    expList = NULL;
}

ExpAssign::ExpAssign():Expression(E_Assign) {
    lValue = NULL;
    rhsValue = NULL;
}
ExpAssign::ExpAssign(LVal* _lValue, Expression* _rhsValue):Expression(E_Assign) {
    lValue = _lValue;
    rhsValue = _rhsValue;
}
ExpAssign::~ExpAssign(){
    if (lValue) delete lValue;
    lValue = NULL;
}

ExpIf::ExpIf(Expression *_cond, Expression *_trueStatement, Expression *_falseStatement):Expression(E_If) {
    cond = _cond;
    trueStatement = _trueStatement;
    falseStatement = _falseStatement;
    if (falseStatement) {
        hasElse = true;
    } else {
        hasElse = false;
    }
}
ExpIf::ExpIf():Expression(E_If) {
    cond = NULL;
    trueStatement = NULL;
    falseStatement = NULL;
    hasElse = false;
}
ExpIf::~ExpIf(){
    if (cond) delete cond;
    cond = NULL;
    if (trueStatement) delete trueStatement;
    trueStatement = NULL;
    if (falseStatement) delete falseStatement;
    falseStatement = NULL;
}

ExpWhile::ExpWhile(Expression *_cond, Expression *_loopStatement):Expression(E_While) {
    cond = _cond;
    loopStatement = _loopStatement;
}
ExpWhile::ExpWhile():Expression(E_While) {
    cond = NULL;
    loopStatement = NULL;
}
ExpWhile::~ExpWhile(){
    if (cond) delete cond;
    cond = NULL;
    if (loopStatement) delete loopStatement;
    loopStatement = NULL;
}

ExpFor::ExpFor(const string& _loopVar, Expression *_beg, Expression *_end, Expression *_loopStatement):Expression(E_For) {
    loopVar = _loopVar;
    beg = _beg;
    end = _end;
    loopStatement = _loopStatement;
}
ExpFor::ExpFor():Expression(E_For) {
    beg = NULL;
    end = NULL;
    loopStatement = NULL;
}
ExpFor::~ExpFor(){
    if (beg) delete beg;
    beg = NULL;
    if (end) delete end;
    end = NULL;
    if (loopStatement) delete loopStatement;
    loopStatement = NULL;
}

ExpBreak::ExpBreak():Expression(E_Break) {
    // do nothing, just instance the father class
}

ExpLet::ExpLet(DecList* _decList, ExpList* _expList):Expression(E_Let) {
    decList = _decList;
    expList = _expList;
}
ExpLet::ExpLet():Expression(E_Let) {
    decList = NULL;
    expList = NULL;
}
ExpLet::~ExpLet(){
    if (decList) delete decList;
    decList = NULL;
    if (expList) delete expList;
    expList = NULL;
}

ExpArray::ExpArray(const string& _typeName, Expression *_expSize, Expression *_expInitVal):Expression(E_Array) {
    typeName = _typeName;
    expSize = _expSize;
    expInitVal = _expInitVal;
}
ExpArray::ExpArray():Expression(E_Array) {
    expSize = NULL;
    expInitVal = NULL;
}
ExpArray::~ExpArray(){
    if (expSize) delete expSize;
    expSize = NULL;
    if (expInitVal) delete expInitVal;
    expInitVal = NULL;
}
