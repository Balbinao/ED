// 16. Fazer uma funcao que copia uma lista L1 em uma outra lista L2.
#include "lista.h" // Inclui o arquivo de cabeçalho "lista.h"

void copia_lista(t_lista *l1, t_lista *l2) {
    inicializa_lista(l2); // Inicializa a lista l2 para garantir que esteja vazia

    t_no *atual_l1 = l1->primeiro; // Ponteiro para percorrer a lista l1
    while (atual_l1 != NULL) {
        insere_fim(atual_l1->info, l2); // Insere o valor do nó atual de l1 no fim de l2
        atual_l1 = atual_l1->proximo; // Avança para o próximo nó em l1
    }
}

int main() {
    t_lista l1, l2; // Declara duas listas, l1 e l2

    inicializa_lista(&l1); // Inicializa a lista l1

    insere_fim(5, &l1); // Insere o valor 5 no fim da lista l1
    insere_fim(4, &l1); // Insere o valor 4 no fim da lista l1

    printf("lista 1:\n");
    mostra_lista(l1); // Mostra os elementos da lista l1

    copia_lista(&l1, &l2); // Copia os elementos de l1 para l2

    printf("lista 2:\n");
    mostra_lista(l2); // Mostra os elementos da lista l2

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}
