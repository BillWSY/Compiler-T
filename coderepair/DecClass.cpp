#ifndef DECCLASS_H_
#define DECCLASS_H_

#include "BasicNode.h"
#include "ASTClass.h"
#include "ClassEnum.h"

Dec::Dec(DecNodeType _decNodeType):BasicNode(N_Dec) {
    decNodeType = _decNodeType;
}
Dec::DecNodeType getDecType() {
    return decNodeType;
}

TyDec::TyDec(const string& _typeName, Ty *_ty):Dec(D_Type) {
    typeName = _typeName;
    ty = _ty;
}
TyDec::TyDec():Dec(D_Type) {
    ty = NULL;
}
TyDec::~TyDec() {
    if (ty) delete ty;
    ty = NULL;
}

Ty::Ty():BasicNode(N_Ty) {
    tyType = TY_None;
}
Ty::Ty(TyType _tyType, string _tyName):BasicNode(N_Ty) {
    tyType = _tyType;
    tyName = _tyName; 
    fieldList = NULL;
}
Ty::Ty(TyType _tyType, FieldList* _fieldList):BasicNode(N_Ty) {
    tyType = _tyType;
    fieldList = _fieldList;
    tyName = "";
}
Ty::~Ty() {
    if (fieldList) delete fieldList;
    fieldList = NULL;
}

VarDec::VarDec(const string& _varName, const string& _typeName, Expression* _initVal) : Dec(D_Var) {
    varName = _varName;
    typeName = _typeName;
    hasType = true;
    initVal = _initVal;
}
VarDec::VarDec(const string& _varName, Expression* _initVal) : Dec(D_Var) {
    varName = _varName;
    typeName = "";
    hasType = false;
    initVal = _initVal;
}
VarDec::VarDec() : Dec(D_Var) {
    hasType = false;
    initVal = NULL;
}
VarDec::~VarDec() {
    if (initVal) delete initVal;
    initVal = NULL;
}

FuncDec::FuncDec(const string& _funcName, FieldList* _fieldList, const string& _typeName, Expression* _body) : Dec(D_Func) {
    hasReturn = true;
    funcName = _funcName;
    fieldList = _fieldList;
    typeName = _typeName;
    body = _body;
}
FuncDec::FuncDec(const string& _funcName, FieldList* _fieldList, Expression* _body) : Dec(D_Func) {
    hasReturn = false;
    funcName = _funcName;
    fieldList = _fieldList;
    body = _body;
}
FuncDec::FuncDec() : Dec(D_Func) {
    hasReturn = false;
    fieldList = NULL;
    body = NULL;
}
FuncDec::~FuncDec() {
    if (fieldList) delete fieldList;
    fieldList = NULL;
}

#endif // DECCLASS_H_
