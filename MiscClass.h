class ExpList : public BasicNode {
  public:
      vector<Expression*> expVec;
      ExpList():BasicNode(N_ExpList) {
          //do nothing
      }
      Expression*& operator[](size_t idx) {
          return expVec[idx];
      }
      vector<Expression*>::size_type size() {
          return expVec.size();
      }
      void push_back(Expression* _exp) {
          expVec.push_back(_exp);
      }
};

class ArgList : public BasicNode {
  public:
      vector<Expression*> argVec;
      ArgList():BasicNode(N_ArgList) {
          //do nothing
      }
      Expression*& operator[](size_t idx) {
          return argVec[idx];
      }
      vector<Expression*>::size_type size() {
          return argVec.size();
      }
      void push_back(Expression* _arg) {
          argVec.push_back(_arg);
      }
};

class DecList : public BasicNode {
  public:
      vector<Dec*> decVec;
      DecList():BasicNode(N_DecList) {
          //do nothing
      }
      Dec*& operator[](size_t idx) {
          return decVec[idx];
      }
      vector<Dec*>::size_type size() {
          return decVec.size();
      }
      void push_back(Dec* _dec) {
          decVec.push_back(_dec);
      }
};

class FieldExpList : public BasicNode {
  public:
      vector<FieldExpEle> fieldExpVec;
      FieldExpList():BasicNode(N_FieldExpList) {
          //do nothing
      }
      FieldExpEle& operator[](size_t idx) {
          return fieldExpVec[idx];
      }
      vector<FieldExpEle>::size_type size() {
          return fieldExpVec.size();
      }
      void push_back(FieldExpEle _fieldExpEle) {
          fieldExpVec.push_back(_fieldExpEle);
      }
};


class FieldList : public BasicNode {
  public:
      vector<FieldEle> fieldVec;
      FieldList():BasicNode(N_FieldList) {
          //do nothing
      }
      FieldEle& operator[](size_t idx) {
          return fieldVec[idx];
      }
      vector<FieldEle>::size_type size() {
          return fieldVec.size();
      }
      void push_back(FieldEle _fieldEle) {
          fieldVec.push_back(_fieldEle);
      }
};

