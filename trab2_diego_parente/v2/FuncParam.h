#ifndef FUNCPARAM_H
#define FUNCPARAM_H

#include "IFuncParam.h" 

class FuncParam : public IFuncParam{

public:
	int (*f)(int, int);
	int getParam();
	void setParam(int p);
	FuncParam(int (*f)(int, int), int param);
	int runFunc(int x);
};

#endif