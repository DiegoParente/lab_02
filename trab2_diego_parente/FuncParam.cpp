#include "FuncParam.h"

int FuncParam::getParam(){
	return this->param;
}
void FuncParam::setParam(int p){
	this->param = !p? 1:p;
}
FuncParam::FuncParam(int (*f)(int, int) ,int param){
	this->f =  f;
	this->setParam(param);
}
int FuncParam::runFunc(int x){
	return this->f(x, this->param);
}

