#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * v;
    int primeiro;
    int ultimo;
    int tamanho;
    int capacidade;
}t_fila;

t_fila * constroi_fila (int); //capacidade é o parametro
int esta_vazia(t_fila *);
int esta_cheia(t_fila *);

int enfileira(int, t_fila *); //o retorno é sucesso (1) ou fracasso(0)
int desenfileira(int *, t_fila *);
//o retorno também é sucesso / fracasso; e o elemento retirado é passado por parametro referencia
void mostra_fila(t_fila *);
void mostra_vetor(t_fila *);
int primeiro_elemento(t_fila *);
