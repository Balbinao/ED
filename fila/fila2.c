#include "fila.h" // Inclui o cabeçalho da fila (definições e declarações)

// Inicializa a fila deixando-a vazia
void inicia_fila(t_fila * f){
    f->primeiro = f->ultimo = NULL; // Define que o primeiro e último elementos são NULL
    f->tamanho = 0; // Define o tamanho inicial como 0
}

// Verifica se a fila está vazia
int esta_vazia(t_fila * f){
    return f->tamanho == 0; // Retorna 1 (verdadeiro) se o tamanho da fila for 0, caso contrário retorna 0
}

// Enfileira (adiciona) um elemento na fila
void enfileira(int x, t_fila * f){
    t_no * novoNo = constroi_no(x); // Cria um novo nó com o valor x

    if(esta_vazia(f)){ // Se a fila estiver vazia
        f->primeiro = novoNo; // O novo nó se torna o primeiro da fila
    }else{
        f->ultimo->proximo = novoNo; // O último nó aponta para o novo nó
    }
    f->ultimo = novoNo; // O novo nó se torna o último da fila
    f->tamanho++; // Incrementa o tamanho da fila
}

// Desenfileira (remove) um elemento da fila
int desenfileira(t_fila * f){
    int temp = f->primeiro->info; // Armazena o valor do primeiro elemento
    t_no * lixo = f->primeiro; // Armazena o ponteiro do primeiro elemento
    f->primeiro = f->primeiro->proximo; // Atualiza o primeiro para o próximo elemento
    f->tamanho--; // Decrementa o tamanho da fila

    if(esta_vazia(f)){ // Se a fila ficar vazia
        f->ultimo = NULL; // Define o último elemento como NULL
    }

    free(lixo); // Libera a memória do antigo primeiro elemento
    return temp; // Retorna o valor do elemento removido
}

// Mostra os elementos da fila
void mostra_fila(t_fila * f){
    if(esta_vazia(f)){ // Se a fila estiver vazia
        printf("\nFila Vazia\n"); // Imprime mensagem indicando fila vazia
    }else{
        t_no * aux = f->primeiro; // Inicia no primeiro elemento
        while(aux != NULL){ // Percorre até o final da fila
            printf("%d ", aux->info); // Imprime o valor do elemento atual
            aux = aux->proximo; // Move para o próximo elemento
        }
        printf("\n"); // Nova linha ao final da impressão da fila
    }
}

// Busca por um elemento específico na fila
int buscar_fila(t_fila *fila, int valor) {
    t_no *aux = fila->primeiro; // Inicia no primeiro elemento
    while (aux != NULL) { // Percorre até o final da fila
        if (aux->info == valor) { // Se encontrar o valor
            return 1; // Retorna 1 (verdadeiro)
        }
        aux = aux->proximo; // Move para o próximo elemento
    }
    return 0; // Retorna 0 (falso) se o valor não for encontrado
}

// Reverte a ordem dos elementos na fila
void reverter_fila(t_fila *fila) {
    t_no *anterior = NULL, *atual = fila->primeiro, *proximo = NULL; // Declara ponteiros auxiliares
    fila->ultimo = fila->primeiro; // Define o último como o primeiro
    while (atual != NULL) { // Percorre até o final da fila
        proximo = atual->proximo; // Armazena o próximo nó
        atual->proximo = anterior; // Inverte a direção do ponteiro
        anterior = atual; // Move o ponteiro anterior para o atual
        atual = proximo; // Move para o próximo elemento
    }
    fila->primeiro = anterior; // O novo primeiro é o antigo último
}

// Remove todos os elementos da fila
void limpar_fila(t_fila *fila) {
    t_no *aux = fila->primeiro; // Inicia no primeiro elemento
    while (aux != NULL) { // Percorre até o final da fila
        t_no *temp = aux; // Armazena o ponteiro do elemento atual
        aux = aux->proximo; // Move para o próximo elemento
        free(temp); // Libera a memória do elemento atual
    }
    fila->primeiro = NULL; // Define o primeiro como NULL
    fila->ultimo = NULL; // Define o último como NULL
    fila->tamanho = 0; // Reseta o tamanho da fila para 0
}

// Compara duas filas para verificar se são iguais
int filas_iguais(t_fila *fila1, t_fila *fila2) {
    t_no *aux1 = fila1->primeiro; // Inicia no primeiro elemento da fila1
    t_no *aux2 = fila2->primeiro; // Inicia no primeiro elemento da fila2
    while (aux1 != NULL && aux2 != NULL) { // Percorre ambas as filas
        if (aux1->info != aux2->info) { // Se encontrar valores diferentes
            return 0; // Retorna 0 (falso)
        }
        aux1 = aux1->proximo; // Move para o próximo elemento na fila1
        aux2 = aux2->proximo; // Move para o próximo elemento na fila2
    }
    return aux1 == NULL && aux2 == NULL; // Retorna 1 (verdadeiro) se ambas as filas forem do mesmo tamanho e tiverem os mesmos valores
}
