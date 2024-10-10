// Escreva uma func¸ao que crie uma lista encadeada a partir de um vetor


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

//função para criar uma lista encadeada a partir de um vetor
t_no* criarListaAPartirDeVetor(int vetor[], int tamanho) {
    t_no* cab = NULL; //inicializa a cabeça da lista como NULL
    for (int i = 0; i < tamanho; i++) { 
        adicionar(&cab, vetor[i]); 
    }
    return cab; //retorna a cabeça da lista criada
}

//função para imprimir a lista
void imprimirLista(t_no* no) {
    while (no != NULL) { 
        printf("%d ", no->dado); 
        no = no->prox; //Avança para o próximo nó na lista
    }
    printf("\n"); 

}
int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); //calcula o tamanho do vetor

    //cria a lista encadeada a partir do vetor
    t_no* lista = criarListaAPartirDeVetor(vetor, tamanho);

 
    printf("Lista encadeada criada a partir do vetor: ");
    imprimirLista(lista);

    return 0;
}