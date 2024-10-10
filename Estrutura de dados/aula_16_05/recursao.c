#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída em C.

int fatorial (int n) { // Declaração da função para calcular o fatorial de um número 'n'.
    //printf("n = %d\n", n); // Comentário para debug, imprime o valor de 'n'.
    if (n <= 1) { // Verifica se 'n' é menor ou igual a 1 e retorna 1.
        return 1;
    }
    return n * fatorial (n-1); // Retorna o produto de 'n' pelo fatorial de 'n-1'.
} // Fim da função 'fatorial'.

int fibonacci (int n) { // Declaração da função para calcular o n-ésimo número de Fibonacci.
    if (n <= 1) { // Verifica se 'n' é menor ou igual a 1 e retorna 1.
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2); // Retorna a soma dos dois números de Fibonacci anteriores a 'n'.
} // Fim da função 'fibonacci'.

int soma_1_a_n (int n) { // Declaração da função para calcular a soma dos números de 1 a 'n'.
    if (n > 0) { // Se 'n' for maior que 0, retorna 'n' mais a soma dos números de 1 a 'n-1'.
        return n + soma_1_a_n(n-1);
    }
    return 0; // Se 'n' for 0 ou negativo, retorna 0.
} // Fim da função 'soma_1_a_n'.

int main () { // Função principal do programa.
    for(int i = 1; i <= 20; i++) { // Loop para calcular e imprimir os números de Fibonacci de 1 a 20.
        printf("Fibonacci em %d = %d\n", i, fibonacci(i)); // Imprime o n-ésimo número de Fibonacci.
    }
    printf("\nSoma 1 a 10: %d\n", soma_1_a_n(10)); // Imprime a soma dos números de 1 a 10.
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso.
} // Fim da função 'main' e do programa.
