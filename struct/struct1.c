#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
    int dia, mes, ano;
};

struct outra_data{
    int dia, mes, ano;
};

typedef struct {
    char nome[40];
    int ano_nascimento;
}pessoa;

typedef struct dia {
    int num;
    char dia_semana[40];
}t_dia_semana;

int main () {
    struct data d1, d2;
    d1.dia = 25;
    d1.mes = 4;
    d1.ano = 2024;
    printf("%d/%d/%d\n", d1.dia, d1.mes, d1.ano);
    d2 = d1;
    printf("%d/%d/%d\n", d2.dia, d2.mes, d2.ano);
    
    pessoa p;
    printf("Digite um nome: ");
    //scanf("%s", &p.nome);
    fgets(p.nome, 39, stdin);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &p.ano_nascimento);

    printf("\n%snasceu em %d\n", p.nome, p.ano_nascimento);

    struct outra_data d;
    // d = d1; um valor do tipo \"struct data\" não pode ser atribuído para uma entidade do tipo \"struct outra_data\"",

    t_dia_semana ds;
    ds.num = p.ano_nascimento;
    //ds.dia_semana = p.nome --> não funciona
    strcpy(ds.dia_semana, p.nome);

    printf("\nds.num = %d\nds.dia_semana = %s\n", ds.num, ds.dia_semana);

    struct data *pd;
    pd = (struct data *)malloc(sizeof*(struct data));

    pd->dia = 25;
    pd->mes = 12;
    pd->ano = 2024;

    printf("\nHo Ho Ho: %d/%d/%d\n", pd->dia, pd->mes, pd->ano);

    return 0;
}