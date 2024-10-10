#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int dia, mes, ano;
}t_data; //struct tipo data

int valida_data (t_data data){
    if (data.dia < 1 || data.mes < 1  || data.mes > 12 || data.ano <1900 || data.ano >2024) return 0;
    switch(data.mes){
    case 1:
    case 3:
    case 5:
    case 7: 
    case 8:
    case 10:
    case 12:
        if(data.dia > 31){
            return 0;
        }
        break;
    case 2:
       if(data.dia > 28){
        return 0;
       }
       break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(data.dia > 30){
            return 0;
        }
        break;

    }
    return 1;
}

t_data le_data(){
    t_data data;
    int valida;

    do {
        printf ("\ndigite o dia: ");
        scanf ("%d", &data.dia);
        printf("\ndigite o mes: ");
        scanf("%d", &data.mes);
        printf("\ndigite o ano: ");
        scanf("%d", &data.ano);
        valida = valida_data (data);
        if (!valida)
            printf ("data invalida");
    } while (!valida);
    return data; 


    return data; //retornando toda a informação de data  
}   

void mostra_data (t_data data) {
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}

int * le_vetor(int t){
    // int v[t]; --> alocaçao de variável local
    int * v = (int *)malloc(t *sizeof(int)); // --> alocação de variável dinamica
    for(int i = 0; i < t; i++){
        printf("%d: ", i);
        scanf("%d", &v[i]);
    }
    return v;
}

int * gera_vetor (int t){
    int * v = (int *) malloc(t *sizeof(int));
    for(int i = 0; i < t; i++){
        v[i] = rand() % 1000;
    }
    return v; 
}

void mostra_vetor (int * v, int t){
    printf("\nEndereco do vetor: %p\n", v);
    // for(int i = 0; i<t; i++){
    //     printf("%d", v[i]);
    // }
}

t_data data_seguinte (t_data data){
    switch(data.mes){
        case 1:
        case 3:
        case 5:
        case 7: 
        case 8:
        case 10:
            data.dia += 1;
            if(data.dia == 32){
                data.mes += 1;
                data.dia = 1;
            }
            break;
        case 12:
            data.dia += 1;
            if(data.dia == 32){
                data.mes = 1;
                data.dia = 1;
                data.ano += 1;
            }
            
            break;
        case 2:
            data.dia += 1;
            if(data.dia == 29){
                data.mes += 1;
                data.dia = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            data.dia += 1;
            if(data.dia == 31){
                data.mes += 1;
                data.dia = 1;
            }
            break;

    }
    return data;
}
int main () {

    t_data d1, d2;
    d1 = le_data(); // chama a função para fazer a leitura
    mostra_data(d1);
    d2 = data_seguinte(d1);
    mostra_data(d2);
   
    int t;
    srand(time(0));
    printf("Escolha o tamanho do vetor, 0 encerra: ");
    scanf("%d", &t);

    while (t > 0){
        int * v = gera_vetor(t);
        mostra_vetor(v, t);
        printf("Escolha o tamanho do vetor, 0 encerra: ");
        free(v);
        scanf("%d", &t);
        
    }

    return 0;
}