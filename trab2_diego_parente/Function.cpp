#include "Function.h"

int Function::runFunc(int x){
	return this->f(x);
}

Function::Function(int (*f)(int)){
	this->f =  f;
}

