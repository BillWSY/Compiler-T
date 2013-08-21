#include "ASTClass.h"
#include "BasicNode.h"
#include "ClassEnum.h"
#include "ExpClass.h"
#include "DecClass.h"
#include "LValClass.h"
#include "MiscClass.h"

ExpList::ExpList():BasicNode(N_ExpList) {
    //do nothing
}
Expression*& ExpList::operator[](size_t idx) {
    return expVec[idx];
}
size_t ExpList::size() {
    return expVec.size();
}
void ExpList::push_back(Expression* _exp) {
    expVec.push_back(_exp);
}
ExpList::~ExpList(){
    for(size_t i = 0; i < expVec.size(); ++ i) {
        if (expVec[i]) delete expVec[i];
        expVec[i] = NULL;
    }
}

ArgList::ArgList():BasicNode(N_ArgList) {
    //do nothing
}
Expression*& ArgList::operator[](size_t idx) {
    return argVec[idx];
}
size_t ArgList::size() {
    return argVec.size();
}
void ArgList::push_back(Expression* _arg) {
    argVec.push_back(_arg);
}
ArgList::~ArgList(){
    for(size_t i = 0; i < argVec.size(); ++ i) {
        if (argVec[i]) delete argVec[i];
        argVec[i] = NULL;
    }
}

DecList::DecList():BasicNode(N_DecList) {
    //do nothing
}
Dec*& DecList::operator[](size_t idx) {
    return decVec[idx];
}
size_t DecList::size() {
    return decVec.size();
}
void DecList::push_back(Dec* _dec) {
    decVec.push_back(_dec);
}
DecList::~DecList() {
    for(size_t i = 0; i < decVec.size(); ++ i) {
        if (decVec[i]) delete decVec[i];
        decVec[i] = NULL;
    }
}

FieldExpList::FieldExpList():BasicNode(N_FieldExpList) {
    //do nothing
}
FieldExpEle& FieldExpList::operator[](size_t idx) {
    return fieldExpVec[idx];
}
size_t FieldExpList::size() {
    return fieldExpVec.size();
}
void FieldExpList::push_back(FieldExpEle _fieldExpEle) {
    fieldExpVec.push_back(_fieldExpEle);
}
FieldExpList::~FieldExpList(){
    for(size_t i = 0; i < fieldExpVec.size(); ++ i) {
        if (fieldExpVec[i].second) delete fieldExpVec[i].second;
        fieldExpVec[i].second = NULL;
    }
}

FieldList::FieldList():BasicNode(N_FieldList) {
    //do nothing
}
FieldEle& FieldList::operator[](size_t idx) {
    return fieldVec[idx];
}
size_t FieldList::size() {
    return fieldVec.size();
}
void FieldList::push_back(FieldEle _fieldEle) {
    fieldVec.push_back(_fieldEle);
}

