// Escreva uma funcao que verifica se duas listas dadas sao iguais (mesmo conteudo)

#include "lista.h" // Inclui o arquivo de cabeçalho "lista.h"

int listas_iguais(t_lista *l1, t_lista *l2) {
    t_no *atual_l1 = l1->primeiro; // Ponteiro para percorrer a lista l1
    t_no *atual_l2 = l2->primeiro; // Ponteiro para percorrer a lista l2

    while (atual_l1 != NULL && atual_l2 != NULL) { // Percorre ambas as listas enquanto não chegar ao fim de nenhuma
        if (atual_l1->info != atual_l2->info) { // Compara a informação dos nós atuais
            return 0; // Se a informação for diferente, as listas não são iguais
        }
        atual_l1 = atual_l1->proximo; // Avança para o próximo nó em l1
        atual_l2 = atual_l2->proximo; // Avança para o próximo nó em l2
    }

    if (atual_l1 != NULL || atual_l2 != NULL) { // Verifica se uma lista terminou antes da outra
        return 0; // Se uma lista terminou antes da outra, as listas não são iguais
    }

    return 1; // Se as listas têm o mesmo comprimento e os mesmos elementos, são iguais
}

int main() {
    t_lista l1, l2; // Declara duas listas, l1 e l2

    inicializa_lista(&l1); // Inicializa a lista l1
    inicializa_lista(&l2); // Inicializa a lista l2

    insere_fim(5, &l1); // Insere o valor 5 no fim da lista l1
    insere_fim(2, &l1); // Insere o valor 2 no fim da lista l1
    insere_fim(5, &l2); // Insere o valor 5 no fim da lista l2

    printf("lista 1:\n");
    mostra_lista(l1); // Mostra os elementos da lista l1
    printf("lista 2:\n");
    mostra_lista(l2); // Mostra os elementos da lista l2

    if (listas_iguais(&l1, &l2)) {
        printf("\nsao iguais"); // Imprime se as listas são iguais
    } else {
        printf("\nnao sao iguais"); // Imprime se as listas não são iguais
    }

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}
