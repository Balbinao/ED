#include "pilha.h" // Inclui o arquivo de cabeçalho que contém a definição da estrutura da pilha e suas funções.

// Função para construir uma pilha com uma capacidade especificada
void constroi_pilha(t_pilha *pilha, int capacidade) {
    pilha->dados = (int *)malloc(capacidade * sizeof(int)); // Aloca memória para os dados da pilha
    if (pilha->dados == NULL) { // Verifica se a alocação de memória foi bem-sucedida
        printf("Erro ao alocar memória para a pilha\n"); // Imprime uma mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }
    pilha->topo = -1; // Inicializa o topo da pilha como -1
    pilha->capacidade = capacidade; // Define a capacidade da pilha
}

// Função para verificar se a pilha está vazia
int esta_vazia(const t_pilha *pilha) {
    return pilha->topo == -1; // Retorna verdadeiro se o topo da pilha for -1, indicando que a pilha está vazia
}

// Função para verificar se a pilha está cheia
int esta_cheia(const t_pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1; // Retorna verdadeiro se o topo da pilha for igual à capacidade - 1, 
    //indicando que a pilha está cheia
}

// Função para obter o tamanho atual da pilha
int tamanho_pilha(const t_pilha *pilha) {
    return pilha->topo + 1; // Retorna o tamanho atual da pilha, que é igual ao topo + 1
}

// Função para empilhar um item na pilha
void empilha(t_pilha *pilha, int item) {
    if (esta_cheia(pilha)) { // Verifica se a pilha está cheia
        printf("Erro: Pilha cheia\n"); // Imprime uma mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }
    pilha->dados[++(pilha->topo)] = item; // Incrementa o topo da pilha e armazena o item na nova posição do topo
}

// Função para desempilhar um item da pilha
int desempilha(t_pilha *pilha) {
    if (esta_vazia(pilha)) { // Verifica se a pilha está vazia
        printf("Erro: Pilha vazia\n"); // Imprime uma mensagem de erro
        exit(1); // Encerra o programa com código de erro 1
    }
    return pilha->dados[(pilha->topo)--]; // Retorna o item no topo da pilha e decrementa o topo
}

// Função para exibir os elementos da pilha
void mostra_pilha(t_pilha *pilha) {
    if (esta_vazia(pilha)) { // Verifica se a pilha está vazia
        printf("Pilha vazia\n"); // Imprime uma mensagem indicando que a pilha está vazia
        return; // Retorna da função
    }
    printf("Elementos da pilha: "); // Imprime uma mensagem indicando que os elementos da pilha serão exibidos
    for (int i = pilha->topo; i >= 0; i--) { // Loop para percorrer os elementos da pilha do topo para a base
        printf("%d ", pilha->dados[i]); // Imprime o elemento atual da pilha
    }
    printf("\n"); // Imprime uma nova linha após exibir todos os elementos da pilha
}
