#include "ASTClass.h"
#include "BasicNode.h"
#include "ClassEnum.h"
#include "ExpClass.h"
#include "DecClass.h"
#include "LValClass.h"
#include "MiscClass.h"

LVal::LVal(LValNodeType _lValNodeType):BasicNode(N_LValue) {
    lValNodeType = _lValNodeType;
}
LValNodeType LVal::getLValType() {
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
