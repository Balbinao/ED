#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
typedef struct{
    int dia, mes, ano;
}t_data;
 
t_data le_data(){
    t_data data;
    printf("Digite o dia: ");
    scanf("%d", &data.dia);
   
    printf("digite p mes: ");
    scanf("%d", &data.mes);
   
    printf("digite o ano: ");
    scanf("%d", &data.ano);
    return data;
}
void mostra_data(t_data data){
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}
int * le_vetor(int t){
    int * v = (int *) malloc (t * sizeof(int));
    //int v[t];
    for(int i=0; i<t; i++){
        printf("%d: ",i);
        scanf("%d", &v[i]);
    }
    return v;
}
int * gera_vetor (int t) {
    int * v = (int *) malloc (t * sizeof(int));
    for(int i=0; i<t; i++) {
        v[i] = rand() % 1000;
    }
    return v;
}
 
void mostra_vetor(int*v, int t){
    // printf("\nendereco do vetor: %p\n", v);
    // for(int i=0; i<t; i++){
    //     printf("%d ", v[i]);
    // }
}
t_data data_seguinte (t_data data){
    

}
int main(){
    //t_data d1, d2;
    //d1 = le_data();
    //mostra_data(d1);
    //d2 = le_data();
    //mostra_data(d2);
 
    int t;
    srand(time(0));
    printf("Escolha o tamanho do vetor, 0 encerra: ");
    scanf("%d", &t);
 
 
    while (t>0) {
        int *v = gera_vetor(t);
        mostra_vetor(v, t);
        printf("Escolha o tamanho do vetor, 0 encerra");
        scanf("%d", &t);
        free(v);
    }
    int * v = le_vetor(5);
 
    return 0;
}