#ifndef LVALCLASS_H_
#define LVALCLASS_H_

#include "BasicNode.h"
#include "ASTClass.h"
#include "ClassEnum.h"

class LVal : public BasicNode {
  private:
      LValNodeType lValNodeType;
  protected:
      LVal(LValNodeType _lValNodeType):BasicNode(N_LValue) {
          lValNodeType = _lValNodeType;
      }
  public:
      LValNodeType getLValType() {
          return lValNodeType;
      }
};

class LValID : public LVal {
  public:
      string lValName;
      LValID(const string& _lValName):LVal(L_ID) {
          lValName = _lValName;
      }
};

class LValMember : public LVal {
  public:
      LVal *major;
      string memberName;
      LValMember(LVal *_major, const string& _memberName) : LVal(L_Member) {
          major = _major;
          memberName = _memberName;
      }
      LValMember() : LVal(L_Member) {
          major = NULL;
      }
      ~LValMember(){
          if (major) delete major;
          major = NULL;
      }
};

class LValElement : public LVal {
  public:
      LVal *major;
      Expression *idx;
      LValElement(LVal *_major, Expression* _idx) : LVal(L_Element) {
          major = _major;
          idx = _idx;
      }
      LValElement() : LVal(L_Element) {
          major = NULL;
          idx = NULL;
      }
      ~LValElement(){
          if (major) delete major;
          major = NULL;
      }
};

#endif // LVALCLASS_H_
