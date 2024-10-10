// Fazer uma func¸ao que copia uma lista L1 em uma outra lista L2.

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int dado; 
    struct no* prox; 
} t_no;


void adicionar(t_no** cab, int novo_dado) {
    t_no* novoNo = (t_no*)malloc(sizeof(t_no)); 
    t_no* ultimo = *cab; 
    novoNo->dado = novo_dado; 
    novoNo->prox = NULL; 
    if (*cab == NULL) { 
        *cab = novoNo; 
        return; // Sai da função
    }
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    ultimo->prox = novoNo; 
}   

void copiarLista(t_no* L1, t_no** L2) {
    t_no* atual = L1; 
    while (atual != NULL) { 
        adicionar(L2, atual->dado); //adiciona o valor do nó atual de L1 na lista L2
        atual = atual->prox; 
    }
}


void imprimirLista(t_no* no) {
    while (no != NULL) {
        printf("%d ", no->dado); 
        no = no->prox; 
    }
    printf("\n"); 
}

int main() {
    t_no* L1 = 0; 
    t_no* L2 = 0; 

    // Exemplo de adição de elementos na lista L1
    adicionar(&L1, 3);
    adicionar(&L1, 7);
    adicionar(&L1, 5);

    
    printf("Lista L1: ");
    imprimirLista(L1);

    
    copiarLista(L1, &L2);

    
    printf("Lista L2: ");
    imprimirLista(L2);

    return 0; 
}
