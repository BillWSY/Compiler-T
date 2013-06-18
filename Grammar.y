%{
#include <stdio.h>
#include <string.h>
#include "ASTClass.h"
#include "utilities.h"
#include <string>

using namespace std;

extern Expression* root;

extern int yylex();
extern string linebuf;

void yyerror(const char *str);

/*
int main()
{
    yyparse();
}
*/

IDType BasicNode::idCnt = 0;

%}

%union {
    string *strPtr;
    TInt integer;
    Expression* exp;
    Dec* dec;
    IdSqB* idSqB;
    LVal* lVal;
    ExpList* expList;
    ArgList* argList;
    FieldList* fieldList;
    FieldExpList* fieldExpList;
    DecList* decList;
    Ty* ty;
    BinOpType binOpType;
    UnOpType unOpType;
};

%error-verbose
%locations

%token TOK_ARRAY TOK_BREAK TOK_DO TOK_ELSE TOK_END
%token TOK_FOR TOK_FUNCTION TOK_IF TOK_IN TOK_LET
%token TOK_NIL TOK_OF TOK_THEN TOK_TO TOK_TYPE
%token TOK_VAR TOK_WHILE TOK_PLUS_SIGN TOK_MINUS_SIGN TOK_MULT_SIGN
%token TOK_DIV_SIGN TOK_AND TOK_OR TOK_EQUALS TOK_NEQ
%token TOK_LT TOK_LTE TOK_GT TOK_GTE TOK_ASSIGN
%token TOK_SEMIC TOK_COMMA TOK_COLON TOK_DOT TOK_LBR
%token TOK_RBR TOK_LSQB TOK_RSQB TOK_LCURLB TOK_RCURLB
%token <integer> TOK_INTEGER
%token <strPtr> TOK_ID
%token <strPtr> TOK_STRING

%type <exp> Prog Exp SqBExp
%type <decList> DecList
%type <dec> Dec TyDec VarDec FuncDec
%type <ty> Ty
%type <idSqB> IdSqB
%type <lVal> LValue
%type <expList> ExpList
%type <argList> ArgList
%type <fieldList> FieldList
%type <fieldExpList> FieldExpList
%type <binOpType> BinOp_L1 BinOp_L2 BinOp_L3 BinOp_L4 BinOp_L5
%type <unOpType> UnOp

%nonassoc EXP_REDUCE_PREC
%nonassoc TOK_LSQB

%nonassoc IF_WO_ELSE_PREC
%nonassoc TOK_ELSE

%nonassoc TOK_ASSIGN
%left TOK_OR
%left TOK_AND
%nonassoc TOK_EQUALS TOK_NEQ TOK_LT TOK_LTE TOK_GT TOK_GTE
%left TOK_PLUS_SIGN TOK_MINUS_SIGN
%left TOK_MULT_SIGN TOK_DIV_SIGN
%nonassoc UNIOP_PREC

%destructor { /* Don't destroy this */ } Prog
%destructor { if($$) delete $$; $$ = NULL; } <exp><decList><dec><ty><idSqB><lVal><expList><argList><fieldList><fieldExpList><strPtr>

%%

Prog            :       Exp
                        {
                            root = $$ = $1;
                        }
                ;

Exp             :       LValue
                        {
                            $$ = (Expression*) new ExpLValue($1);
                        }
                |       TOK_INTEGER
                        {
                            $$ = (Expression*) new ExpInteger($1);
                        }
                |       TOK_NIL
                        {
                            $$ = (Expression*) new ExpNil();
                        }
                |       TOK_STRING
                        {
                            $$ = (Expression*) new ExpString(*$1);
                            delete $1; $1 = NULL;
                        }
                |       TOK_ID TOK_LBR ArgList TOK_RBR
                        {
                            $$ = (Expression*) new ExpFuncCall(*$1, $3);
                            delete $1; $1 = NULL;
                        }
                |       Exp BinOp_L1 Exp                                        %prec TOK_MULT_SIGN
                        {
                            $$ = (Expression*) new ExpBinOp($1, $3, $2);
                        }
                |       Exp BinOp_L2 Exp                                        %prec TOK_PLUS_SIGN
                        {
                            $$ = (Expression*) new ExpBinOp($1, $3, $2);
                        }
                |       Exp BinOp_L3 Exp                                        %prec TOK_NEQ
                        {
                            $$ = (Expression*) new ExpBinOp($1, $3, $2);
                        }
                |       Exp BinOp_L4 Exp                                        %prec TOK_AND
                        {
                            $$ = (Expression*) new ExpBinOp($1, $3, $2);
                        }
                |       Exp BinOp_L5 Exp                                        %prec TOK_OR
                        {
                            $$ = (Expression*) new ExpBinOp($1, $3, $2);
                        }
                |       UnOp Exp                                                %prec UNIOP_PREC
                        {
                            $$ = (Expression*) new ExpUnOp($2, $1);
                        }
                |       TOK_ID TOK_LCURLB FieldExpList TOK_RCURLB
                        {
                            $$ = (Expression*) new ExpRecord(*$1, $3);
                            delete $1; $1 = NULL;
                        }
                |       TOK_LBR ExpList TOK_RBR
                        {
                            $$ = (Expression*) new ExpExpList($2);
                        }
                |       LValue TOK_ASSIGN Exp                                   %prec EXP_REDUCE_PREC
                        {
                            $$ = (Expression*) new ExpAssign($1, $3);
                        }
                |       TOK_IF Exp TOK_THEN Exp                                 %prec IF_WO_ELSE_PREC
                        {
                            $$ = (Expression*) new ExpIf($2, $4);
                        }
                |       TOK_IF Exp TOK_THEN Exp TOK_ELSE Exp                    %prec EXP_REDUCE_PREC
                        {
                            $$ = (Expression*) new ExpIf($2, $4, $6);
                        }
                |       TOK_WHILE Exp TOK_DO Exp                                %prec EXP_REDUCE_PREC
                        {
                            $$ = (Expression*) new ExpWhile($2, $4);
                        }
                |       TOK_FOR TOK_ID TOK_ASSIGN Exp TOK_TO Exp TOK_DO Exp     %prec EXP_REDUCE_PREC
                        {
                            $$ = (Expression*) new ExpFor(*$2, $4, $6, $8);
                            delete $2; $2 = NULL;
                        }
                |       TOK_BREAK
                        {
                            $$ = (Expression*) new ExpBreak();
                        }
                |       TOK_LET DecList TOK_IN ExpList TOK_END
                        {
                            $$ = (Expression*) new ExpLet($2, $4);
                        }
                |       IdSqB TOK_OF Exp                                        %prec EXP_REDUCE_PREC
                        {
                            $$ = (Expression*) new ExpArray($1 -> first, $1 -> second,  $3);
                            delete $1; $1 = NULL;
                        }
                ;

SqBExp          :       TOK_LSQB Exp TOK_RSQB 
                        {
                            $$ = $2;
                        }

DecList         :       /* nothing */
                        {
                            $$ = new DecList;
                        }
                |       DecList Dec
                        {
                            $1 -> push_back($2);
                            $$ = $1;
                        }
                ;

Dec             :       TyDec
                |       VarDec
                |       FuncDec
                ;

TyDec           :       TOK_TYPE TOK_ID TOK_EQUALS Ty
                        {
                            $$ = (Dec*) new TyDec(*$2, $4);
                            delete $2; $2 = NULL;
                        }
                ;

Ty              :       TOK_ID
                        {
                            $$ = new Ty(TY_ID, *$1);
                            delete $1; $1 = NULL;
                        }
                |       TOK_LCURLB FieldList TOK_RCURLB
                        {
                            $$ = new Ty(TY_Record, $2);
                        }
                |       TOK_ARRAY TOK_OF TOK_ID
                        {
                            $$ = new Ty(TY_Array, *$3);
                            delete $3; $3 = NULL;
                        }
                ;

VarDec          :       TOK_VAR TOK_ID TOK_ASSIGN Exp                           %prec EXP_REDUCE_PREC
                        {
                            $$ = (Dec*) new VarDec(*$2, $4);
                            delete $2; $2 = NULL;
                        }
                |       TOK_VAR TOK_ID TOK_COLON TOK_ID TOK_ASSIGN Exp          %prec EXP_REDUCE_PREC
                        {
                            $$ = (Dec*) new VarDec(*$2, *$4, $6);
                            delete $2; $2 = NULL;
                            delete $4; $4 = NULL;
                        }
                ;

FuncDec         :       TOK_FUNCTION TOK_ID TOK_LBR FieldList TOK_RBR TOK_EQUALS Exp   %prec EXP_REDUCE_PREC
                        {
                            $$ = (Dec*) new FuncDec(*$2, $4, $7);
                            delete $2; $2 = NULL;
                        }
                |       TOK_FUNCTION TOK_ID TOK_LBR FieldList TOK_RBR TOK_COLON TOK_ID TOK_EQUALS Exp   %prec EXP_REDUCE_PREC
                        {
                            $$ = (Dec*) new FuncDec(*$2, $4, *$7, $9);
                            delete $2; $2 = NULL;
                            delete $7; $7 = NULL;
                        }
                ;

IdSqB           :       TOK_ID SqBExp
                        {
                            $$ = new IdSqB(*$1, $2);
                            delete $1; $1 = NULL;
                        }

LValue          :       TOK_ID                                                  %prec EXP_REDUCE_PREC
                        {
                            $$ = (LVal*) new LValID(*$1);
                            delete $1; $1 = NULL;
                        }
                |       LValue TOK_DOT TOK_ID
                        {
                            $$ = (LVal*) new LValMember($1, *$3);
                            delete $3; $3 = NULL;
                        }
                |       IdSqB
                        {
                            $$ = (LVal*) new LValElement((LVal*) new LValID($1 -> first), $1 -> second);
                        }
                |       LValue SqBExp
                        {
                            $$ = (LVal*) new LValElement($1, $2);
                        }
                ;

ExpList         :       /* nothing */
                        {
                            $$ = new ExpList;
                        }
                |       Exp
                        {
                            $$ = new ExpList;
                            $$ -> push_back($1);
                        }
                |       ExpList TOK_SEMIC Exp
                        {
                            $$ = $1;
                            $$ -> push_back($3);
                        }
                |       ExpList error TOK_SEMIC Exp
                        {
                            cerr << "Statement discarded, continuing." << endl;
                            $$ = $1;
                            $$ -> push_back($4);
                        }
                ;

ArgList         :       /* nothing */
                        {
                            $$ = new ArgList;
                        }
                |       Exp
                        {
                            $$ = new ArgList;
                            $$ -> push_back($1);
                        }
                |       ArgList TOK_COMMA Exp
                        {
                            $$ = $1;
                            $$ -> push_back($3);
                        }
                ;

FieldList       :       /* nothing */
                        {
                            $$ = new FieldList;
                        }
                |       TOK_ID TOK_COLON TOK_ID
                        {
                            $$ = new FieldList;
                            $$ -> push_back(FieldEle(*$1, *$3));
                            delete $1; $1 = NULL;
                            delete $3; $3 = NULL;
                        }
                |       FieldList TOK_COMMA TOK_ID TOK_COLON TOK_ID
                        {
                            $$ = $1;
                            $$ -> push_back(FieldEle(*$3, *$5));
                            delete $3; $3 = NULL;
                            delete $5; $5 = NULL;
                        }
                ;

FieldExpList    :       /* nothing */
                        {
                            $$ = new FieldExpList;
                        }
                |       TOK_ID TOK_EQUALS Exp
                        {
                            $$ = new FieldExpList;
                            $$ -> push_back(FieldExpEle(*$1, $3));
                            delete $1; $1 = NULL;
                        }
                |       FieldExpList TOK_COMMA TOK_ID TOK_EQUALS Exp
                        {
                            $$ = $1;
                            $$ -> push_back(FieldExpEle(*$3, $5));
                            delete $3; $3 = NULL;
                        }
                |       FieldExpList error TOK_COMMA
                ;

BinOp_L1        :       TOK_MULT_SIGN
                        {
                            $$ = BO_Mul;
                        }
                |       TOK_DIV_SIGN
                        {
                            $$ = BO_Div;
                        }
                ;
BinOp_L2        :       TOK_PLUS_SIGN
                        {
                            $$ = BO_Plus;
                        }
                |       TOK_MINUS_SIGN
                        {
                            $$ = BO_Minus;
                        }
                ;
BinOp_L3        :       TOK_NEQ
                        {
                            $$ = BO_Neq;
                        }
                |       TOK_LT
                        {
                            $$ = BO_LT;
                        }
                |       TOK_LTE
                        {
                            $$ = BO_LTE;
                        }
                |       TOK_GT
                        {
                            $$ = BO_GT;
                        }
                |       TOK_GTE
                        {
                            $$ = BO_GTE;
                        }
                |       TOK_EQUALS
                        {
                            $$ = BO_Equal;
                        }
                ;
BinOp_L4        :       TOK_AND
                        {
                            $$ = BO_And;
                        }
                ;
BinOp_L5        :       TOK_OR
                        {
                            $$ = BO_Or;
                        }
                ;
UnOp            :       TOK_MINUS_SIGN
                        {
                            $$ = UO_Neg;
                        }
                ;

%%

static const char *const yyprintname[] =
{
  "end of file", "error", "undefined", "\"array\"", "\"break\"", "\"do\"",
  "\"else\"", "\"end\"", "\"for\"", "\"function\"", "\"if\"", "\"in\"",
  "\"let\"", "\"nil\"", "\"of\"", "\"then\"", "\"to\"", "\"type\"",
  "\"var\"", "\"while\"", "\"+\"", "\"-\"",
  "\"*\"", "\"/\"", "\"&\"", "\"|\"", "\"=\"",
  "\"<>\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\":=\"",
  "\";\"", "\",\"", "\":\"", "\".\"", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "integer",
  "identifier", "string", "EXP_REDUCE_PREC", "IF_WO_ELSE_PREC",
  "UNIOP_PREC", "$accept", "Program", "Expression", "Square Brace Expression", "Declaration List", "Declaration",
  "Type Declaration", "Type", "Variable Declaration", "Function Declartion", "Identifier Square Brace Expression", "Left Hand Value", "Expression List",
  "Argument List", "Field List", "Field Expression List", "Binary Operation Level 1", "Binary Operation Level 2",
  "Binary Operation Level 3", "Binary Operation Level 4", "Binary Operation Level 5", "Uni-Operation", YY_NULL
};

static string strErrReplace(const char* str)
{
    string strBig = str;
    for (const char* const* src = yytname, * const* dst = yyprintname; *src != YY_NULL; ++ src, ++ dst) {
        string::size_type pos=0;
        string strsrc = *src;
        string strdst = *dst;
        string::size_type srclen=strsrc.size();
        string::size_type dstlen=strdst.size();
        while( (pos=strBig.find(strsrc, pos)) != string::npos)
        {
            if (((pos + srclen) < strBig.size()) && (isalpha(strBig[pos + srclen]) || (strBig[pos + srclen] == '_'))) {
                ++ pos;
                continue;
            }
            strBig.replace(pos, srclen, strdst);
            pos += dstlen;
        }
    }
    return strBig;
}


static string strErrReplace(const char* str);

extern char* yytext;
extern int yylineno;
extern int yycolumn;

void yyerror(const char *str)
{
    cerr << "Parser: " << strErrReplace(str) << "." << endl;
    string errHead = toStr(string("\"") + yytext + "\"" + " at line ");
    if (yylloc.first_line) {
        errHead += toStr(yylloc.first_line);
        errHead += ": ";
        string lineout = linebuf;
        string_replace(linebuf, "\t", " ");
        cerr << errHead << linebuf << endl;
        
        string errFill(errHead.length(), ' ');
        string errLeading(yylloc.first_column - 1, '.');
        string errSymbol(yylloc.last_column - yylloc.first_column + 1, '^');
        string errTrailing(linebuf.length() - yylloc.last_column, '.');
        cerr << errFill << errLeading << errSymbol << errTrailing << endl;
        
        // cerr << yylloc.first_line << ":" << yylloc.first_column << " - ";
        // cerr << yylloc.last_line << ":" << yylloc.last_column << endl;
    }
}

int yywrap()
{
    return 1;
}

