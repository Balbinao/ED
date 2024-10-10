#include "fila.h"
int main() {
    t_fila fila, fila2;
    inicia_fila(&fila);
    inicia_fila(&fila2);
    // Testando enfileirar
    printf("Enfileirando 10, 20, 30...\n");
    enfileira(10, &fila);
    enfileira(20, &fila);
    enfileira(50, &fila);
    mostra_fila(&fila);
    
    enfileira(10, &fila2);
    enfileira(20, &fila2);
    enfileira(30, &fila2);

      if (filas_iguais(&fila, &fila2)) {
        printf("As filas sao iguais.\n");
    } else {
        printf("As filas nao sao iguais.\n");
    }
    // Testando desenfileirar
    printf("Desenfileirando...\n");
    desenfileira(&fila);
    mostra_fila(&fila);

    // Testando buscar na fila
    int valor_busca = 20;
    if (buscar_fila(&fila, valor_busca)) {
        printf("O valor %d esta presente na fila.\n", valor_busca);
    } else {
        printf("O valor %d nao esta presente na fila.\n", valor_busca);
    }

    valor_busca = 40;
    if (buscar_fila(&fila, valor_busca)) {
        printf("O valor %d esta presente na fila.\n", valor_busca);
    } else {
        printf("O valor %d nao esta presente na fila.\n", valor_busca);
    }

    // Testando reverter fila
    printf("Revertendo a fila...\n");
    reverter_fila(&fila);
    mostra_fila(&fila);

    // Testando desenfileirar após reverter
    printf("Desenfileirando apos reverter...\n");
    desenfileira(&fila);
    mostra_fila(&fila);

    // Testando enfileirar após reverter
    printf("Enfileirando 40...\n");
    enfileira(40, &fila);
    mostra_fila(&fila);
    limpar_fila(&fila);
    mostra_fila(&fila);
    return 0;
}