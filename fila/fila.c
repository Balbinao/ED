#include "fila.h"

void inicia_fila(t_fila * f){
    f->primeiro = f->ultimo = NULL;
    f->tamanho = 0;
}
int esta_vazia(t_fila * f){
    return f->tamanho == 0;
}
void enfileira(int x, t_fila * f){
    t_no * novoNo = constroi_no(x);

    if(esta_vazia(f)){
        f->primeiro = novoNo;

    }else{
        f->ultimo->proximo = novoNo;
    }
    f->ultimo = novoNo;
    f->tamanho++;
}
int desenfileira(t_fila * f){
    int temp = f->primeiro->info;
    t_no * lixo = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    f->tamanho--;

    if(esta_vazia(f)){
        f->ultimo = NULL;
    }

    free(lixo);
    return temp;

}
void mostra_fila(t_fila * f){
    if(esta_vazia(f)){
        printf("\nFila Vazia\n");
    }else{
        t_no * aux = f->primeiro;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

//busca elemento presente na fila
int buscar_fila(t_fila *fila, int valor) {
    t_no *aux = fila->primeiro;
    while (aux != NULL) {
        if (aux->info == valor) {
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

//funcao que reverte a fila
void reverter_fila(t_fila *fila) {
    t_no *anterior = NULL, *atual = fila->primeiro, *proximo = NULL;
    fila->ultimo = fila->primeiro;
    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    fila->primeiro = anterior;
}

//funcao que remove os elementos da fila
void limpar_fila(t_fila *fila) {
    t_no *aux = fila->primeiro;
    while (aux != NULL) {
        t_no *temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}


//funcao que compara filas para saber se sao iguais, se seguem a mesma ordem e tem os mesmos valores
int filas_iguais(t_fila *fila1, t_fila *fila2) {
    t_no *aux1 = fila1->primeiro;
    t_no *aux2 = fila2->primeiro;
    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->info != aux2->info) {
            return 0;
        }
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }
    return aux1 == NULL && aux2 == NULL;
}
