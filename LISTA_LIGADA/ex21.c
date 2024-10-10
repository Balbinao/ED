//Escreva uma funcao que crie uma lista encadeada a partir de um vetor.

#include "lista.h" // Inclui o arquivo de cabeçalho "lista.h"

void lista_de_vetor(int v[], int tamanho, t_lista *lista) {
    inicializa_lista(lista); // Inicializa a lista para garantir que esteja vazia

    for (int i = 0; i < tamanho; i++) {
        insere_fim(v[i], lista); // Insere cada elemento do vetor no fim da lista
    }
}

int main() {
    int v[] = {1, 2, 3, 4}; // Declara e inicializa um vetor de inteiros
    t_lista minha_lista; // Declara uma lista

    lista_de_vetor(v, 4, &minha_lista); // Cria uma lista a partir do vetor

    mostra_lista(minha_lista); // Mostra os elementos da lista

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}
