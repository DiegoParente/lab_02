#ifndef OPERATOR_H
#define OPERATOR_H

#include "IFunction.h"
#include "IOperator.h"

class Operator : public IOperator{

public:
    void setFunction(IFunction *f);
    IFunction *getFunction();
    Operator(IFunction *f);
    Operator *next;
private:
	IFunction *f;
};

#endif