#include <stdio.h>
#include <string.h>

int main () {
    char palavra[100];
    int i, cont;

    printf("Digite uma palavra: ");
    scanf("%s ", &palavra);

    for(i = 0; i < strlen(palavra); i++){
        if(palavra[i] == 'a' || palavra[i] == 'A'){
            cont++;
        }
    }
    printf("%d\n", cont);
}