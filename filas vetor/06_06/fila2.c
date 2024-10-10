#include "fila.h"

// Função para construir a fila com uma capacidade dada
t_fila * constroi_fila (int capacidade){
    t_fila * pf = (t_fila *)malloc(sizeof(t_fila)); // Aloca memória para a estrutura da fila
    if (pf != NULL){ // Verifica se a alocação foi bem sucedida
        pf->v = (int *)malloc(capacidade * sizeof(int)); // Aloca memória para o array de inteiros dentro da fila
        if(pf->v == NULL){ // Verifica se a alocação do array foi bem sucedida
            return NULL; // Se falhou, retorna NULL
        }
        pf->capacidade = capacidade; // Define a capacidade da fila
        pf->tamanho = 0; // Inicializa o tamanho da fila como 0
        pf->primeiro = 0; // Define a posição do primeiro elemento como 0
        pf->ultimo = 0; // Define a posição do último elemento como 0
    }
    return pf; // Retorna o ponteiro para a fila recém-criada
}

// Função para verificar se a fila está vazia
int esta_vazia(t_fila *pf){
    return pf->tamanho == 0; // Retorna 1 (true) se o tamanho da fila for 0
}

// Função para verificar se a fila está cheia
int esta_cheia(t_fila *pf){
    return pf->tamanho == pf->capacidade; // Retorna 1 (true) se o tamanho da fila for igual à sua capacidade
}

// Função para calcular a próxima posição circularmente
int proxima_posicao(int posicao, t_fila *pf){
    return (posicao + 1) % pf->capacidade; // Retorna a próxima posição na fila circular
}

// Função para adicionar um elemento à fila
int enfileira(int i, t_fila *pf){
    if(esta_cheia(pf)){ // Verifica se a fila está cheia
        return 0; // Retorna 0 se a fila estiver cheia
    }
    pf->v[pf->ultimo] = i; // Coloca o elemento na posição 'ultimo' da fila
    pf->ultimo = proxima_posicao(pf->ultimo, pf); // Atualiza a posição do último elemento
    pf->tamanho++; // Incrementa o tamanho da fila
    return 1; // Retorna 1 indicando sucesso
}

// Função para remover um elemento da fila
int desenfileira(int *pi, t_fila *pf){
    if(esta_vazia(pf)){ // Verifica se a fila está vazia
        return 0; // Retorna 0 se a fila estiver vazia
    }
    *pi = pf->v[pf->primeiro]; // Armazena o elemento na posição 'primeiro' em 'pi'
    pf->primeiro = proxima_posicao(pf->primeiro, pf); // Atualiza a posição do primeiro elemento
    pf->tamanho--; // Decrementa o tamanho da fila
    return 1; // Retorna 1 indicando sucesso
}

// Função para mostrar os elementos da fila
void mostra_fila(t_fila *pf){
    if(esta_vazia(pf)){ // Verifica se a fila está vazia
        printf("Fila vazia"); // Imprime mensagem se a fila estiver vazia
    } else {
        int i = pf->primeiro; // Começa do primeiro elemento
        do {
            printf("%d ", pf->v[i]); // Imprime o elemento na posição atual
            i = proxima_posicao(i, pf); // Move para a próxima posição
        } while(i != pf->ultimo); // Continua até chegar na posição do último elemento
    }
    printf(" | "); // Imprime uma barra separadora
}

// Função para mostrar o array interno da fila
void mostra_vetor(t_fila *pf){
    int i;
    if(esta_cheia(pf)){
        for(i = 0; i < pf->capacidade; i++){
            printf("%d ", pf->v[i]); // Imprime todos os elementos se a fila estiver cheia
        }
    }
    else if(pf->primeiro <= pf->ultimo){
        for(i = 0; i < pf->primeiro; i++){
            printf("_ "); // Imprime underscore para posições antes do primeiro elemento
        }
        for(i = pf->primeiro; i < pf->ultimo; i++){
            printf("%d ", pf->v[i]); // Imprime os elementos entre o primeiro e o último
        }
        for(i = pf->ultimo; i < pf->capacidade; i++){
            printf("_ "); // Imprime underscore para posições após o último elemento
        }
    }
    else{
        for(i = 0; i < pf->ultimo; i++){
            printf("%d ", pf->v[i]); // Imprime os elementos até a posição do último elemento
        }
        for(i = pf->ultimo; i < pf->primeiro; i++){
            printf("_ "); // Imprime underscore para posições entre o último e o primeiro elementos
        }
        for (i = pf->primeiro; i < pf->capacidade; i++){
            printf("%d ", pf->v[i]); // Imprime os elementos da posição do primeiro até o final
        }
    }
    printf("\n"); // Quebra de linha ao final
}

// Função para retornar o primeiro elemento da fila
int primeiro_elemento(t_fila *pf) {
    if (esta_vazia(pf)) { // Verifica se a fila está vazia
        printf("Fila vazia\n");
        return -1; // Retorna -1 se a fila estiver vazia
    }
    return pf->v[pf->primeiro]; // Retorna o elemento na posição 'primeiro'
}

// Função para contar elementos pares e ímpares na fila circular
void conta_pares_impares(t_fila *pf, int *pares, int *impares) {
    *pares = 0;
    *impares = 0;

    if (esta_vazia(pf)) { // Verifica se a fila está vazia
        return; // Retorna sem fazer nada se a fila estiver vazia
    }

    int i = pf->primeiro;
    do {
        if (pf->v[i] % 2 == 0) {
            (*pares)++; // Incrementa o contador de pares se o elemento for par
        } else {
            (*impares)++; // Incrementa o contador de ímpares se o elemento for ímpar
        }
        i = proxima_posicao(i, pf); // Move para a próxima posição
    } while (i != pf->ultimo); // Continua até chegar na posição do último elemento
}

// Função para mesclar duas filas circulares
t_fila* merge_filas(t_fila *pf1, t_fila *pf2) {
    int nova_capacidade = pf1->capacidade + pf2->capacidade; // Define a nova capacidade como a soma das capacidades das duas filas
    t_fila *nova_fila = constroi_fila(nova_capacidade); // Constrói a nova fila com a capacidade combinada

    int i;
    // Enfileira todos os elementos da primeira fila
    i = pf1->primeiro;
    while (i != pf1->ultimo) {
        enfileira(pf1->v[i], nova_fila); // Enfileira cada elemento da primeira fila na nova fila
        i = proxima_posicao(i, pf1); // Move para a próxima posição
    }

    // Enfileira todos os elementos da segunda fila
    i = pf2->primeiro;
    while (i != pf2->ultimo) {
        enfileira(pf2->v[i], nova_fila); // Enfileira cada elemento da segunda fila na nova fila
        i = proxima_posicao(i, pf2); // Move para a próxima posição
    }

    return nova_fila; // Retorna a nova fila combinada
}

// Função para verificar se um elemento existe na fila
int existe_na_fila(int x, t_fila *pf) {
    int i = pf->primeiro;
    do {
        if (pf->v[i] == x) {
            return 1; // Retorna 1 se o elemento for encontrado
        }
        i = proxima_posicao(i, pf); // Move para a próxima posição
    } while (i != pf->ultimo); // Continua até chegar na posição do último elemento
    return 0; // Retorna 0 se o elemento não for encontrado
}

// Função para remover elementos duplicados na fila
void remove_duplicados(t_fila *pf) {
    t_fila *nova_fila = constroi_fila(pf->capacidade); // Constrói uma nova fila com a mesma capacidade

    int i = pf->primeiro;
    do {
        if (!existe_na_fila(pf->v[i], nova_fila)) {
            enfileira(pf->v[i], nova_fila); // Enfileira o elemento na nova fila se não for duplicado
        }
        i = proxima_posicao(i, pf); // Move para a próxima posição
    } while (i != pf->ultimo); // Continua até chegar na posição do último elemento

    // Copia os elementos da nova fila de volta para a fila original
    *pf = *nova_fila;
    free(nova_fila); // Libera a memória da nova fila
}

// Função para verificar se a fila é um palíndromo
int verifica_palindromo(t_fila *pf) {
    int inicio = pf->primeiro; // Inicializa 'inicio' com a posição do primeiro elemento
    int fim = (pf->ultimo - 1 + pf->capacidade) % pf->capacidade; // Inicializa 'fim' com a posição do último elemento

    while (inicio != fim && proxima_posicao(inicio, pf) != fim) { // Continua enquanto 'inicio' não encontra 'fim'
        if (pf->v[inicio] != pf->v[fim]) {
            return 0; // Retorna 0 se os elementos em 'inicio' e 'fim' forem diferentes
        }
        inicio = proxima_posicao(inicio, pf); // Move 'inicio' para a próxima posição
        fim = (fim - 1 + pf->capacidade) % pf->capacidade; // Move 'fim' para a posição anterior
    }
    return 1; // Retorna 1 se a fila for um palíndromo
}
