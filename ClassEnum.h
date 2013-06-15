#ifndef CLASSENUM_H_
#define CLASSENUM_H_

enum NodeType {
    N_Exp,
    N_Dec,
    N_Ty,
    N_IdSqB,
    N_LValue,
    N_ExpList,
    N_ArgList,
    N_DecList,
    N_FieldExpList,
    N_FieldList
};

enum ExpNodeType {
    E_LValue,
    E_Integer,
    E_Nil,
    E_String,
    E_FuncCall,
    E_BinOp,
    E_UnOp,
    E_Negative,
    E_Record,
    E_Assign,
    E_ExpList,
    E_If,
    E_While,
    E_For,
    E_Break,
    E_Let,
    E_Array
};

enum DecNodeType {
    D_Type,
    D_Var,
    D_Func
};

enum LValNodeType {
    L_ID,
    L_Member,
    L_Element
};

enum TyType {
    TY_None,
    TY_ID,
    TY_Array,
    TY_Record
};

enum BinOpType {
    BO_None,
    BO_Mul,
    BO_Div,
    BO_Plus,
    BO_Minus,
    BO_Neq,
    BO_LT,
    BO_LTE,
    BO_GT,
    BO_GTE,
    BO_Equal,
    BO_And,
    BO_Or
};

enum UnOpType {
    UO_None,
    UO_Neg
};

typedef unsigned int IDType;

#endif // CLASSENUM_H_
