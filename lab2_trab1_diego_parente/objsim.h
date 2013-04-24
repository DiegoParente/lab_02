#ifndef OBJSIM_H_INCLUDED
#define OBJSIM_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

void *createFuncLine();


// Adiciona a função 'f' no final da lista de funções 'funcLine'. Retorna um identificador do operador que contém esta função
// A primeira entrada da função f é o valor passado pela linha de funções. A segunda entrada de f é o valor param se este for diferente de 0 e 1 caso contrário.
void *addFuncParam(void *funcLine, int (*f)(int, int), int param);

// Adiciona a função 'f' no final da lista de funções 'funcLine'. Retorna um identificador do operador que contém esta função
// A entrada da função f é o valor passado pela linha de funções.
void *addFunc(void *funcLine, int (*f)(int));

// Adiciona uma função de impressão no final da lista de funções 'funcLine'.
void addPrint(void *funcLine);

// Modifica o parâmetro de op se este possuir um parâmetro. O novo parâmetro deve ser igual a 1 se for fornecido o valor 0 na entrada.
void setParam(void *op, int param);

// Modifica a função de um operador sem parâmetro.
void setFunc(void *op, int (*f)(int));

// Roda a lista de funções em ordem
void runFuncLine(void *funcLine, int init);

#endif // OBJSIM_H_INCLUDED
