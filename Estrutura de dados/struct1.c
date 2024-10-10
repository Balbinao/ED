//exemplo de uma Struct: struct data {int dia, mes, ano};
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct data{
    int dia, mes, ano;
};
struct outra_data{
    int dia, mes, ano;
};
 
typedef struct{
    char nome[40];
    int ano_nascimento;
}  pessoa; //pessoa ja conta como um apelido ja definido pela Struct, por isso não precisa estar dentro dos colchetes.
 
typedef struct dia {
    int numero;
    char dia_semana[40];
}   t_dia_semana;
 
int main(){
    struct data d1, d2;
    d1.dia = 25;
    d1.mes = 04;
    d1.ano = 2024;
   
    printf ("%d/%d/%d\n", d1.dia, d1.mes, d1.ano);
 
    d2 = d1;
    printf ("%d/%d/%d\n", d2.dia, d2.mes, d2.ano);
 
    pessoa p;
    printf("digite o nome da pessoa:\n");
    //scanf("%s", &p.nome);
    fgets(p.nome, 39, stdin);
 
    printf("digite o ano de nascimento:\n");
    scanf("%d", &p.ano_nascimento);
 
    printf("\n%s nasceu em %d\n", p.nome, p.ano_nascimento);
 
    struct outra_data d;
    //d = d1;
 
    t_dia_semana ds;
    ds.numero = p.ano_nascimento;
    //ds.dia_semana = p.nome; --> não funciona
    strcpy(ds.dia_semana, p.nome); //strcpy serve para podermos fazer uma copia da string.
 
    printf("ds.numero = %d\nds.dia_semana = %s\n", ds.numero, ds.dia_semana);
 
    struct data *pd;
 
    pd = (struct data * ) malloc (sizeof(struct data));
 
    pd -> dia = 25;
    pd -> mes = 12;
    pd -> ano = 2024;
 
    printf("\nHO HO HO: %d/%d/%d\n", pd->dia, pd->mes, pd->ano);
 
 
return 0;
}