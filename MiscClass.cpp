#ifndef MISCCLASS_H_
#define MISCCLASS_H_

ExpList::ExpList():BasicNode(N_ExpList) {
    //do nothing
}
ExpList::Expression*& operator[](size_t idx) {
    return expVec[idx];
}
ExpList::vector<Expression*>::size_type size() {
    return expVec.size();
}
ExpList::void push_back(Expression* _exp) {
    expVec.push_back(_exp);
}
ExpList::~ExpList(){
    for(size_t i = 0; i < expVec.size(); ++ i) {
        if (expVec[i]) delete expVec[i];
        expVec[i] = NULL;
    }
}

ArgList::ArgList():BasicNode(N_ArgList) {
    //do nothing
}
ArgList::Expression*& operator[](size_t idx) {
    return argVec[idx];
}
ArgList::vector<Expression*>::size_type size() {
    return argVec.size();
}
ArgList::void push_back(Expression* _arg) {
    argVec.push_back(_arg);
}
ArgList::~ArgList(){
    for(size_t i = 0; i < argVec.size(); ++ i) {
        if (argVec[i]) delete argVec[i];
        argVec[i] = NULL;
    }
}

DecList::DecList():BasicNode(N_DecList) {
    //do nothing
}
DecList::Dec*& operator[](size_t idx) {
    return decVec[idx];
}
DecList::vector<Dec*>::size_type size() {
    return decVec.size();
}
DecList::void push_back(Dec* _dec) {
    decVec.push_back(_dec);
}
DecList::~DecList() {
    for(size_t i = 0; i < decVec.size(); ++ i) {
        if (decVec[i]) delete decVec[i];
        decVec[i] = NULL;
    }
}

FieldExpList::FieldExpList():BasicNode(N_FieldExpList) {
    //do nothing
}
FieldExpList::FieldExpEle& operator[](size_t idx) {
    return fieldExpVec[idx];
}
FieldExpList::vector<FieldExpEle>::size_type size() {
    return fieldExpVec.size();
}
FieldExpList::void push_back(FieldExpEle _fieldExpEle) {
    fieldExpVec.push_back(_fieldExpEle);
}
FieldExpList::~FieldExpList(){
    for(size_t i = 0; i < fieldExpVec.size(); ++ i) {
        if (fieldExpVec[i].second) delete fieldExpVec[i].second;
        fieldExpVec[i].second = NULL;
    }
}

FieldList::FieldList():BasicNode(N_FieldList) {
    //do nothing
}
FieldList::FieldEle& operator[](size_t idx) {
    return fieldVec[idx];
}
FieldList::vector<FieldEle>::size_type size() {
    return fieldVec.size();
}
FieldList::void push_back(FieldEle _fieldEle) {
    fieldVec.push_back(_fieldEle);
}

#endif // MISCCLASS_H_
