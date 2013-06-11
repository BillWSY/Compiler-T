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
                lvalue = _lvalue;
                kind = 2;
       }

};

/*TOK_INTEGER 3*/
class Expression2: public BasicNode {
public:
       int value;
       Expression2(int _value){
                    value = _value;
                    kind = 3;
                    data_for_print = "Integer ";
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
                      data_for_print = "String ";
       }
};

/*TOK_STRING 6 id(<ArgList>)*/
class Expression5: public BasicNode {
public:
       BasicNode *id;
       vector<BasicNode *>arglist;
       Expression5(BasicNode*_id,vector<BasicNode *>_arglist) {
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
       BasicNode *id;
       vector<BasicNode *> fieldexplist;
       Expression8(BasicNode *_id,vector<BasicNode*>_fieldexplist) {
                      id = _id;
                      fieldexplist = _fieldexplist;
                      kind = 9;
                      data_for_print = "FieldList";
       }
};

/* 10 (ExpList) */
class Expression9: public BasicNode {
public:
       vector <BasicNode *>explist;
       Expression9(vector <BasicNode *>_explist) {
                      explist = _explist;
                      kind = 10;
                      data_for_print = "ExpList";
       }
};

/* 11  LValue := <Exp>*/
class Expression10: public BasicNode {
public:
       BasicNode *lvalue,*exp;
       Expression10(BasicNode *_lvalue,BasicNode *_exp) {
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
       Expression11(BasicNode *_exp1,BasicNode *_exp2) {
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
       Expression12(BasicNode *_exp1,BasicNode *_exp2,BasicNode *_exp3) {
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
       Expression13(BasicNode *_exp1,BasicNode *_exp2) {
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
       Expression14(BasicNode *_id,BasicNode *_exp1,BasicNode *_exp2) {
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
       vector <BasicNode *>declist,explist;
       Expression16(vector <BasicNode *>_declist,vector <BasicNode *>_explist) {
                    declist = _declist;
                    explist = _explist;
                    kind = 17;
                    data_for_print = "let Statement";
       }
};

/* 18  id[Exp] of Exp  这条好像有点不一致，我看到的原版是这个..*/
class Expression17: public BasicNode {
public:
       BasicNode *id,*exp1,*exp2;
       Expression17(BasicNode*_id,BasicNode*_exp1,BasicNode*_exp2) {
                    id = _id;
                    exp1 = _exp1;
                    exp2 = _exp2;
                    kind = 18;
                    data_for_print = "Of Statement";
       }
};
/*--------------------end of exp---------------------------------*/


/*20  <DecList>      ->        <Dec> <Declist>*/
class DecList:public BasicNode {
    vector <BasicNode *> declist;
    DecList(vector <BasicNode *> _declist) {
        declist = _declist;
        kind = 20;
        data_for_print = "DecList";
    }
};

/*22 Dec ->  TyDec*/
class DecNode1:public BasicNode {
    BasicNode* tydec;
    DecNode1(BasicNode *_tydec) {
        tydec = _tydec;
        kind = 22;
        data_for_print = "Dec(TyDec)";
    }
};

/*23 Dec ->  VarDec*/
class DecNode2:public BasicNode {
    BasicNode* vardec;
    DecNode2(BasicNode *_vardec){
        vardec = _vardec;
        kind = 23;
        data_for_print = "Dec(VarDec)";
    }
};

/*24 Dec ->  FunDec*/
class DecNode3:public BasicNode {
    BasicNode* fundec;
    DecNode3(BasicNode *_fundec){
        fundec = _fundec;
        kind = 24;
        data_for_print = "Dec(FunDec)";
    }
};

/*25 <TyDec>        |         type id = <Ty>*/
class TyDec:public BasicNode {
    BasicNode* id, *ty;
    TyDec(BasicNode *_id,BasicNode *_ty){
        id = _id;
        ty = _ty;
        kind = 25;
        data_for_print = "TyDec";
    }
};

/*26 <Ty> -> id*/
class Ty1:public BasicNode {
    BasicNode* id;
    Ty1(BasicNode *_id) {
        id = _id;
        kind = 26;
        data_for_print = "Ty(id)";
    }
};

/*27 <Ty> ->  {<FieldList>}*/
class Ty2:public BasicNode {
    vector <BasicNode *> fieldlist;
    Ty2(vector <BasicNode *>_fieldlist) {
        fieldlist = _fieldlist;
        kind = 27;
        data_for_print = "Ty<FieldList>";
    }
};

/*28 <Ty> -> array of id*/
class Ty3:public BasicNode {
    BasicNode* id;
    Ty3(BasicNode *_id) {
        id = _id;
        kind = 28;
        data_for_print = "Ty(array)";
    }
};

/*29 <VarDec> ->  var id := <Exp>*/
class VarDec1:public BasicNode {
    BasicNode* id,*exp;
    VarDec1(BasicNode *_id,BasicNode *exp) {
        id = _id;
        kind = 29;
        data_for_print = "VarDec1";
    }
};

/*30 <VarDec> ->   var id:id:= <Exp>*/
class VarDec2:public BasicNode {
    BasicNode* id1, *id2, *exp;
    VarDec2(BasicNode *_id1,BasicNode *_id2,BasicNode *_exp) {
        id1 = _id1;
        id2 = _id2;
        exp = _exp;
        kind = 30;
        data_for_print = "VarDec2";
    }
};

/*31 <FuncDec> ->   function id(FieldList)=Exp*/
class FuncDec1:public BasicNode {
    BasicNode* id;
    vector <BasicNode *> fieldlist;
    BasicNode *exp;
    FuncDec1(BasicNode *_id,vector <BasicNode *>_fieldlist,BasicNode *_exp) {
        id = _id;
        fieldlist = _fieldlist;
        exp = _exp;
        kind = 31;
        data_for_print = "FuncDec1";
    }
};

/*32 <FuncDec> ->    function id(FieldList):id=<Exp>*/
class FuncDec2:public BasicNode {
    BasicNode* id1,*id2, *exp;
    vector <BasicNode *> fieldlist;
    FuncDec2(BasicNode *_id1,vector <BasicNode *>_fieldlist,BasicNode *_id2,BasicNode *_exp) {
        id1 = _id1;
        id2 = _id2;
        fieldlist = _fieldlist;
        exp = _exp;
        kind = 32;
        data_for_print = "FuncDec2";
    }
};

/*33 <LValue> ->  id*/
class Lvalue1:public BasicNode {
    BasicNode* id;
    Lvalue1(BasicNode *_id) {
        id = _id;
        kind = 33;
        data_for_print = "LValue1";
    }
};

/*34 <LValue> ->   LValue.id*/
class Lvalue2:public BasicNode {
    BasicNode* lvalue,* id;
    Lvalue2(BasicNode* _lvalue,BasicNode *_id) {
        id = _id;
        lvalue = _lvalue;
        kind = 34;
        data_for_print = "LValue2";
    }
};

/*35 <LValue> ->    LValue[Exp]*/
class Lvalue3:public BasicNode {
    BasicNode* exp,*id;
    Lvalue3(BasicNode* _id,BasicNode *_exp) {
        id = _id;
        exp = _exp;
        kind = 35;
        data_for_print = "LValue3";
    }
};

/*36  <ExpList> -> <Exp> ExpList*/
class ExpList:public BasicNode {
    vector <BasicNode *> explist;
    ExpList(vector <BasicNode *> _explist) {
        explist = _explist;
        kind = 36;
        data_for_print = "ExpList";
    }
};

/*37  <ArgList> -> <Exp> <ArgList'>*/
class ArgList:public BasicNode {
    vector <BasicNode *> arglist;
    ArgList(vector <BasicNode *> _arglist) {
        arglist = _arglist;
        kind = 37;
        data_for_print = "ArgList";
    }
};

/*38  <FieldList>    ->        id:id FieldList' | ε
      <FieldList'>   ->        , id:id FieldList' | ε*/
class FieldList:public BasicNode {
    vector <BasicNode *> fieldlist;
    FieldList(vector <BasicNode *> _fieldlist) {
        fieldlist = _fieldlist;
        kind = 38;
        data_for_print = "FieldList";
    }
};

/*39  <FieldExpList> -> id = Exp FieldExpList' |         ε
<FieldExpList'> ->  , id = Exp FieldExpList' |        ε */
class FieldExpList:public BasicNode {
    vector <BasicNode *> fieldexplist;
    FieldExpList(vector <BasicNode *> _fieldexplist) {
        fieldexplist = _fieldexplist;
        kind = 39;
        data_for_print = "FieldExpList";
    }
};



int main() {
    Expression4* temp = new Expression4("ok~~~~");
    cout << temp->value;
    BasicNode * aa = temp;
    Expression4* now = (Expression4*)(aa);
    printf("%s",now->value.c_str());
    int x;
    while (true) cin>>x;
}














