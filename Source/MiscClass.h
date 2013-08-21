#ifndef MISCCLASS_H_
#define MISCCLASS_H_

#include "ASTClass.h"

class ExpList : public BasicNode {
  public:
      vector<Expression*> expVec;
      ExpList();
      Expression*& operator[](size_t idx) ;
      vector<Expression*>::size_type size() ;
      void push_back(Expression* _exp) ;
      ~ExpList();
};

class ArgList : public BasicNode {
  public:
      vector<Expression*> argVec;
      ArgList();
      Expression*& operator[](size_t idx) ;
      vector<Expression*>::size_type size() ;
      void push_back(Expression* _arg) ;
      ~ArgList();
};

class DecList : public BasicNode {
  public:
      vector<Dec*> decVec;
      DecList();
      Dec*& operator[](size_t idx) ;
      vector<Dec*>::size_type size() ;
      void push_back(Dec* _dec) ;
      ~DecList() ;
};

class FieldExpList : public BasicNode {
  public:
      vector<FieldExpEle> fieldExpVec;
      FieldExpList();
      FieldExpEle& operator[](size_t idx) ;
      vector<FieldExpEle>::size_type size() ;
      void push_back(FieldExpEle _fieldExpEle) ;
      ~FieldExpList();
};

class FieldList : public BasicNode {
  public:
      vector<FieldEle> fieldVec;
      FieldList();
      FieldEle& operator[](size_t idx) ;
      vector<FieldEle>::size_type size() ;
      void push_back(FieldEle _fieldEle) ;
};

#endif // MISCCLASS_H_
