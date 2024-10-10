// 5. Considere uma pilha que armazene caracteres. Fac¸a uma func¸ao para determinar se ˜
// uma string e da forma XY, onde X ´ e uma cadeia formada por caracteres arbitr ´ arios e Y ´
// e o reverso de X. Por exemplo, se x = ABCD, ent ´ ao y = DCBA. Considere que x e y s ˜ ao˜
// duas strings distintas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no {
    char dado;
    struct no* prox;
} t_no;


void empilhar(t_no** topo, char valor) {
    t_no* novoNo = (t_no*)malloc(sizeof(t_no)); 
    novoNo->dado = valor; //atribui o valor ao campo 'dado' do novo nó
    novoNo->prox = *topo; //define o próximo nó como o nó atual do topo
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


int saoXy(const char* str1, const char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2) {
        return 0; //se as strings tiverem comprimentos diferentes, não podem ser reversas uma da outra
    }
    
    //verifica caractere por caractere
    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[n1 - i - 1]) {
            return 0; //etorna falso se houver uma diferença
        }
    }
    return 1; //retorna verdadeiro se forem reversas uma da outra
}

int main() {
    char str1[100], str2[100];
    

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);

    //verifica se sao xy
    if (saoXy(str1, str2)) {
        printf("eh XY!.\n", str1, str2);
    } else {
        printf("Nao eh XY.\n", str1, str2);
    }

    return 0;
}