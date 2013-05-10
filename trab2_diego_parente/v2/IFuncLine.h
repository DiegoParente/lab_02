#ifndef IFUNCLINE_H
#define IFUNCLINE_H

#include "IFunction.h"
#include "IOperator.h"

class IFuncLine
{
    public:
        // Adiciona a função 'f' na fila de funções. Retorna um operador que contém esta função
        virtual IOperator *addFunction(IFunction *f) =0;

        // Adiciona uma função de impressão na fila de funções
        virtual void addPrint() =0;

        // Roda as funções desta funcline na ordem em que foram inseridas e retorna o último valor calculado
        virtual int runFuncLine(int x) =0;
    protected:
    private:
};

#endif // IFUNCLINE_H
