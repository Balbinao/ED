#include "lista.h" // Inclui o arquivo de cabeçalho "lista.h"

void inicializa_lista (t_lista *l) {
    l->tamanho = 0; // Inicializa o tamanho da lista como 0
    l->primeiro = NULL; // Inicializa o primeiro elemento da lista como NULL
}

int esta_vazia (t_lista *l) {
    return l->primeiro == NULL; // Retorna 1 (verdadeiro) se a lista estiver vazia, 0 (falso) caso contrário
}

void insere_inicio (int i, t_lista *l) {
    t_no * novo = constroi_no(i); // Cria um novo nó com o valor 'i'
    if (!esta_vazia(l)) {
        novo->proximo = l->primeiro; // Se a lista não estiver vazia, o novo nó aponta para o antigo primeiro nó
    }
    l->primeiro = novo; // O novo nó se torna o primeiro da lista
    l->tamanho++; // Incrementa o tamanho da lista
}

int remove_inicio (t_lista * l) {
    int temp = l->primeiro->info; // Guarda a informação do primeiro nó
    t_no * lixo = l->primeiro; // Guarda o primeiro nó para liberar memória depois
    l->primeiro = l->primeiro->proximo; // O segundo nó se torna o primeiro da lista
    l->tamanho--; // Decrementa o tamanho da lista
    free(lixo); // Libera a memória do nó removido
    return temp; // Retorna a informação do nó removido
}

void mostra_lista (t_lista l) {
    if (esta_vazia(&l)) {
        printf ("lista vazia\n"); // Se a lista estiver vazia, imprime "lista vazia"
    } else {
        t_no * aux = l.primeiro; // Auxiliar para percorrer a lista
        while (aux != NULL) { // Enquanto não chegar ao fim da lista
            printf ("| %d | -> ", aux->info); // Imprime a informação do nó atual
            aux = aux->proximo; // Avança para o próximo nó
        }
        printf("//\n"); // Imprime o fim da lista
    }
}

void insere_fim (int i, t_lista *l) {
    t_no * novo = constroi_no(i); // Cria um novo nó com o valor 'i'
    if (esta_vazia(l)) {
        l->primeiro = novo; // Se a lista estiver vazia, o novo nó se torna o primeiro
    } else {
        t_no * aux = l->primeiro; // Auxiliar para percorrer a lista
        while (aux->proximo != NULL) { // Enquanto não chegar ao último nó
            aux = aux->proximo; // Avança para o próximo nó
        }
        aux->proximo = novo; // O último nó aponta para o novo nó
    }
    l->tamanho++; // Incrementa o tamanho da lista
}

int remove_fim (t_lista *l) {
    int temp; // Variável para armazenar a informação do nó removido
    t_no * lixo; // Variável para armazenar o nó a ser removido
    if (l->primeiro->proximo == NULL) {
        temp = l->primeiro->info; // Se só houver um nó, guarda a informação desse nó
        lixo = l->primeiro; // Guarda esse nó para liberar memória depois
        l->primeiro = NULL; // A lista fica vazia
    } else {
        t_no * aux = l->primeiro; // Auxiliar para percorrer a lista
        while (aux->proximo->proximo != NULL) { // Enquanto não chegar ao penúltimo nó
            aux = aux->proximo; // Avança para o próximo nó
        }
        temp = aux->proximo->info; // Guarda a informação do último nó
        lixo = aux->proximo; // Guarda o último nó para liberar memória depois
        aux->proximo = NULL; // O penúltimo nó se torna o último
    }
    l->tamanho--; // Decrementa o tamanho da lista
    free(lixo); // Libera a memória do nó removido
    return temp; // Retorna a informação do nó removido
}
