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

int gNodeTot = 0;
string getNewNodeID()
{
    return toStr(gNodeTot++);
}

string addEdge(string node1, string node2)
{
    cout << node1 + " -> " + node2;
}

string graphVisitExpression(Expression* exp)
{
    string curID;
    string strTmp;
    if (!exp) return string("");
    switch(exp->getExpType()) {
        case E_LValue:
            return graphVisitLVal(((ExpLValue*)exp)->lValue);
            break;
        case E_Integer:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Integer | " << toStr(((ExpInteger*)exp)->num) << " }\"]";
            return curID + ":ptr";
            break;
        case E_Nil:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{ Nil }\"]";
            return curID + ":ptr";
            break;
        case E_String:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Integer | " << ((ExpString*)exp)->str << " }\"]";
            return curID + ":ptr";
            break;
        case E_FuncCall:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Function Call | " << ((ExpFuncCall*)exp)->funcName << " | <argpos> Arguments} }\"]";
            cout << curID << ":argpos" << " -> " << graphVisitArgList(((ExpFuncCall*)exp)->argList);
            return curID + ":ptr";
            break;
        case E_BinOp:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Binary Operation | <exp0> Expression 0 | " << binOpToStr(((ExpBinOp*)exp)->binOp);
            cout << " | <exp1> Expression 1} }\"]";
            cout << curID << ":exp0" << " -> " << graphVisitExpression(((ExpBinOp*)exp)->exp0);
            cout << curID << ":exp1" << " -> " << graphVisitExpression(((ExpBinOp*)exp)->exp1);
            return curID + ":ptr";
            break;
        case E_UnOp:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Uni-Operation | " << unOpToStr(((ExpUnOp*)exp)->unOp) + " ";
            cout << " | <exp> Expression} }\"]";
            cout << curID << ":exp" << " -> " << graphVisitExpression(((ExpUnOp*)exp)->exp);
            return curID + ":ptr";
            break;
        case E_Record:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Record | " << ((ExpRecord*)exp)->typeName << " | <flistpos> Field List} }\"]";
            cout << curID << ":argpos" << " -> " << graphVisitFieldExpList(((ExpRecord*)exp)->fieldExpList);
            return curID + ":ptr";
            break;
        case E_ExpList:
            return graphVisitExpList(((ExpExpList*)exp)->expList);
            break;
        case E_Assign:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{Assignment | <lval> LHS | <rhs> RHS } } \""
            cout << curID << ":lval" << " -> " << graphVisitLVal(((ExpAssign*)exp)->lValue);
            cout << curID << ":rhs" << " -> " << graphVisitExpression(((ExpAssign*)exp)->rhsValue);
            return curID + ":ptr";
            break;
        case E_If:
            if (((ExpIf*)exp)->hasElse) {
                curID = getNewNodeID();
                cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
                cout << "{If | <cond> Condition | <stmt> Statement } } \"";
                cout << curID << ":cond" << " -> " << graphVisitExpression(((ExpIf*)exp)->cond);
                cout << curID << ":stmt" << " -> " << graphVisitExpression(((ExpIf*)exp)->trueStatement);
                return curID + ":ptr";
            } else {
                curID = getNewNodeID();
                cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
                cout << "{If | <cond> Condition | <tstmt> True Statement | <fstmt> False Statement } } \"";
                cout << curID << ":cond" << " -> " << graphVisitExpression(((ExpIf*)exp)->cond);
                cout << curID << ":tstmt" << " -> " << graphVisitExpression(((ExpIf*)exp)->trueStatement);
                cout << curID << ":fstmt" << " -> " << graphVisitExpression(((ExpIf*)exp)->falseStatement);
                return curID + ":ptr";
            }
            break;
        case E_While:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{While Loop | <cond> Condition | <stmt> Statement } } \"";
            cout << curID << ":cond" << " -> " << graphVisitExpression(((ExpWhile*)exp)->cond);
            cout << curID << ":stmt" << " -> " << graphVisitExpression(((ExpWhile*)exp)->loopStatement);
            return curID + ":ptr";
            break;
        case E_For:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |";
            cout << "{For Loop | <forvar> Varible [" << ((ExpFor*)exp)->loopVar << "] ";
            cout << "| <beg> Begin Value | <ed> End Value | <stmt> Statement } } \"";
            cout << curID << ":beg" << " -> " << graphVisitExpression(((ExpFor*)exp)->beg);
            cout << curID << ":ed" << " -> " << graphVisitExpression(((ExpFor*)exp)->end);
            cout << curID << ":stmt" << " -> " << graphVisitExpression(((ExpFor*)exp)->loopStatement);
            return curID + ":ptr";
            break;
        case E_Break:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |"
            cout << "{ Break }\"]";
            return curID + ":ptr";
            break;
        case E_Let:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |"
            cout << "{Let | <dec> Declaration | <stmt> Statement } } \"" << endl;
            cout << curID << ":dec" << " -> " << graphVisitDecList(((ExpLet*)exp)->decList);
            cout << curID << ":stmt" << " -> " << graphVisitExpList(((ExpLet*)exp)->expList);
            return curID + ":ptr";
            break;
        case E_Array:
            curID = getNewNodeID();
            cout << curID << " [shape=record, label=\"{ { <ptr> Expression | " << curID << " } |"
            cout << "{Array | Type [" << ((ExpArray*)exp)->typeName << "] | <sz> Size | <ival> Initial Value} } \"" << endl;
            cout << curID << ":sz" << " -> " << graphVisitExpression(((ExpArray*)exp)->expSize);
            cout << curID << ":ival" << " -> " << graphVisitExpression(((ExpArray*)exp)->expInitVal);
            return curID + ":ptr";
            break;
        default:
            return string("WRONG_EXPRESSION");
    }
}

string graphVisitExpList(ExpList* expList)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Expression List | " << curID << " } ";
    for(int i = 0; i < expList->size(); ++ i) {
        result += "| { " + toStr(i) + " | <pos" + toStr(i) + "> Expression }";
        tmpStr = graphVisitExpression((*expList)[i]);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";";
    }
    if (expList->size() == 0) {
        result += "| {Expression List Empty}";
    }
    result += " }\"]";
    cout << result;
    return curID + ":ptr";
}

string graphVisitDecList(DecList* decList)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Declartion List | " << curID << " } ";
    for(int i = 0; i < decList->size(); ++ i) {
        result += "| { " + toStr(i) + " | <pos" + toStr(i) + "> Declartion }";
        tmpStr = graphVisitDec((*decList)[i]);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";";
    }
    if (decList->size() == 0) {
        result += "| {Declartion List Empty}";
    }
    result += " }\"]";
    cout << result;
    return curID + ":ptr";
}

string graphVisitLVal(LVal* lVal)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Left Hand Value | " + curID + " } ";
    switch(lVal->getLValType()) {
        case L_ID:
            result += "| { ID | " + ((LValID*)lVal)->lValName + " } } \"]";
            cout << result << endl;
            return curID + ":ptr";
            break;
        case L_Member:
            result += "| { Member Reference | <maj> Major Name | <mbr> Member Name } } \"]";
            cout << result << endl;
            tmpStr = graphVisitLVal(((LValMember*)lVal)->major);
            cout << curID << ":maj -> " << tmpStr << ";";
            tmpStr = ((LValMember*)lVal)->memberName;
            cout << curID << ":mbr -> " << tmpStr << ";";
            return curID + ":ptr";
            break;
        case L_Element:
            result += "| { Element Reference | <maj> Major Name | <idx> Index } } \"]";
            cout << result << endl;
            tmpStr = graphVisitLVal(((LValElement*)lVal)->major);
            cout << curID << ":maj -> " << tmpStr << ";";
            tmpStr = graphVisitExpression(((LValElement*)lVal)->idx);
            cout << curID << ":idx -> " << tmpStr << ";";
            return curID + ":ptr";
            break;
        default:
            return "WRONG_LVALUE";
    }
}

string graphVisitArgList(ArgList* argList)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Argument List | " << curID << " } ";
    for(int i = 0; i < argList->size(); ++ i) {
        result += "| { " + toStr(i) + " | <pos" + toStr(i) + "> Argument }";
        tmpStr = graphVisitExpression((*argList)[i]);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";";
    }
    if (argList->size() == 0) {
        result += "| {Argument List Empty}";
    }
    result += " }\"]";
    cout << result;
    return curID + ":ptr";
}

string graphVisitFieldExpList(FieldExpList* fieldExpList)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Field Expression List | " << curID << " } ";
    for(int i = 0; i < fieldExpList->size(); ++ i) {
        FieldExpEle cur = (*fieldExpList)[i];
        result += "| { " + toStr(i) + " | " + cur.first + " | ";
        result += "<pos" + toStr(i) + "> Expression }";
        tmpStr = graphVisitExpression(cur.second);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";";
    }
    if (argList->size() == 0) {
        result += "| {Field Expression List Empty}";
    }
    result += " }\"]";
    cout << result;
    return curID + ":ptr";
}

string graphVisitDec(Dec* dec)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Declartion | " + curID + " } ";
    switch(dec->getDecType()) {
        case D_Var:
            rtn += ((VarDec*)dec)->varName;
            if (((VarDec*)dec)->hasType) {
                result += "| {Variable | " + ((VarDec*)dec)->varName + " | " + "Type " + ((VarDec*)dec)->typeName;
                result += " | <initval> Initial Value } }\"]";
                cout << result << endl;
                tmpStr = graphVisitExpression(((VarDec*)dec)->initVal);
                cout << curID << ":initval -> " << tmpStr << ";";
            } else {
                result += "| {Variable | " + ((VarDec*)dec)->varName;
                result += " | <initval> Initial Value } }\"]";
                cout << result << endl;
                tmpStr = graphVisitExpression(((VarDec*)dec)->initVal);
                cout << curID << ":initval -> " << tmpStr << ";";
            }
            return curID + ":pos";
            break;
        case D_Func:
            if (((FuncDec*)dec)->hasReturn) {
                result += "| {Function | " + ((FuncDec*)dec)->funcName + " | " + "Type " + ((FuncDec*)dec)->typeName;
                result += " | <exp> Expression } }\"]";
                cout << result << endl;
                tmpStr = graphVisitExpression(((FuncDec*)dec)->body);
                cout << curID << ":exp -> " << tmpStr << ";";
                return curID + ":pos";
            } else {
                result += "| {Function | " + ((FuncDec*)dec)->funcName;
                result += " | <exp> Expression } }\"]";
                cout << result << endl;
                return curID + ":pos";
            }
            break;
        case D_Type:
            result += "| {Type | Name " + ((TyDec*)dec)->typeName;
            result += " | <ty> Type } }\"]";
            cout << result << endl;
            tmpStr = graphVisitTy(((TyDec*)dec)->ty);
            cout << curID << ":ty -> " << tmpStr << ";";
            break;
        default:
            return string("WRONG_DECLARATION");
    }
}

string graphVisitTy(Ty* ty)
{
    string curID;
    curID = getNewNodeID();
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
            cout << curID << ":flist -> " << tmpStr << ";";
            return curID + ":ptr";
            break;
        default:
            return string("WRONG_TY");
    }
}

string graphVisitFieldList(FieldList* fieldList)
{
    string curID;
    curID = getNewNodeID();
    string result;
    string tmpStr;
    result = curID + " [shape=record, label=\"{ { <ptr> Field Expression List | " << curID << " } ";
    for(int i = 0; i < fieldList->size(); ++ i) {
        FieldEle cur = (*fieldList)[i];
        result += "| { " + toStr(i) + " | " + cur.first + " | " + cur.second + " }";
        tmpStr = graphVisitExpression(cur.second);
        cout << curID << ":pos" + toStr(i) + " -> " << tmpStr << ";";
    }
    if (argList->size() == 0) {
        result += "| {Field List Empty}";
    }
    result += " }\"]";
    cout << result;
    return curID + ":ptr";
}

int main()
{
    yyparse();
    graphVisitExpression(root);
}

