#include <stdio.h>
#include <stdlib.h>

#include "objsim.h"

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

int main()
{
    void *funcLine1, *funcLine2;
    void *op1, *op2, *op3, *op4, *op5, *op6, *op7, *op8;

    funcLine1 = createFuncLine();
    funcLine2 = createFuncLine();

    op1 = addFuncParam(funcLine1, &f1, 5);
    addPrint(funcLine1);
    op2 = addFuncParam(funcLine1, &f2, 0);
    addPrint(funcLine1);
    op3 = addFunc(funcLine1, &f3);
    op4 = addFunc(funcLine1, &f4);
    addPrint(funcLine1);

    op5 = addFuncParam(funcLine2, &f2, 5);
    addPrint(funcLine2);
    op6 = addFuncParam(funcLine2, &f1, 0);
    addPrint(funcLine2);
    op7 = addFunc(funcLine2, &f4);
    op8 = addFunc(funcLine2, &f3);
    addPrint(funcLine2);

    runFuncLine(funcLine1, 2);
    runFuncLine(funcLine2, 3);

    setParam(op1, 0);
    setParam(op2, 4);
    setFunc(op3, &f4);
    setFunc(op4, &f3);

    setParam(op5, 0);
    setParam(op6, 20);
    setFunc(op7, &f3);
    setFunc(op8, &f4);

    runFuncLine(funcLine1, 5);
    runFuncLine(funcLine2, 4);

    return 0;
}
