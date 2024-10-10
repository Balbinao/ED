#include <stdio.h>

int main() {
    int matriz[3][3];
    int somaLinhas[3] = {0};

    // Lendo a matriz 3x3
    printf("Digite a matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

  
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            somaLinhas[i] += matriz[i][j];
        }
    }


    printf("\nSomas das linhas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d: %d\n", i + 1, somaLinhas[i]);
    }

    return 0;
}
