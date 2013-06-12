#include "BasicNode.h"
#include "Classes.h"

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
      TyLVal():LVal(L_ID) {
      }
};

class LValMember : public LVal {
  public:
      LValue *major;
      string memberName;
      VarLVal(LValue *_major, const string& _memberName) : LVal(L_Member) {
          major = _major;
          memberName = _memberName;
      }
      VarLVal() : LVal(L_Member) {
          major = NULL;
      }
};

class LValElement : public LVal {
  public:
      LValue *major;
      Expression *idx;
      LValElement(LValue *_major, Expression* _idx) : LVal(L_Element) {
          major = _major;
          idx = _idx
      }
      LValElement() : LVal(L_Element) {
          major = NULL;
          idx = NULL;
      }
};

