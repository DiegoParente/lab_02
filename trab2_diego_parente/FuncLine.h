#ifndef FUNCLINE_H
#define FUNCLINE_H

#include "IFuncLine.h"
#include <vector>
#include <iostream>
#include "Operator.h"
#include "Function.h"
#include "FuncParam.h"

using namespace std;

class FuncLine : public IFuncLine{

public:
 	IOperator *addFunction(IFunction *f);
    void addPrint();
    int runFuncLine(int x);
	vector<IOperator*> line;
};

int print_aux(int x);

#endif