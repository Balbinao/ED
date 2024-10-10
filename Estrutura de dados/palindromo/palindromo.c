#include <string.h> // Inclui a biblioteca para operações de strings em C.
#include "pilha.h" // Inclui o arquivo de cabeçalho que contém a definição da estrutura da pilha e suas funções.

int main () {
    char c, s[101]; // Declaração de variáveis: c para armazenar cada caractere lido, 
    //s para armazenar a frase e o tamanho máximo é 100 caracteres.
    int i, tamanho, e_palindromo = 1; // Declaração de variáveis: i para índices, 
    //tamanho para o tamanho da frase e e_palindromo para verificar se é um palíndromo.
    t_pilha p; // Declaração de uma variável do tipo pilha.

    printf("Digite sua frase: "); // Imprime uma mensagem solicitando ao usuário que digite a frase.

    i = 0; // Inicializa o índice i como 0.
    while (i < 101 && ((c = getchar()) != '\n')){ // Loop para ler a frase caractere por caractere 
    //até atingir o final da linha ou o limite de 100 caracteres.
        s[i++] = c; // Armazena o caractere na posição i do vetor s e incrementa o índice i.
    }
    s[i] = '\0'; // Adiciona o caractere nulo ao final da string para indicar o término da mesma.
    tamanho = i; // Armazena o tamanho da frase lida na variável tamanho.

    constroi_pilha(&p, tamanho); // Constrói a pilha com o tamanho da frase.

    for (i = 0; i < tamanho; i++) { // Loop para empilhar cada caractere da frase na pilha.
        empilha(&p, s[i]); // Empilha o caractere na pilha.
    }

    for (i = 0; i < tamanho && e_palindromo; i++) { // Loop para verificar se a frase é um palíndromo.
        if (desempilha(&p) != s[i]) { // Compara o caractere desempilhado com o caractere correspondente da frase.
            e_palindromo = 0; // Se houver diferença, a frase não é um palíndromo.
        }
    }

    if (e_palindromo) { // Se for um palíndromo.
        printf("\n%s é palíndromo\n", s); // Imprime a mensagem indicando que a frase é um palíndromo.
    } else {
        printf("\n%s NÃO é palíndromo\n",s); // Imprime a mensagem indicando que a frase não é um palíndromo.
    }
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
}
