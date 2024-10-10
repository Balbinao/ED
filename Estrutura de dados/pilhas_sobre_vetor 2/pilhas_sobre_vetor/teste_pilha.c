#include "pilha.h"
#include <time.h> //pega o rend e srend, variaveis para gerar numeros aleatorios

int main(){
    srand(time (0));
    t_pilha p;
    constroi_pilha(&p, 10);

    do{
        if(rand() % 2){ // perguntando se é verdadeiro: == 1;
            if(!esta_cheia(&p)){
                empilha(&p, rand() % 100);
            }
        }
        else{
            if(!esta_vazia(&p)){
                printf("\n%d foi desempilhado\n", desempilha(&p));
            }
        }
        mostra_pilha(&p);
        printf("=================================\n");
    }
    while(!esta_vazia(&p));
    return 0;
}
