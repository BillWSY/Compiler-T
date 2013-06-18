#ifndef DECCLASS_H_
#define DECCLASS_H_

#include "ASTClass.h"

class Dec : public BasicNode {
  private:
      DecNodeType decNodeType;
  protected:
      Dec(DecNodeType _decNodeType);
  public:
      DecNodeType getDecType() ;
};
class TyDec : public Dec {
  public:
      string typeName;
      Ty* ty;
      TyDec(const string& _typeName, Ty *_ty);
      TyDec();
      ~TyDec() ;
};
class Ty : public BasicNode {
  public:
      TyType tyType;
      string tyName;
      FieldList* fieldList;
      Ty();
      Ty(TyType _tyType, string _tyName);
      Ty(TyType _tyType, FieldList* _fieldList);
      ~Ty() ;
};
class VarDec : public Dec {
  public:
      string varName;
      string typeName;
      Expression* initVal;
      bool hasType;
      VarDec(const string& _varName, const string& _typeName, Expression* _initVal) ;
      VarDec(const string& _varName, Expression* _initVal) ;
      VarDec() ;
      ~VarDec() ;
};
class FuncDec : public Dec {
  public:
      bool hasReturn;
      string funcName;
      FieldList* fieldList;
      string typeName;
      Expression* body;
      FuncDec(const string& _funcName, FieldList* _fieldList, const string& _typeName, Expression* _body) ;
      FuncDec(const string& _funcName, FieldList* _fieldList, Expression* _body) ;
      FuncDec() ;
      ~FuncDec() ;
};
#endif // DECCLASS_H_
