#ifndef IFUNCTION_H
#define IFUNCTION_H

// Um objeto que implemente esta interface pode ser utilizado na fila de funções realizando alguma função de inteiro para inteiro.
class IFunction
{
    public:
        // Roda a função com a entrada x e retorna o valor professado por esta função
        virtual int runFunc(int x) =0;
};

#endif // IFUNCTION_H
