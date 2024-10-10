#include <time.h>
#include "abb.h"

int main () {
    t_abb a;
    inicializa_abb(&a);
    srand(time(0));
    for(int i =1; i<=12; i++){
        int n = rand() % 100;
        printf("%d ", n);
        insere(n, &a);
    }
    printf("\n");
    exibe_em_ordem(&a);
    printf("\n");
    printf("\n");
    exibe_em_pre_ordem(&a);
    printf("\n");
    printf("\n");
    exibe_ordem_desc(&a);
    printf("\n");
    printf("\n");
    printf("altura = %d\n", altura_arvore(&a));
    printf("O maior eh %d\n", maior_num(&a));
    return 0;
}