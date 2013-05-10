#ifndef FUNCLINE_H
#define FUNCLINE_H

#include "IFuncLine.h"
#include <vector>
#include <iostream>
#include "Operator.h"
#include "Function.h"
#include "FuncParam.h"

using namespace std;


int print_aux(int x);

class FuncLine : public IFuncLine{

public:
 	IOperator *addFunction(IFunction *f);
    void addPrint();
    int runFuncLine(int x);
	Operator *line;
};



#endif