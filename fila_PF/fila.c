#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}t_no;


typedef struct{
    t_no *primeiro;
    t_no *ultimo;
    int tamanho;
}t_fila;

void criar_fila(t_fila* fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

void inserir_fila(t_fila *fila, int num){
    t_no *aux, *novo = (t_no*) malloc(sizeof(t_no));
    if (novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(fila->primeiro == NULL){
            fila->primeiro = novo;
            fila->ultimo = novo;       
        }else{
            fila->ultimo->proximo = novo;
            fila->ultimo = novo; 
        }
        fila->tamanho++;
    }
    
    else{
        printf("Erro ao alocar memoria.\n");
    }
}

t_no * remover_fila(t_fila*fila){
    t_no *remover = NULL;

    if(fila->primeiro){
        remover = fila->primeiro;
        fila->primeiro = remover->proximo;
        fila->tamanho--;
    }else{
        printf("Fila vazia\n");
    }
    return remover;
}

void imprimir(t_fila *fila){
    t_no *aux = fila->primeiro;
    printf("\t-----------FILA-----------\n\t");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
        printf("\n\t-----------FIM FILA-----------\n");

}

int main (){
    t_no *r;
    t_fila fila;
    int op;
    int valor;

    criar_fila(&fila);

    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_fila(&fila, valor);
                break;
            case 2:
                r = remover_fila(&fila);
                if(r){
                    printf("Removido: %d\n", r->valor);
                    free(r);
                }
                break;
            case 3: 
                imprimir(&fila);
                break;
            
            default:
                if(op != 0){
                    printf("\nOpcao invalida\n");
                }
        }
    }while(op!=0);

    return 0;
}