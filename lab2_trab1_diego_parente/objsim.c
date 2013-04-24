#include "objsim.h"

//Normalmente, eu definiria essas estruturas em objsim.h, porém,
//como foi instruído que houvesse o mínimo de alterações possíveis em objsim.h, elas estão definidas aqui.
//Foi adicionado um parâmetro para a função runFuncLine, o parâmetro que representa o valor inicial.


typedef struct _ll{//lista duplamente encadeada
	struct _ll *next, *previous;//ponteiros para o próximo elemento e elemento anterior da lista
	int x;//primeiro parâmetro da função
	void *function;//é usado para apontar para uma função
	int *param;//para funções que possuem apenas um parâmetro, param deve ser NULL, caso contrário param é o valor do segundo parâmetro
}ll;

void *createFuncLine(){
	ll *aux = (ll*)malloc(sizeof(ll));//aloca a cabeça da lista
	return aux;//retorna a cabeça da lista
}

void *addFuncParam(void *funcLine, int (*f)(int, int), int param){//adiciona função de 2 parâmetros na lista
	ll *aux = (ll*) funcLine;//faz o casting de funcLine
	while(aux->next != NULL) aux = aux->next;//procura o último elemento da lista
	aux->next = (ll*)malloc(sizeof(ll));//aloca um novo elemento na lista
	ll *a2 = aux->next;//variável auxiliar recebe o novo nó alocado
	a2->previous = aux;//atualiza o ponteiro anterior, do novo nó
	a2->function = f;
	a2->param = (int*) malloc(sizeof(int));//aloca param, de a2
	*(a2->param) = (!param)? 1:param;//caso o parâmetro passado em param seja 0, atribui 1, caso contrário, atribui param
	return a2;//retorna o novo nó
}

void *addFunc(void *funcLine, int (*f)(int)){//adiciona função de único parâmetro na lista
	ll *aux = (ll*) funcLine;//faz o casting de funcLine
	while(aux->next != NULL) aux = aux->next;//procura o último elemento da lista
	aux->next = (ll*)malloc(sizeof(ll));//aloca um novo elemento na lista
	ll *a2 = aux->next;//atualiza o ponteiro anterior, do novo nó
	a2->previous = aux;//atualiza o ponteiro anterior, do novo nó
	a2->function = f;
	a2->param = NULL; //indicando que a função possui apenas um parâmetro(será que é necessário?)
	return a2;//retorna o novo nó
}

int prt(int value){//função auxiliar, que encapsula printf para poder passá-la como parâmetro de addFunc
	printf("%d\n", value);
	return value; 
}

void addPrint(void *funcLine){//inclui impressão na lista
	addFunc(funcLine, prt);
}

void setParam(void *op, int param){//altera o estado de um nó que possui um ponteiro para uma função de 2 parâmetros
	ll *aux = (ll*) op;
	if(aux->param == NULL) return;
	*(aux->param) = (param == 0)? 1:param;//caso o parâmetro passado em param seja 0, atribui 1, caso contrário, atribui param
}

void setFunc(void *op, int (*f)(int)){//altera o estado de um nó que possui um ponteiro para uma função de único parâmetro
	ll *aux = (ll*) op;
	if(aux->param != NULL) return;
	aux->function = f;
}

void runFuncLine(void *funcLine, int init){//executa a linha de função em ordem de inserção. Iésima a ser inserida -> Iésima a ser executada
	ll *aux = (ll*) funcLine;
	aux->x = init;
	while(aux->next != NULL){
		aux = aux->next;
		if(aux->param == NULL){
			int (*f)(int) = (int (*)(int))(aux->function);
			aux->x = f(aux->previous->x);
		}
		else{
			int (*f)(int, int) = (int(*)(int, int))(aux->function);
			aux->x = f(aux->previous->x, *(aux->param));
		}
	}
}




