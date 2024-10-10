// Considere uma lista contendo números inteiros positivos. Faça uma função que retorne a média da lista.

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int dado;
    struct no* prox;
} t_no;


void adicionar(t_no** cab, int novo_dado) {
    t_no* novoNo = (t_no*)malloc(sizeof(t_no)); //aloca memória para um novo nó
    t_no* ultimo = *cab; //ponteiro para percorrer a lista até o último elemento
    novoNo->dado = novo_dado; //atribui o novo dado ao campo 'dado' do novo nó
    novoNo->prox = NULL; //define o próximo nó como NULL, pois será o último da lista
    if (*cab == NULL) { //verifica se a lista está vazia
        *cab = novoNo; //se estiver vazia, o novo nó se torna o primeiro da lista
        return;
    }
    while (ultimo->prox != NULL) {// Percorre a lista até encontrar o último nó
        ultimo = ultimo->prox;
    }
    ultimo->prox = novoNo; // Adiciona o novo nó ao final da lista
}


float calcularMedia(t_no* cab) {
    if (cab == NULL)
        return 0.0; // Se a lista estiver vazia, retorna média zero
    
    int soma = 0; 
    int contador = 0; 
    t_no* atual = cab; // Ponteiro para percorrer a lista
      
    while (atual != NULL) {
        soma += atual->dado; //soma o valor do nó atual à variável 'soma'
        contador++; //incrementa o contador de elementos
        atual = atual->prox; //avança para o próximo nó na lista
    }

    //retorna a média como um número de ponto flutuante
    return (float)soma / contador;
}


void imprimirLista(t_no* no) {
    while (no != NULL) { //enquanto houver nós na lista
        printf("%d ", no->dado); 
        no = no->prox; //avança para o próximo nó na lista
    }
    printf("\n"); 
}


int main() {
    t_no* cab = NULL; 

   
    adicionar(&cab, 3);
    adicionar(&cab, 7);
    adicionar(&cab, 5);


    printf("Lista: ");
    imprimirLista(cab);

   
    printf("Media da lista: %.2f\n", calcularMedia(cab));

    return 0;
}
