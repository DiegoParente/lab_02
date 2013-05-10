#include "Operator.h"

void Operator::setFunction(IFunction *f){
	this->f = f;
}
IFunction *Operator::getFunction(){
	return this->f;
}

Operator::Operator(IFunction *f){
	this->f = f;
}
