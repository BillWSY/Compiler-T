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

/*--------------------expression---------------------------------*/
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

/*1  LValue*/
class BasicLValue: public BasicExpression {
public:
   int Lv_kind;   
           
}





class NValue





/*TOK_INTEGER*/
class NInteger: public BasicNode {
public:
       int value;
       NInteger(int _value){
                    value = _value;
                    data_for_print = "Integer " + value.str();
       }            
};

/*TOK_Nil*/
class NNil: public BasicNode {
public:
       NNil() {
                    data_for_print = "Nil";
       }            
};

/*TOK_BREAK*/
class NBreak: public BasicNode {
public:
       NBreak() {
                    data_for_print = "Break";
       }            
};


/*TOK_STRING*/
class NString: public BasicNode {
public:
       string value;
       NString(string _value) {
                      value = _value;
                      data_for_print = "String " + value;
       }
};  

/*TOK_UnOp*/ 
class NUnOp: public BasicNode {
public:
       string op;
       BasicNode *value;
       NString(string _op,BasicNode *_value) {
                      op = _op;
                      value = _value;
                      data_for_print = "Unop";
       }
};

/*TOK_BinOp*/ 
class NBinOp: public BasicNode {
public:
       string op;
       BasicNode *left,*right;
       NBinOp(string _op,BasicNode *_left,BasicNode *_right) {
                      op = _op;
                      left = _left;
                      right = _right;
                      data_for_print = "BinOp " + string;
       }
};






