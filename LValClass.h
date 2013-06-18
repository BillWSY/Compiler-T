#ifndef LVALCLASS_H_
#define LVALCLASS_H_

#include "ASTClass.h"

class LVal : public BasicNode {
  private:
      LValNodeType lValNodeType;
  protected:
      LVal(LValNodeType _lValNodeType);
  public:
      LValNodeType getLValType() ;
};

class LValID : public LVal {
  public:
      string lValName;
      LValID(const string& _lValName);
};

class LValMember : public LVal {
  public:
      LVal *major;
      string memberName;
      LValMember(LVal *_major, const string& _memberName) ;
      LValMember() ;
      ~LValMember();
};

class LValElement : public LVal {
  public:
      LVal *major;
      Expression *idx;
      LValElement(LVal *_major, Expression* _idx) ;
      LValElement() ;
      ~LValElement();
};

#endif // LVALCLASS_H_
