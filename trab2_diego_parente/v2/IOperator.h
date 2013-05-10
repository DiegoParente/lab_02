#ifndef IOPERATOR_H
#define IOPERATOR_H

#include "IFunction.h"

// Um operador dentro da fila de funções
class IOperator
{
    public:
        // Coloca a função deste operador para ser a função 'f'
        virtual void setFunction(IFunction *f) =0;

        // Retorna a função atual utilizada por este operador
        virtual IFunction *getFunction() =0;
};

#endif // IOPERATOR_H
