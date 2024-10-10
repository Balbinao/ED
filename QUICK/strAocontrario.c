#include <stdio.h>

int main() {
    char palavra[100];
    int tamanho = 0;
    char ch;


    printf("Digita ai: ");
    while ((ch = getchar()) != '\n' && tamanho < 100 - 1) {
        palavra[tamanho] = ch;
        tamanho++;
    }
    palavra[tamanho] = '\0'; 


    printf("Oq foi digitado ao contrario: ");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", palavra[i]);
    }
    printf("\n");

    return 0;
}
