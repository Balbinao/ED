#include <time.h>
#include "fila.h"

void concatena_fila(t_fila * f1, t_fila *f2){
    f1->ultimo->proximo = f2->primeiro;
    f1->ultimo = f2->ultimo;
    f1->tamanho = f1->tamanho + f2->tamanho;
    inicia_fila(f2); 
}

int elementos_impar(t_fila *f){
    t_no * aux = f->primeiro;
    if(esta_vazia(f)){
        return 0;
    }
    int cont = 0;
    while(aux != NULL){
        if(aux->info%2){
            cont++;
        }
        aux = aux -> proximo;
    }
    return cont;
}
int main(){
    t_fila fila;    
    inicia_fila(&fila);
    srand(time(0));
    // do{
    //     if(rand() %2){
    //         enfileira(rand() % 10, &fila);
    //     }else{
    //         if(!esta_vazia(&fila)){
    //             printf("\n%d foi atendido\n", desenfileira(&fila));
    //         }
    //     }
    //     mostra_fila(&fila);     
    // }while(!esta_vazia(&fila));
    t_fila f1, f2;
    inicia_fila(&f1);
    inicia_fila(&f2);
    for(int i = 1; i < 10; i += 2){
        enfileira(i, &f1);
    }
    mostra_fila(&f1);
    for(int i = 2; i <= 10; i += 2){
        enfileira(i, &f2);
    }
    mostra_fila(&f2);

    concatena_fila(&f1, &f2);
    mostra_fila(&f1);
    mostra_fila(&f2);
    printf("impares: %d\n", elementos_impar(&f1));
}