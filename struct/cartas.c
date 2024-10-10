#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

typedef struct{
    int num;
    char naipe[40];
}t_carta;

typedef struct{
    t_carta baralho[5];
    int num;
    char nome [100];
}t_jogador;

t_carta gerar_carta(){
    t_carta carta;
    char naipes [4][40] = {"paus","ouro","espadas","copas"};
    carta.num = 1+rand()%12;
    int qual_naipe = (int)rand()&3;
    strcpy(carta.naipe, naipes[qual_naipe]);
    char teste[40];
    //printf("%s\n", carta.naipe);
    return carta;
}

void mostrar_carta(t_carta carta){
    char letras [4] = {'A','J','Q','K'};
    if(carta.num == 1){
        printf("\t%c de %s\n",letras[carta.num-1], carta.naipe);
    }
    else if(carta.num > 10){
        printf("\t%c de %s\n",letras[carta.num-10], carta.naipe);
    }
    else{
        printf("\t%d de %s\n",carta.num, carta.naipe);
    }
}

void mostrar_jogador(t_jogador j, int qnts){
    printf("Baralho do jogador %d, %s:\n", j.num, j.nome);
    for(int i = 0; i < qnts; i++){
        mostrar_carta(j.baralho[i]);
    }
}

void dar_nome(t_jogador *j){
    printf("Digite o nome do jogador %d: ",j->num);
    scanf("%99[^\n]s", j->nome);
    getchar();
}

int main(){
    srand(time(NULL));
    // t_jogador j1, j2;
    // j1.num = 1;
    // j2.num = 2;
    // dar_nome(&j1);
    // dar_nome(&j2);
    // for(int i = 0; i<5; i++){
    //     j1.baralho[i] = gerar_carta();
    //     j2.baralho[i] = gerar_carta();
    // }
    // mostrar_jogador(j1);
    // mostrar_jogador(j2);
    t_jogador *jogadores;
    int qnts_jogadores = 2;
    int qnts_cartas = 13;
    jogadores = (t_jogador *)malloc(10*sizeof(t_jogador));
    for(int i = 0; i < qnts_jogadores; i++){
        jogadores[i].num = i+1;
        dar_nome(&jogadores[i]);
        for(int j = 0; j < qnts_cartas; j++){
            jogadores[i].baralho[j] = gerar_carta();
        }
    }
    for(int i = 0; i < qnts_jogadores; i++){
        mostrar_jogador(jogadores[i], qnts_cartas);
    }

    return 0;
}  