#ifndef IFUNCPARAM_H
#define IFUNCPARAM_H

#include "IFunction.h"

// Uma função desta interface utiliza o parâmetro param quando fizer a chamada para funFunction. O parâmetro não pode ser 0.
class IFuncParam : public IFunction
{
    protected:
        int param;

    public:
        // Retorna o parâmetro desta função
        virtual int getParam() =0;

        // Atualiza o novo parâmetro desta função. Se p == 0, a variável 'param' deve ser 1.
        virtual void setParam(int p) =0;
};

#endif // IFUNCPARAM_H
