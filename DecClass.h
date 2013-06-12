#include "BasicNode.h"
#include "Classes.h"

class Dec : public BasicNode {
  private:
      DecNodeType decNodeType;
  protected:
      Dec(DecNodeType _decNodeType):BasicNode(N_Dec) {
          decNodeType = _decNodeType;
      }
  public:
      DecNodeType getDecType() {
          return decNodeType;
      }
};

class TyDec : public Dec {
  public:
      string typeName;
      Ty* ty;
      TyDec(const string& _typeName, Ty *_ty):Dec(D_Type) {
          typeName = _typeName;
          ty = _ty;
      }
      TyDec():Dec(D_Type) {
          ty = NULL;
      }
};

class Ty : public BasicNode {
  public:
      TyType tyType;
      string tyName;
      FieldList* fieldList;
      TyDec():BasicNode(N_Ty) {
          TyType = TY_None;
      }
      TyDec(TyType _tyType, string _tyName):BasicNode(N_Ty) {
          TyType = _tyType;
          tyName = _tyName; 
          fieldList = NULL;
      }
      TyDec(TyType _tyType, FieldList* _fieldList):BasicNode(N_Ty) {
          TyType = _tyType;
          fieldList = _fieldList;
          tyName = "";
      }
};

class VarDec : public Dec {
  public:
      string varName;
      string typeName;
      Expression* initVal;
      VarDec(const string& _varName, const string& _typeName, Expression* _initVal) : Dec(D_Var) {
          varName = _varName;
          typeName = _typeName;
          initVal = _initVal;
      }
      VarDec(const string& _varName, Expression* _initVal) : Dec(D_Var) {
          varName = _varName;
          typeName = "";
          initVal = _initVal;
      }
      VarDec() : Dec(D_Var) {
          initVal = NULL;
      }
};

class FuncDec : public Dec {
  public:
      bool hasReturn;
      string funcName;
      FieldList* fieldList;
      string typeName;
      Expression* body;

      FuncDec(const string& _funcName, FieldList* _fieldList, const string& _typeName, Expression* _body) : Dec(D_Func) {
          hasReturn = true;
          funcName = _funcName;
          fieldList = _fieldList;
          typeName = _typeName;
          body = _body;
      }

      FuncDec(const string& _funcName, FieldList* _fieldList, Expression* _body) : Dec(D_Func) {
          hasReturn = false;
          funcName = _funcName;
          fieldList = _fieldList;
          typeName = _typeName;
          body = _body;
      }

      FuncDec() : Dec(D_Func) {
          hasReturn = false;
          fieldList = NULL;
          body = NULL;
      }
};

