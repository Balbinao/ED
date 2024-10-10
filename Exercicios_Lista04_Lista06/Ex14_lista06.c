// 14. Desenvolva uma operac¸ao para transferir elementos de uma pilha P1 para uma pilha P2 ˜
// (copia).

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int dado;
    struct no* prox;
} t_no;


void empilhar(t_no** topo, int valor) {
    t_no* novoNo = (t_no*)malloc(sizeof(t_no));
    novoNo->dado = valor;
    novoNo->prox = *topo;
    *topo = novoNo;
}

// Função para desempilhar um elemento
int desempilhar(t_no** topo) {
    if (*topo == NULL) {
        return 0;
    }
    t_no* temp = *topo;
    int valor = temp->dado;
    *topo = (*topo)->prox;
    free(temp);
    return valor;
}

//função para copiar elementos de P1 para P2
void copiarPilha(t_no** P1, t_no** P2) {
    t_no* temp = NULL;
    
    //transfere elementos de P1 para uma pilha temporária
    while (*P1 != NULL) {
        empilhar(&temp, desempilhar(P1));
    }
    
    //transfere elementos da pilha temporária para P2
    while (temp != NULL) {
        empilhar(P2, desempilhar(&temp));
    }
}


void imprimirPilha(t_no* topo) {
    t_no* temp = topo;
    
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    t_no* P1 = 0;
    t_no* P2 = 0;

   
    empilhar(&P1, 1);
    empilhar(&P1, 2);
    empilhar(&P1, 3);

    //imprime a pilha P1 antes da cópia
    printf("Pilha P1 antes da copia: ");
    imprimirPilha(P1);

    //cpia os elementos de P1 para P2
    copiarPilha(&P1, &P2);

 
    printf("Pilha P1 apos a copia: ");
    imprimirPilha(P1);

    printf("Pilha P2 apos a copia: ");
    imprimirPilha(P2);

 
    while (P1 != NULL) {
        desempilhar(&P1);
    }
    while (P2 != NULL) {
        desempilhar(&P2);
    }

    return 0;
}
