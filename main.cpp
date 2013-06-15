#include "ASTClass.h"
#include "Parser.h"
#include "utilities.h"
#include <iostream>
#include <string>

using namespace std;

extern Expression* root;
Expression* root = NULL;
int indent;
bool expListNewLine = false;

string strVisitExpression(Expression* exp);
string strVisitExpList(ExpList* expList);
string strVisitDecList(DecList* decList);
string strVisitLVal(LVal* lVal);
string strVisitArgList(ArgList* argList);
string strVisitFieldExpList(FieldExpList* fieldExpList);
string strVisitDec(Dec* dec);
string strVisitTy(Ty* ty);
string strVisitFieldList(FieldList* fieldList);

string strVisitExpression(Expression* exp)
{
    bool lastExpListNewLine = false;
    if (!exp) return string("");
    string rtn;
    switch(exp->getExpType()) {
        case E_LValue:
            return strVisitLVal(((ExpLValue*)exp)->lValue);
            break;
        case E_Integer:
            return toStr(((ExpInteger*)exp)->num);
            break;
        case E_Nil:
            return string("nil");
            break;
        case E_String:
            return "\"" + ((ExpString*)exp)->str + "\"";
            break;
        case E_FuncCall:
            rtn = ((ExpFuncCall*)exp)->funcName;
            rtn += "(";
            rtn += strVisitArgList(((ExpFuncCall*)exp)->argList);
            rtn += ")";
            return rtn;
            break;
        case E_BinOp:
            rtn = strVisitExpression(((ExpBinOp*)exp)->exp0);
            rtn += " " + binOpToStr(((ExpBinOp*)exp)->binOp) + " ";
            rtn += strVisitExpression(((ExpBinOp*)exp)->exp1);
            return rtn;
            break;
        case E_UnOp:
            rtn = unOpToStr(((ExpUnOp*)exp)->unOp) + " ";
            rtn += strVisitExpression(((ExpUnOp*)exp)->exp);
            return rtn;
            break;
        case E_Record:
            rtn = ((ExpRecord*)exp)->typeName;
            rtn += "{";
            rtn += strVisitFieldExpList(((ExpRecord*)exp)->fieldExpList);
            rtn += "}";
            return rtn;
            break;
        case E_ExpList:
            rtn = "(" + strVisitExpList(((ExpExpList*)exp)->expList) + ")";
            return rtn;
            break;
        case E_Assign:
            rtn = strVisitLVal(((ExpAssign*)exp)->lValue);
            rtn += " := ";
            rtn += strVisitExpression(((ExpAssign*)exp)->rhsValue);
            return rtn;
            break;
        case E_If:
            rtn = "if " + strVisitExpression(((ExpIf*)exp)->cond) + " then\n";
            ++ indent;
            rtn += makeIndent(indent) + strVisitExpression(((ExpIf*)exp)->trueStatement) + "\n";
            -- indent;
            if (((ExpIf*)exp)->hasElse) {
                rtn += makeIndent(indent) + "else\n";
                ++ indent;
                rtn += makeIndent(indent) + strVisitExpression(((ExpIf*)exp)->falseStatement);
                -- indent;
            }
            return rtn;
            break;
        case E_While:
            rtn = "while " + strVisitExpression(((ExpWhile*)exp)->cond) + " do\n";
            ++ indent;
            rtn += makeIndent(indent) + strVisitExpression(((ExpWhile*)exp)->loopStatement) + "\n";
            -- indent;
            return rtn;
            break;
        case E_For:
            rtn = "for " + ((ExpFor*)exp)->loopVar + " := ";
            rtn += strVisitExpression(((ExpFor*)exp)->beg);
            rtn += " to ";
            rtn += strVisitExpression(((ExpFor*)exp)->end);
            rtn += " do\n";
            ++ indent;
            rtn += makeIndent(indent);
            rtn += strVisitExpression(((ExpFor*)exp)->loopStatement);
            --indent;
            return rtn;
            break;
        case E_Break:
            return string("break");
            break;
        case E_Let:
            rtn = "let\n";
            ++ indent;
            rtn += makeIndent(indent);
            rtn += strVisitDecList(((ExpLet*)exp)->decList);
            -- indent;
            rtn += "\n" + makeIndent(indent) + "in\n";
            ++ indent;
            rtn += makeIndent(indent);
            lastExpListNewLine = expListNewLine;
            expListNewLine = true;
            rtn += strVisitExpList(((ExpLet*)exp)->expList);
            expListNewLine = lastExpListNewLine;
            -- indent;
            rtn += "\n" + makeIndent(indent) + "end";
            return rtn;
            break;
        case E_Array:
            rtn = ((ExpArray*)exp)->typeName;
            rtn += "[" + strVisitExpression(((ExpArray*)exp)->expSize) + "]";
            rtn += " of " + strVisitExpression(((ExpArray*)exp)->expInitVal);
            return rtn;
            break;
        default:
            return string("WRONG_EXPRESSION");
    }
}

string strVisitExpList(ExpList* expList)
{
    string rtn;
    for(int i = 0; i < expList->size(); ++ i) {
        rtn += strVisitExpression((*expList)[i]);
        if (i != expList->size() - 1) {
            rtn += ";";
            if (expListNewLine) {
                rtn += "\n" + makeIndent(indent);
            } else {
                rtn += " ";
            }
        }
    }
    return rtn;
}

string strVisitDecList(DecList* decList)
{
    string rtn;
    for(int i = 0; i < decList->size(); ++ i) {
        rtn += strVisitDec((*decList)[i]);
        if (i != decList->size() - 1) {
            rtn += "\n";
            rtn += makeIndent(indent);
        }
    }
    return rtn;
}

string strVisitLVal(LVal* lVal)
{
    string rtn;
    switch(lVal->getLValType()) {
        case L_ID:
            return ((LValID*)lVal)->lValName;
            break;
        case L_Member:
            rtn = strVisitLVal(((LValMember*)lVal)->major);
            rtn += ".";
            rtn += ((LValMember*)lVal)->memberName;
            return rtn;
            break;
        case L_Element:
            rtn = strVisitLVal(((LValElement*)lVal)->major);
            rtn += "[";
            rtn += strVisitExpression(((LValElement*)lVal)->idx);
            rtn += "]";
            return rtn;
            break;
        default:
            return "WRONG_LVALUE";
    }
}

string strVisitArgList(ArgList* argList)
{
    string rtn;
    for(int i = 0; i < argList->size(); ++ i) {
        rtn += strVisitExpression((*argList)[i]);
        if (i != argList->size() - 1) {
            rtn += ", ";
        }
    }
    return rtn;
}

string strVisitFieldExpList(FieldExpList* fieldExpList)
{
    string rtn;
    for(int i = 0; i < fieldExpList->size(); ++ i) {
        FieldExpEle cur = (*fieldExpList)[i];
        rtn += cur.first + " = " + strVisitExpression(cur.second);
        if (i != fieldExpList->size() - 1) {
            rtn += ", ";
        }
    }
    return rtn;
}

string strVisitDec(Dec* dec)
{
    string rtn = "";
    switch(dec->getDecType()) {
        case D_Var:
            rtn = "var ";
            rtn += ((VarDec*)dec)->varName;
            if (((VarDec*)dec)->typeName != "") {
                rtn += " : ";
                rtn += ((VarDec*)dec)->typeName;
            }
            rtn += " := ";
            rtn += strVisitExpression(((VarDec*)dec)->initVal);
            return rtn;
            break;
        case D_Func:
            rtn = "function ";
            rtn += ((FuncDec*)dec)->funcName;
            rtn += "(";
            rtn += strVisitFieldList(((FuncDec*)dec)->fieldList);
            rtn += ")";
            if (((FuncDec*)dec)->hasReturn) {
                rtn += " : ";
                rtn += ((FuncDec*)dec)->typeName;
            }
            rtn += " = \n";
            ++ indent;
            rtn += makeIndent(indent);
            rtn += strVisitExpression(((FuncDec*)dec)->body);
            -- indent;
            return rtn;
            break;
        case D_Type:
            rtn = "type ";
            rtn += ((TyDec*)dec)->typeName;
            rtn += " = ";
            rtn += strVisitTy(((TyDec*)dec)->ty);
            return rtn;
            break;
        default:
            return string("WRONG_DECLARATION");
    }
}

string strVisitTy(Ty* ty)
{
    string rtn = "";
    switch (ty->tyType) {
        case TY_ID:
            return ty->tyName;
            break;
        case TY_Array:
            rtn = "array of " + ty->tyName;
            return rtn;
            break;
        case TY_Record:
            rtn = "{";
            rtn += strVisitFieldList(ty->fieldList);
            rtn += "}";
            return rtn;
            break;
        default:
            return string("WRONG_TY");
    }
}

string strVisitFieldList(FieldList* fieldList)
{
    string rtn;
    for(int i = 0; i < fieldList->size(); ++ i) {
        FieldEle cur = (*fieldList)[i];
        rtn += cur.first + " : " + cur.second;
        if (i != fieldList->size() - 1) {
            rtn += ", ";
        }
    }
    return rtn;
}

int main()
{
    yyparse();
    cout << strVisitExpression(root);
}

