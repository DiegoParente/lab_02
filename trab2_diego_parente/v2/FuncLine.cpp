#include "FuncLine.h"
//a fila, agora é do tipo Operator*, com nome line
//cada operator tem um ponteiro para next;


IOperator *FuncLine::addFunction(IFunction *f){
	Operator *op = new Operator(f);
	op->next = NULL;
	if(line == NULL) line = op;
	else{
		Operator *aux =  line;
		while(aux->next != NULL) aux = aux->next;
		aux->next = op;
	}
	return (IOperator*)op;
}

void FuncLine::addPrint(){
	IFunction *f =  new Function(print_aux);
	this->addFunction(f);
}

int FuncLine::runFuncLine(int x){
	
	for(Operator *aux = line; aux != NULL; aux = aux->next){
		x =  aux->getFunction()->runFunc(x);
	}
	return x;
}

int print_aux(int x){
	cout << x << endl;
	return x;
}