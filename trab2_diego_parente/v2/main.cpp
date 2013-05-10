#include "FuncLine.h"

int f1(int x, int param)
{
    x = (50*x)/(3*param);
    return x;
}

int f2(int x, int param)
{
    x = (10*x)/param;
    return x;
}

int f3(int x)
{
    x = x+1;
    return x;
}

int f4(int x)
{
    x = x/2;
    return x;
}

int main(){
	IFuncLine *l1, *l2;
	IFuncParam *p1, *p2, *p3, *p4;
	IFunction *s1, *s2, *s3, *s4;
	IOperator *op1, *op2, *op3, *op4;
	IOperator *op5, *op6, *op7, *op8;

	p1 =  new FuncParam(f1, 5);
	p2 =  new FuncParam(f2, 0);
	p3 =  new FuncParam(f2, 5);
	p4 =  new FuncParam(f1, 0);

	s1 =  new Function(f3);
	s2 = new Function(f4);
	s3 = new Function(f4);
	s4 = new Function(f3);

	l1 =  new FuncLine();
	l2 =  new FuncLine();

	op1 = l1->addFunction(p1);
	l1->addPrint();
	op2 = l1->addFunction(p2);
	l1->addPrint();
	op3 = l1->addFunction(s1);
	op4 = l1->addFunction(s2);
	l1->addPrint();

	op5 = l2->addFunction(p3);
	l2->addPrint();
	op6 = l2->addFunction(p4);
	l2->addPrint();
	op7 = l2->addFunction(s3);
	op8 = l2->addFunction(s4);
	l2->addPrint();

	l1->runFuncLine(2);
	l2->runFuncLine(3);

	((FuncParam*)(op1->getFunction()))->setParam(0);
	((FuncParam*)(op2->getFunction()))->setParam(4);
	op3->setFunction(new Function(f4));
	op4->setFunction(new Function(f3));

	((FuncParam*)(op5->getFunction()))->setParam(0);
	((FuncParam*)(op6->getFunction()))->setParam(20);
	op7->setFunction(new Function(f3));
	op8->setFunction(new Function(f4));

	l1->runFuncLine(5);
	l2->runFuncLine(4);

	return 0;

}