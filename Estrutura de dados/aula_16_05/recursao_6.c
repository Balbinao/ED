#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C.

// Função para calcular a potência de um número k elevado a n
int potencia (int k, int n) {
    if (n > 0) { // Se n for maior que 0
        return k * potencia(k, n - 1); // Retorna k multiplicado pela potência de k elevado a (n - 1)
    }
    return 1; // Retorna 1 se n for 0
}

// Função para calcular a multiplicação de dois inteiros n1 e n2
int multiplicacao (int n1, int n2) {
    if (n1 == 1) { // Se n1 for igual a 1
        return n2; // Retorna n2
    }
    return n2 + multiplicacao(n1 - 1, n2); // Retorna a soma de n2 com a multiplicação de (n1 - 1) por n2
}

// Função recursiva para exibir os elementos de um vetor v até a posição tam
void exibe_vetor_1(int i, int tam, int v[]) {
    if (i < tam) { // Se i for menor que tam
        printf("%d ", v[i]); // Imprime o elemento atual do vetor
        exibe_vetor_1(i + 1, tam, v); // Chama a função recursivamente com o próximo índice
    }
}

// Função recursiva para exibir os elementos de um vetor v a partir da posição n
void exibe_vetor_2 (int n, int v[]) {
    if (n > 0) { // Se n for maior que 0
        exibe_vetor_2(n - 1, v); // Chama a função recursivamente com o índice anterior
    }
    printf("%d ", v[n]); // Imprime o elemento atual do vetor
}

// Função recursiva para exibir os elementos de um vetor v a partir da posição n até 0
void exibe_vetor_3(int n, int v[]) {
    if (n > 0) { // Se n for maior que 0
        printf("%d\n", v[n]); // Imprime o elemento atual do vetor
        exibe_vetor_3(n - 1, v); // Chama a função recursivamente com o índice anterior
    }
}

int main () {
    printf("2^4 = %d\n", potencia(2, 4)); // Chamada da função para calcular a potência de 2 elevado a 4
    printf("5 x 4 = %d\n", multiplicacao(5, 4)); // Chamada da função para calcular a multiplicação de 5 por 4
    int v[10] = {1, 4, 3, 4, 5}; // Declaração de um vetor com valores iniciais
    printf("teste 1:\n");
    exibe_vetor_1(0, 5, v); // Chamada da função para exibir os elementos do vetor v a partir da posição 0 até 4
    printf("\nteste 2:\n");
    exibe_vetor_2(4, v); // Chamada da função para exibir os elementos do vetor v a partir da posição 4 até 0
    printf("\nTeste 3:\n");
    exibe_vetor_3(4, v); // Chamada da função para exibir os elementos do vetor v a partir da posição 4 até 0
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
