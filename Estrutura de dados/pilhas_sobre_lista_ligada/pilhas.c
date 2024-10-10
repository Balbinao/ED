#include "pilha.h" // Inclui o arquivo de cabeçalho que contém a definição da estrutura da pilha e suas funções.

// Função para construir uma pilha com uma capacidade especificada
void constroi_pilha(t_pilha *p, int capacidade){
    p -> dados = (int *) malloc (capacidade); // Aloca memória para os dados da pilha
    p -> capacidade = capacidade; // Define a capacidade da pilha
    p -> topo = 0; // Inicializa o topo da pilha para a primeira posição disponível
}

// Função para verificar se a pilha está vazia
int esta_vazia (const t_pilha *p){
    return p -> topo == 0; // Retorna verdadeiro se o topo da pilha for 0, indicando que a pilha está vazia
}

// Função para verificar se a pilha está cheia
int esta_cheia(const t_pilha *p ){
    return p -> topo == p -> capacidade; // Retorna verdadeiro se o topo da pilha for igual à capacidade, 
    //indicando que a pilha está cheia
}

// Função para obter o tamanho atual da pilha
int tamanho_pilha(const t_pilha *p ){
    return p -> topo; // Retorna o valor do topo da pilha, que indica o tamanho atual da pilha
}

// Função para empilhar um caractere na pilha
void empilha(t_pilha *p, char c){
    p -> dados [p -> topo++ ] = c; // Armazena o caractere na posição do topo da pilha e incrementa o topo
}

// Função para desempilhar um caractere da pilha
char desempilha(t_pilha *p){
    return p -> dados [--p -> topo]; // Retorna o caractere na posição do topo da pilha e decrementa o topo
}

// Função para mostrar os elementos da pilha
void mostra_pilha(t_pilha *p){
    if(esta_vazia(p)){ // Verifica se a pilha está vazia
        printf("pilha vazia\n"); // Se estiver vazia, imprime uma mensagem indicando que a pilha está vazia
    }
    else{
        for(int i = p -> topo - 1; i >= 0; i--){ // Loop para percorrer os elementos da pilha do topo até o início
            printf("%c", p -> dados[i]); // Imprime o caractere na posição i da pilha
        }
    }
}
