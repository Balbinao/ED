#include "no.h"

typedef struct abb{
    t_no * raiz;
}t_abb;

void inicializa_abb(t_abb *);
int esta_vazia(t_abb *);
void insere (int, t_abb *);
void exibe_em_ordem(t_abb *);
void exibe_em_pre_ordem (t_abb *);
void exibe_ordem_desc(t_abb *);
int altura_arvore(t_abb *);
int maior_num(t_abb *);
int conta_nos (t_abb *);
int conta_nao_folha(t_abb *);
int acha_impar(t_abb *);
int acha_maior(t_abb *);
int compara (t_abb *, t_abb *);