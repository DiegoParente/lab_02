#include "FuncLine.h"

IOperator *FuncLine::addFunction(IFunction *f){
	IOperator *op = new Operator(f);
	this->line.push_back(op);
	return op;
}

void FuncLine::addPrint(){
	IFunction *f =  new Function(print_aux);
	this->addFunction(f);
}

int FuncLine::runFuncLine(int x){
	for(vector<IOperator*>::iterator it = this->line.begin(); it != line.end(); it++){
		x =  (*it)->getFunction()->runFunc(x);
	}
	return x;
}

int print_aux(int x){
	cout << x << endl;
	return x;
}