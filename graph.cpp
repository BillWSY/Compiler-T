#include "ASTClass.h"
#include "Parser.h"
#include "utilities.h"
#include <iostream>
#include <string>

using namespace std;

extern Expression* root;
Expression* root = NULL;
int indent;

string graphVisitExpression(Expression* exp);
string graphVisitExpList(ExpList* expList);
string graphVisitDecList(DecList* decList);
string graphVisitLVal(LVal* lVal);
string graphVisitArgList(ArgList* argList);
string graphVisitFieldExpList(FieldExpList* fieldExpList);
string graphVisitDec(Dec* dec);
string graphVisitTy(Ty* ty);
string graphVisitFieldList(FieldList* fieldList);

string graphVisitExpression(Expression* exp)
{
    string curID = toStr(exp -> getID());
    string tmpStr;
    if (!exp) return string("");
    switch(exp->getExpType()) {
        case E_LValue:
            return graphVisitLVal(((ExpLValue*)exp)->lValue);
            break;
        case E_Integer:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Integer | " << toStr(((ExpInteger*)exp)->num) << " } }\"];" << endl;
            return curID + ":ptr";
            break;
        case E_Nil:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Nil } }\"];" << endl;
            return curID + ":ptr";
            break;
        case E_String:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ String | " << ((ExpString*)exp)->str << " } }\"];" << endl;
            return curID + ":ptr";
            break;
        case E_FuncCall:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Function Call | " << ((ExpFuncCall*)exp)->funcName << " | <argpos> Arguments} }\"];" << endl;
            tmpStr = graphVisitArgList(((ExpFuncCall*)exp)->argList);
            cout << curID << ":argpos" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_BinOp:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Binary Operation | <exp0> Expression 0 | " << binOpToStrEsc(((ExpBinOp*)exp)->binOp);
            //cout << "{ Binary Operation | <exp0> Expression 0 | " << "XX";
            cout << " | <exp1> Expression 1} }\"];" << endl;
            tmpStr = graphVisitExpression(((ExpBinOp*)exp)->exp0);
            cout << curID << ":exp0" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpression(((ExpBinOp*)exp)->exp1);
            cout << curID << ":exp1" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_UnOp:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Uni-Operation | " << unOpToStr(((ExpUnOp*)exp)->unOp) + " ";
            cout << " | <exp> Expression} }\"];" << endl;
            tmpStr = graphVisitExpression(((ExpUnOp*)exp)->exp);
            cout << curID << ":exp" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_Record:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Record | " << ((ExpRecord*)exp)->typeName << " | <flistpos> Field List} }\"];" << endl;
            tmpStr = graphVisitFieldExpList(((ExpRecord*)exp)->fieldExpList);
            cout << curID << ":flistpos" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_ExpList:
            return graphVisitExpList(((ExpExpList*)exp)->expList);
            break;
        case E_Assign:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Assignment | <lval> LHS | <rhs> RHS } } \"];" << endl;
            tmpStr = graphVisitLVal(((ExpAssign*)exp)->lValue);
            cout << curID << ":lval" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpression(((ExpAssign*)exp)->rhsValue);
            cout << curID << ":rhs" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_If:
            if (((ExpIf*)exp)->hasElse) {
                cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
                cout << "{ If | <cond> Condition | <stmt> Statement } } \"];" << endl;
                tmpStr = graphVisitExpression(((ExpIf*)exp)->cond);
                cout << curID << ":cond" << " -> " << tmpStr << endl;
                tmpStr = graphVisitExpression(((ExpIf*)exp)->trueStatement);
                cout << curID << ":stmt" << " -> " << tmpStr << endl;
                return curID + ":ptr";
            } else {
                cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
                cout << "{ If | <cond> Condition | <tstmt> True Statement | <fstmt> False Statement } } \"];" << endl;
                tmpStr = graphVisitExpression(((ExpIf*)exp)->cond);
                cout << curID << ":cond" << " -> " << tmpStr << endl;
                tmpStr = graphVisitExpression(((ExpIf*)exp)->trueStatement);
                cout << curID << ":tstmt" << " -> " << tmpStr << endl;
                tmpStr = graphVisitExpression(((ExpIf*)exp)->falseStatement);
                cout << curID << ":fstmt" << " -> " << tmpStr << endl;
                return curID + ":ptr";
            }
            break;
        case E_While:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ While Loop | <cond> Condition | <stmt> Statement } } \"];" << endl;
            tmpStr = graphVisitExpression(((ExpWhile*)exp)->cond);
            cout << curID << ":cond" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpression(((ExpWhile*)exp)->loopStatement);
            cout << curID << ":stmt" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_For:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ For Loop | <forvar> Varible [" << ((ExpFor*)exp)->loopVar << "] ";
            cout << "| <beg> Begin Value | <ed> End Value | <stmt> Statement } } \"];" << endl;
            tmpStr = graphVisitExpression(((ExpFor*)exp)->beg);
            cout << curID << ":beg" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpression(((ExpFor*)exp)->end);
            cout << curID << ":ed" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpression(((ExpFor*)exp)->loopStatement);
            cout << curID << ":stmt" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_Break:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Break }\"];" << endl;
            return curID + ":ptr";
            break;
        case E_Let:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Let | <dec> Declaration | <stmt> Statement } } \"];" << endl;
            tmpStr = graphVisitDecList(((ExpLet*)exp)->decList);
            cout << curID << ":dec" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpList(((ExpLet*)exp)->expList);
            cout << curID << ":stmt" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        case E_Array:
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Array | Type [" << ((ExpArray*)exp)->typeName << "] | <sz> Size | <ival> Initial Value} } \"];" << endl;
            tmpStr = graphVisitExpression(((ExpArray*)exp)->expSize);
            cout << curID << ":sz" << " -> " << tmpStr << endl;
            tmpStr = graphVisitExpression(((ExpArray*)exp)->expInitVal);
            cout << curID << ":ival" << " -> " << tmpStr << endl;
            return curID + ":ptr";
            break;
        default:
            return string("WRONG_EXPRESSION");
    }
}

string graphVisitExpList(ExpList* expList)
{
    string curID;
    curID = toStr(expList -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Expression List | " + curID + " } ";
    for(int i = 0; i < expList->size(); ++ i) {
        result += "| { " + toStr(i) + " | <pos" + toStr(i) + "> Expression }";
        tmpStr = graphVisitExpression((*expList)[i]);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";" << endl;
    }
    if (expList->size() == 0) {
        result += "| {Expression List Empty}";
    }
    result += " }\"];";
    cout << result << endl;
    return curID + ":ptr";
}

string graphVisitDecList(DecList* decList)
{
    string curID;
    curID = toStr(decList -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Declartion List | " + curID + " } ";
    for(int i = 0; i < decList->size(); ++ i) {
        result += "| { " + toStr(i) + " | <pos" + toStr(i) + "> Declartion }";
        tmpStr = graphVisitDec((*decList)[i]);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";" << endl;
    }
    if (decList->size() == 0) {
        result += "| {Declartion List Empty}";
    }
    result += " }\"];";
    cout << result << endl;
    return curID + ":ptr";
}

string graphVisitLVal(LVal* lVal)
{
    string curID;
    curID = toStr(lVal -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Left Hand Value | " + curID + " } ";
    switch(lVal->getLValType()) {
        case L_ID:
            result += "| { ID | " + ((LValID*)lVal)->lValName + " } } \"];";
            cout << result << endl;
            return curID + ":ptr";
            break;
        case L_Member:
            result += "| { Member Reference | <maj> Major Name | ";
            result += "Member Name" + ((LValMember*)lVal)->memberName + "} } \"];";
            cout << result << endl;
            tmpStr = graphVisitLVal(((LValMember*)lVal)->major);
            cout << curID << ":maj -> " << tmpStr << ";" << endl;
            return curID + ":ptr";
            break;
        case L_Element:
            result += "| { Element Reference | <maj> Major Name | <idx> Index } } \"];";
            cout << result << endl;
            tmpStr = graphVisitLVal(((LValElement*)lVal)->major);
            cout << curID << ":maj -> " << tmpStr << ";" << endl;
            tmpStr = graphVisitExpression(((LValElement*)lVal)->idx);
            cout << curID << ":idx -> " << tmpStr << ";" << endl;
            return curID + ":ptr";
            break;
        default:
            return "WRONG_LVALUE";
    }
}

string graphVisitArgList(ArgList* argList)
{
    string curID;
    curID = toStr(argList -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Argument List | " + curID + " } ";
    for(int i = 0; i < argList->size(); ++ i) {
        result += "| { " + toStr(i) + " | <pos" + toStr(i) + "> Argument }";
        tmpStr = graphVisitExpression((*argList)[i]);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";" << endl;
    }
    if (argList->size() == 0) {
        result += "| {Argument List Empty}";
    }
    result += " }\"];";
    cout << result << endl;
    return curID + ":ptr";
}

string graphVisitFieldExpList(FieldExpList* fieldExpList)
{
    string curID;
    curID = toStr(fieldExpList -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Field Expression List | " + curID + " } ";
    for(int i = 0; i < fieldExpList->size(); ++ i) {
        FieldExpEle cur = (*fieldExpList)[i];
        result += "| { " + toStr(i) + " | " + cur.first + " | ";
        result += "<pos" + toStr(i) + "> Expression }";
        tmpStr = graphVisitExpression(cur.second);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";" << endl;
    }
    if (fieldExpList->size() == 0) {
        result += "| {Field Expression List Empty}";
    }
    result += " }\"];";
    cout << result << endl;
    return curID + ":ptr";
}

string graphVisitDec(Dec* dec)
{
    string curID;
    curID = toStr(dec -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Declartion | " + curID + " } ";
    switch(dec->getDecType()) {
        case D_Var:
            if (((VarDec*)dec)->hasType) {
                result += "| {Variable | " + ((VarDec*)dec)->varName + " | " + "Type " + ((VarDec*)dec)->typeName;
                result += " | <initval> Initial Value } }\"];";
                cout << result << endl;
                tmpStr = graphVisitExpression(((VarDec*)dec)->initVal);
                cout << curID << ":initval -> " << tmpStr << ";" << endl;
            } else {
                result += "| {Variable | " + ((VarDec*)dec)->varName;
                result += " | <initval> Initial Value } }\"];";
                cout << result << endl;
                tmpStr = graphVisitExpression(((VarDec*)dec)->initVal);
                cout << curID << ":initval -> " << tmpStr << ";" << endl;
            }
            return curID + ":ptr";
            break;
        case D_Func:
            if (((FuncDec*)dec)->hasReturn) {
                result += "| {Function | " + ((FuncDec*)dec)->funcName + " | " + "Type " + ((FuncDec*)dec)->typeName;
                result += " | <exp> Expression } }\"];";
                cout << result << endl;
                tmpStr = graphVisitExpression(((FuncDec*)dec)->body);
                cout << curID << ":exp -> " << tmpStr << ";" << endl;
                return curID + ":ptr";
            } else {
                result += "| {Function | " + ((FuncDec*)dec)->funcName;
                result += " | <exp> Expression } }\"];";
                cout << result << endl;
                return curID + ":ptr";
            }
            break;
        case D_Type:
            result += "| {Type | Name " + ((TyDec*)dec)->typeName;
            result += " | <ty> Type } }\"];";
            cout << result << endl;
            tmpStr = graphVisitTy(((TyDec*)dec)->ty);
            cout << curID << ":ty -> " << tmpStr << ";" << endl;
            return curID + ":ptr";
            break;
        default:
            return string("WRONG_DECLARATION");
    }
}

string graphVisitTy(Ty* ty)
{
    string curID;
    curID = toStr(ty -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Type | " + curID + " } ";
    switch (ty->tyType) {
        case TY_ID:
            result += "| { Name | " + ty->tyName + " } } \"];";
            cout << result << endl;
            return curID + ":ptr";
            break;
        case TY_Array:
            result += "| { Array | " + ty->tyName + " } } \"];";
            cout << result << endl;
            return curID + ":ptr";
            break;
        case TY_Record:
            result += "| { Record | <flist> Field List } } \"];";
            tmpStr = graphVisitFieldList(ty->fieldList);
            cout << result << endl;
            cout << curID << ":flist -> " << tmpStr << ";" << endl;
            return curID + ":ptr";
            break;
        default:
            return string("WRONG_TY");
    }
}

string graphVisitFieldList(FieldList* fieldList)
{
    string curID;
    curID = toStr(fieldList -> getID());
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Field Expression List | " + curID + " } ";
    for(int i = 0; i < fieldList->size(); ++ i) {
        FieldEle cur = (*fieldList)[i];
        result += "| { " + toStr(i) + " | " + cur.first + " | " + cur.second + " }";
    }
    if (fieldList->size() == 0) {
        result += "| {Field List Empty}";
    }
    result += " }\"]";
    cout << result << endl;
    return curID + ":ptr";
}

int main()
{
    yyparse();
    cout << "digraph ast {" << endl;
    graphVisitExpression(root);
    cout << "}" << endl;
}

