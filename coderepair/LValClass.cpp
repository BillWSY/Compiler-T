#ifndef LVALCLASS_H_
#define LVALCLASS_H_

#include "BasicNode.h"
#include "ASTClass.h"
#include "ClassEnum.h"

LVal::LVal(LValNodeType _lValNodeType):BasicNode(N_LValue) {
    lValNodeType = _lValNodeType;
}
LVal::LValNodeType getLValType() {
    return lValNodeType;
}

LValID::LValID(const string& _lValName):LVal(L_ID) {
    lValName = _lValName;
}

LValMember::LValMember(LVal *_major, const string& _memberName) : LVal(L_Member) {
    major = _major;
    memberName = _memberName;
}
LValMember::LValMember() : LVal(L_Member) {
    major = NULL;
}
LValMember::~LValMember(){
    if (major) delete major;
    major = NULL;
}

LValElement::LValElement(LVal *_major, Expression* _idx) : LVal(L_Element) {
    major = _major;
    idx = _idx;
}
LValElement::LValElement() : LVal(L_Element) {
    major = NULL;
    idx = NULL;
}
LValElement::~LValElement(){
    if (major) delete major;
    major = NULL;
}

#endif // LVALCLASS_H_
