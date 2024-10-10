// 13. Desenvolva uma func¸ao para testar se duas pilhas P1 e P2 s ˜ ao iguais. 

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

//função para desempilhar um elemento
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

//função para verificar se duas pilhas são iguais
int pilhasIguais(t_no* P1, t_no* P2) {
    t_no *temp1 = P1, *temp2 = P2;

    //percorre as duas pilhas comparando os elementos
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->dado != temp2->dado) {
            return 0; // Retorna falso se encontrar elementos diferentes
        }
        temp1 = temp1->prox;
        temp2 = temp2->prox;
    }

    //verifica se ambas as pilhas chegaram ao fim, têm o mesmo tamanho
    return (temp1 == NULL && temp2 == NULL);
}

//função para imprimir a pilha
void imprimirPilha(t_no* topo) {
    t_no* temp = topo;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}


int main() {
    t_no* P1 = NULL;
    t_no* P2 = NULL;

    //exemplo de adição de elementos nas pilhas
    empilhar(&P1, 1);
    empilhar(&P1, 2);
    empilhar(&P1, 3);

    empilhar(&P2, 1);
    empilhar(&P2, 2);
    empilhar(&P2, 3);

    
    printf("Pilha P1: ");
    imprimirPilha(P1);
    printf("Pilha P2: ");
    imprimirPilha(P2);

    
    if (pilhasIguais(P1, P2)) {
        printf("As pilhas P1 e P2 sao iguais.\n");
    } else {
        printf("As pilhas P1 e P2 nao sao iguais.\n");
    }

    
    while (P1 != NULL) {
        desempilhar(&P1);
    }
    while (P2 != NULL) {
        desempilhar(&P2);
    }

    return 0;
}
