#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C.
#include <stdlib.h> // Inclui a biblioteca padrão de funções utilitárias em C.
#include <string.h> // Inclui a biblioteca para operações de strings em C.
#include "pilha.h" // Inclui o arquivo de cabeçalho que contém a definição da estrutura da pilha e suas funções.

// Função para verificar se uma string é palíndromo
int eh_palindromo(const char *str) {
    int len = strlen(str); // Obtém o tamanho da string
    t_pilha pilha; // Declara uma variável do tipo pilha
    constroi_pilha(&pilha, len); // Constrói a pilha com o tamanho da string

    // Empilha metade dos caracteres da string
    for (int i = 0; i < len / 2; i++) {
        empilha(&pilha, str[i]); // Empilha o caractere na pilha
    }

    // Verifica se os caracteres restantes formam um palíndromo
    int j = len % 2 == 0 ? len / 2 : len / 2 + 1; // Calcula o índice inicial para comparar os caracteres
    for (; j < len; j++) {
        if (str[j] != desempilha(&pilha)) { // Compara o caractere atual com o desempilhado
            return 0; // Não é um palíndromo
        }
    }

    return 1; // É um palíndromo
}

int main() {
    char str[100]; // Declara uma string para armazenar a entrada do usuário
    printf("Digite uma string: "); // Solicita ao usuário que digite uma string
    scanf("%s", str); // Lê a string fornecida pelo usuário

    if (eh_palindromo(str)) { // Verifica se a string é um palíndromo usando a função eh_palindromo
        printf("%s é um palíndromo.\n", str); // Imprime que a string é um palíndromo
    } else {
        printf("%s não é um palíndromo.\n", str); // Imprime que a string não é um palíndromo
    }

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
