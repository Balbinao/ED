//Considere uma lista contendo n´umeros inteiros positivos. Faca uma funcao que retorne
 //a media da lista.

#include "lista.h" // Inclui o arquivo de cabeçalho "lista.h"

int media_lista (t_lista *l) {
    int media = 0; // Variável para armazenar a média
    int soma = 0; // Variável para armazenar a soma dos elementos da lista
    int cont = 0; // Variável para contar o número de elementos na lista
    t_no *atual = l->primeiro; // Ponteiro para percorrer a lista, começando pelo primeiro nó
    while (atual != NULL) {
        soma += atual->info; // Adiciona a informação do nó atual à soma
        atual = atual->proximo; // Avança para o próximo nó
        cont++; // Incrementa o contador de elementos
    }
    media = soma / cont; // Calcula a média dividindo a soma pelo número de elementos
    return media; // Retorna a média
}

int main () {
    t_lista minha_lista; // Declara uma variável para a lista

    inicializa_lista(&minha_lista); // Inicializa a lista

    insere_fim (8, &minha_lista); // Insere o valor 8 no fim da lista
    insere_fim (4, &minha_lista); // Insere o valor 4 no fim da lista
    insere_fim (2, &minha_lista); // Insere o valor 2 no fim da lista

    mostra_lista (minha_lista); // Mostra os elementos da lista

    int media = media_lista(&minha_lista); // Calcula a média dos elementos da lista

    printf("a media da minha lista eh %d", media); // Imprime a média da lista

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}
