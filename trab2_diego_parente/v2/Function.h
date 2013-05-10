#ifndef FUNCTION_H
#define FUNCTION_H

#include "IFunction.h"

class Function : public IFunction{

public:
    int runFunc(int x);
    Function(int (*f)(int));
private:
	int (*f)(int);
};

#endif