// Escreva um programa que utilize uma pilha para verificar se expressoes aritm ˜ eticas est ´ ao˜
// com a parentizac¸ao correta. O programa deve verificar express ˜ oes para ver se cada “abre ˜
// parenteses” tem um “fecha par ˆ enteses” correspondente. Ex.: ˆ
// Correto: ( ( ) ) – ( ( )( ) ) – ( ) ( )
// Incorreto: )( – ( ( ) ( – ) ) ( (


#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    char dado; 
    struct no* prox; 
} t_no;


void empilhar(t_no** topo, char valor) {
    t_no* novoNo = (t_no*)malloc(sizeof(t_no)); 
    novoNo->dado = valor;
    novoNo->prox = *topo; 
    *topo = novoNo; 
}


char desempilhar(t_no** topo) {
    if (*topo == NULL) {
        return '\0'; 
    }
    t_no* temp = *topo; 
    char valor = temp->dado; 
    *topo = (*topo)->prox; 
    free(temp); 
    return valor; 
}


int verificarExpressao(const char* expressao) {
    t_no* pilha = NULL; 

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar(&pilha, '('); //Empilha parênteses de abertura
        } else if (expressao[i] == ')') {
            if (pilha == NULL) {
                return 0; //retorna falso se tentar desempilhar uma pilha vazia
            }
            desempilhar(&pilha); //desempilha parênteses de fechamento
        }
    }

    //verifica se a pilha está vazia após processar a expressão
    return pilha == NULL;
}

int main() {
    const char* expressoes[] = {"((()))","(()(()))","()()",")(","((()(",")()("};

    int n = sizeof(expressoes) / sizeof(expressoes[0]); //calcula o número de expressões

    for (int i = 0; i < n; i++) {
        if (verificarExpressao(expressoes[i])) {
            printf("Correto: %s\n", expressoes[i]);
        } else {
            printf("Incorreto: %s\n", expressoes[i]);
        }
    }

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
