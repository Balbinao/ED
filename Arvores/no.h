#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *esq, *dir;
}t_no;

t_no * constroi_no(int);
void mostra_no(t_no *);

