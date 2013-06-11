#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
 
class BasicNode {
public:
   int kind;      //种类信息~~ 
   int total_node;  //当前结点总子树大小 
   string data_for_print; //用来输出的信息 
};

/*--------------------exp---------------------------------*/
/*TOK_ID 1*/
class NId: public BasicNode {
public:
       string name;
       NId(string _name) {
                      name = _name;
                      kind = 1;  
                      data_for_print = "Identifier " + name;
       }
};

/*LValue 2*/
class Expression1: public BasicNode{
public:
       BasicNode *lvalue;
       Expression1(BasicNode *_lvalue) {
                lvalue = _Lvalue;
                kind = 2;
       }        
           
}

/*TOK_INTEGER 3*/
class Expression2: public BasicNode {
public:
       int value;
       Expression2(int _value){
                    value = _value;
                    kind = 3;
                    data_for_print = "Integer " + value.str();
       }            
};

/*TOK_Nil 4*/
class Expression3: public BasicNode {
public:
       Expression3() {
                    kind = 4;
                    data_for_print = "Nil";
       }            
};

/*TOK_STRING 5*/
class Expression4: public BasicNode {
public:
       string value;
       Expression4(string _value) {
                      value = _value;
                      kind = 5;
                      data_for_print = "String " + value;
       }
};  

/*TOK_STRING 6 id(<ArgList>)*/
class Expression5: public BasicNode {
public:
       BasicNode *id, *arglist;
       Expression5(BasicNode*_id,BasicNode*_arglist) {
                      id = _id;
                      arglist = _arglist;
                      kind = 6;
       }
};  

/*TOK_BinOp  7 把几种都合起来了*/ 
class Expression6: public BasicNode {
public:
       string op;
       BasicNode *exp1,*exp2;
       Expression6(string _op,BasicNode *_exp1,BasicNode *_exp2) {
                      op = _op;
                      exp1 = _exp1; 
                      exp2 = _exp2;
                      kind = 7; 
                      data_for_print = "BinOp ";
       }
};

/*TOK_UnOp  8*/ 
class Expression7: public BasicNode {
public:
       string op;
       BasicNode *value;
       Expression7(string _op,BasicNode *_value) {
                      op = _op;
                      value = _value;
                      kind = 8;
                      data_for_print = "Unop";
       }
};


/* 9 id{FieldExpList} */ 
class Expression8: public BasicNode {
public:
       BasicNode *id, *fieldexplist;
       Expression8(BasicNode *_id,BasicNode *_fieldexplist) {
                      id = _id;
                      fieldexplist = _fieldexplist;
                      kind = 9;
                      data_for_print = "FieldList";
       }
};

/* 10 (ExpList) */ 
class Expression9: public BasicNode {
public:
       BasicNode *explist;
       Expression9(BasicNode *_explist) {
                      explist = _explist;
                      kind = 10;
                      data_for_print = "ExpList";
       }
};

/* 11  LValue := <Exp>*/ 
class Expression10: public BasicNode {
public:
       BasicNode *lvalue,*exp;
       Expression10(BasicNode *_lvalue,*exp) {
                      exp = _exp;
                      lvalue = _lvalue;
                      kind = 11;
                      data_for_print = "Assign Statement";
       }
};

/* 12  if <Exp> then <Exp>*/ 
class Expression11: public BasicNode {
public:
       BasicNode *exp1,*exp2;
       Expression11(BasicNode *_exp1,*_exp2) {
                      exp1 = _exp1;
                      exp2 = _exp2;
                      kind = 12;
                      data_for_print = "if Statement";
       }
};

/* 13  if <Exp> then <Exp> else <Exp>*/ 
class Expression12: public BasicNode {
public:
       BasicNode *exp1,*exp2,*exp3;
       Expression12(BasicNode *_exp1,*_exp2,*_exp3) {
                      exp1 = _exp1;
                      exp2 = _exp2;
                      exp3 = _exp3;
                      kind = 13;
                      data_for_print = "if Statement(full)";
       }
};

/* 14   while <Exp> do <Exp>*/ 
class Expression13: public BasicNode {
public:
       BasicNode *exp1,*exp2;
       Expression13(BasicNode *_exp1,*_exp2) {
                      exp1 = _exp1;
                      exp2 = _exp2;
                      kind = 14;
                      data_for_print = "while Statement";
       }
};

/* 15   for id := <Exp> to <Exp> do <Exp>*/ 
class Expression14: public BasicNode {
public:
       BasicNode *id,*exp1,*exp2;
       Expression14(BasicNode *_id,*_exp1,*_exp2) {
                      id = _id;
                      exp1 = _exp1;
                      exp2 = _exp2;
                      kind = 15;
                      data_for_print = "for Statement";
       }
};

/* 16  TOK_BREAK*/
class Expression15: public BasicNode {
public:
       Expression15() {
                    kind = 16;
                    data_for_print = "Break";
       }            
};


/* 17  let <DecList> in <ExpList> end*/
class Expression16: public BasicNode {
public:
       BasicNode *declist,*explist;
       Expression16(BasicNode*_declist,BasicNode*_explist) {
                    declist = _declist;
                    explist = _explist;
                    kind = 17;
                    data_for_print = "let Statement";
       }            
};

/* 18  id[Exp] of Exp  这条好像有点不一致，我看到的原版是这个..*/
class Expression17: public BasicNode {
public:
       BasicNode *id,*exp1,*;
       Expression17(BasicNode*_id,BasicNode*_exp1,BasicNode*_exp2) {
                    id = _id;
                    exp1 = _exp1;
                    exp2 = _exp2;
                    kind = 18;
                    data_for_print = "Of Statement";
       }            
};
/*--------------------end of exp---------------------------------*/
 
/* 19  None */
class None:public BasicNode {
      None() {kind = 19;  data_for_print = "NONE" }
}














