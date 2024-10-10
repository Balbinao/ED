// 24. Escreva uma func¸ao que verifica se duas listas dadas s ˜ ao iguais (mesmo conte ˜ udo

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
        return;
    }
    while (ultimo->prox != NULL) {

        ultimo = ultimo->prox;
    }
    ultimo->prox = novoNo; 
}


int saoIguais(t_no* L1, t_no* L2) {
    //ponteiros para percorrer as duas listas
    t_no* p1 = L1; 
    t_no* p2 = L2; 
    
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->dado != p2->dado) { //compara os dados dos nós atuais
            return 0; 
        }
        
        p1 = p1->prox; 
        p2 = p2->prox; 
    }
    
    //se ambas as listas terminaram ao mesmo tempo, elas são iguais
    return (p1 == NULL && p2 == NULL);
}


void imprimirLista(t_no* no) {
    while (no != NULL) {
        printf("%d ", no->dado); //imprime o valor do nó atual
        no = no->prox; //avança para o próximo nó na lista
    }
    printf("\n"); 
}


int main() {
    t_no* L1 = 0;
    t_no* L2 = 0;

    //adição de elementos na lista L1
    adicionar(&L1, 1);
    adicionar(&L1, 2);
    adicionar(&L1, 3);

    //eadição de elementos na lista L2
    adicionar(&L2, 3);
    adicionar(&L2, 2);
    adicionar(&L2, 3);

 
    printf("Lista L1: ");
    imprimirLista(L1);

    
    printf("Lista L2: ");
    imprimirLista(L2);

    //verifica se as listas L1 e L2 são iguais
    if (saoIguais(L1, L2)) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas nao sao iguais.\n");
    }

    return 0; 
}
