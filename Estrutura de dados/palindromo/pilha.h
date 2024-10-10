#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * dados;
    int topo;
    int capacidade;
}t_pilha;

void constroi_pilha(t_pilha *, int);

int esta_vazia (const t_pilha *); //const, serve para não alterar as coisas, não modifica a referência

int esta_cheia(const t_pilha * );

int tamanho_pilha(const t_pilha * );

void empilha(t_pilha *, char);

char desempilha(t_pilha *);

void mostra_pilha(t_pilha *);

