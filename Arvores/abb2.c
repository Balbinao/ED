#include "abb.h"

// Inicializa a árvore binária de busca
void inicializa_abb(t_abb *a){
    a->raiz = NULL;
}

// Verifica se a árvore está vazia
int esta_vazia(t_abb *a) {
    return a->raiz == NULL;
}

// Função auxiliar recursiva para inserir um nó na árvore
void insere_rec(t_no *novo, t_no *atual){
    if(novo->info <= atual->info){ // Se o novo nó é menor ou igual ao nó atual, vai para a esquerda
        if(atual->esq == NULL){ // Se o gancho da esquerda está livre, insere o novo nó aqui
            atual->esq = novo;
        } else { // Caso contrário, continua procurando na subárvore esquerda
            insere_rec(novo, atual->esq);
        }
    } else { // Se o novo nó é maior, vai para a direita
        if(atual->dir == NULL){ // Se o gancho da direita está livre, insere o novo nó aqui
            atual->dir = novo;
        } else { // Caso contrário, continua procurando na subárvore direita
            insere_rec(novo, atual->dir);
        }
    }
}

// Insere um novo elemento na árvore
void insere(int i, t_abb *a){
    t_no *novo = constroi_no(i); // Cria um novo nó com o valor i
    if(esta_vazia(a)){ // Se a árvore está vazia, o novo nó se torna a raiz
        a->raiz = novo;
    } else { // Caso contrário, insere recursivamente na árvore
        insere_rec(novo, a->raiz);
    }
}

// Exibe os elementos da árvore em ordem decrescente recursivamente
void exibe_ordem_desc_rec(t_no *atual){
    if(atual != NULL){
        exibe_ordem_desc_rec(atual->dir); // Visita a subárvore direita
        mostra_no(atual); // Mostra o nó atual
        exibe_ordem_desc_rec(atual->esq); // Visita a subárvore esquerda
    }
}

// Exibe os elementos da árvore em ordem decrescente
void exibe_ordem_desc(t_abb *a){
    if(esta_vazia(a)){
        printf("Árvore vazia.");
    } else {
        exibe_ordem_desc_rec(a->raiz);
    }
}

// Exibe os elementos da árvore em ordem crescente recursivamente
void exibe_em_ordem_rec(t_no *atual){
    if(atual != NULL){
        exibe_em_ordem_rec(atual->esq); // Visita a subárvore esquerda
        mostra_no(atual); // Mostra o nó atual
        exibe_em_ordem_rec(atual->dir); // Visita a subárvore direita
    }
}

// Exibe os elementos da árvore em ordem crescente
void exibe_em_ordem(t_abb *a){
    if(esta_vazia(a)){
        printf("Árvore vazia.");
    } else {
        exibe_em_ordem_rec(a->raiz);
    }
}

// Exibe os elementos da árvore em pré-ordem recursivamente
void exibe_em_pre_ordem_rec(t_no *atual){
    if(atual != NULL){
        mostra_no(atual); // Mostra o nó atual
        exibe_em_pre_ordem_rec(atual->esq); // Visita a subárvore esquerda
        exibe_em_pre_ordem_rec(atual->dir); // Visita a subárvore direita
    }
}

// Exibe os elementos da árvore em pré-ordem
void exibe_em_pre_ordem(t_abb *a){
    if(esta_vazia(a)){
        printf("Árvore vazia.");
    } else {
        exibe_em_pre_ordem_rec(a->raiz);
    }
}

// Calcula a altura da árvore recursivamente
int altura_arvore_rec(t_no *atual){
    int nivel_esq = 0, nivel_dir = 0;

    if(atual == NULL){ // Se o nó atual é nulo, retorna -1
        return -1;
    }

    nivel_esq = altura_arvore_rec(atual->esq); // Calcula a altura da subárvore esquerda
    nivel_dir = altura_arvore_rec(atual->dir); // Calcula a altura da subárvore direita

    // Retorna o maior nível entre esquerda e direita mais um (altura do nó atual)
    return (nivel_esq > nivel_dir ? nivel_esq : nivel_dir) + 1;
}

// Calcula a altura da árvore
int altura_arvore(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, altura é zero
    }
    return altura_arvore_rec(a->raiz); // Caso contrário, calcula recursivamente a altura
}

// Encontra o maior valor na árvore recursivamente
int acha_maior_rec(t_no *atual){
    if(atual->dir == NULL){ // Se não há filho direito, o próprio nó é o maior
        return atual->info;
    }
    return acha_maior_rec(atual->dir); // Caso contrário, continua procurando no filho direito
}

// Encontra o maior valor na árvore
int acha_maior(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return acha_maior_rec(a->raiz); // Caso contrário, encontra o maior valor recursivamente
}

// Conta o número de nós na árvore recursivamente
int conta_rec(t_no *atual){
    int cont_esq = 0, cont_dir = 0;

    if(atual == NULL){ // Se o nó atual é nulo, retorna 0
        return 0;
    }

    if(atual->esq != NULL){ // Se há filho esquerdo, conta os nós na subárvore esquerda
        cont_esq = conta_rec(atual->esq);
    }

    if(atual->dir != NULL){ // Se há filho direito, conta os nós na subárvore direita
        cont_dir = conta_rec(atual->dir);
    }

    // Retorna a soma de nós da subárvore esquerda, direita e o nó atual
    return cont_esq + cont_dir + 1;
}

// Conta o número de nós na árvore
int conta_nos(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return conta_rec(a->raiz); // Caso contrário, conta os nós recursivamente
}

// Conta o número de nós não folha na árvore recursivamente
int conta_nao_folha_rec(t_no *atual){
    int cont_esq = 0, cont_dir = 0;

    if(atual == NULL || (atual->esq == NULL && atual->dir == NULL)){
        return 0; // Se o nó atual é nulo ou folha, retorna 0
    }

    if(atual->esq != NULL){ // Se há filho esquerdo, conta nós não folha na subárvore esquerda
        cont_esq = conta_nao_folha_rec(atual->esq);
    }

    if(atual->dir != NULL){ // Se há filho direito, conta nós não folha na subárvore direita
        cont_dir = conta_nao_folha_rec(atual->dir);
    }

    // Retorna a soma de nós não folha na subárvore esquerda, direita e o nó atual
    return cont_esq + cont_dir + 1;
}

// Conta o número de nós não folha na árvore
int conta_nao_folha(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return conta_nao_folha_rec(a->raiz); // Caso contrário, conta nós não folha recursivamente
}

// Encontra o primeiro número ímpar na árvore recursivamente
int acha_impar_rec(t_no *atual){
    if(atual == NULL){
        return 0; // Se o nó atual é nulo, retorna 0
    }
    if(atual->info % 2 != 0){
        return atual->info; // Se o valor do nó é ímpar, retorna o valor
    }
    // Caso contrário, continua procurando nos filhos esquerdo e direito
    int impar = acha_impar_rec(atual->esq);
    if(impar % 2 != 0){
        return impar;
    }
    return acha_impar_rec(atual->dir);
}

// Encontra o primeiro número ímpar na árvore
int acha_impar(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return acha_impar_rec(a->raiz); // Caso contrário, encontra o primeiro ímpar recursivamente
}

// Compara duas árvores recursivamente
int compara_rec(t_no *at1, t_no *at2){
    if(at1 == NULL && at2 == NULL){
        return 1; // Se ambos os nós são nulos, são iguais
    }
    if(at1 == NULL || at2 == NULL){
        return 0; // Se apenas um dos nós é nulo, são diferentes
    }
    // Compara os filhos esquerdo e direito de cada nó recursivamente
    int comp_esq = compara_rec(at1->esq, at2->esq);
    int comp_dir = compara_rec(at1->dir, at2->dir);

    // Retorna verdadeiro se ambos os filhos esquerdos e direitos forem iguais
    return (comp_esq == 1 && comp_dir == 1) ? 1 : 0;
}

// Compara duas árvores
int compara(t_abb *a1, t_abb *a2){
    if(esta_vazia(a1) && esta_vazia(a2)){
        return 1; // Se ambas as árvores estão vazias, são iguais
    }
    if(esta_vazia(a1) || esta_vazia(a2)){
        return 0; // Se apenas uma das árvores está vazia, são diferentes
    }
    return compara_rec(a1->raiz, a2->raiz); // Caso contrário, compara as raízes das árvores recursivamente
}

// Encontra o maior valor na árvore recursivamente
int acha_maior_rec(t_no *atual){
    if(atual->dir == NULL){ // Se não há filho direito, o próprio nó é o maior
        return atual->info;
    }
    return acha_maior_rec(atual->dir); // Caso contrário, continua procurando no filho direito
}

// Encontra o maior valor na árvore
int acha_maior(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return acha_maior_rec(a->raiz); // Caso contrário, encontra o maior valor recursivamente
}

// Função auxiliar para contar o número de nós não folha na árvore recursivamente
int conta_nao_folha_rec(t_no *atual){
    int cont_esq = 0, cont_dir = 0;

    if(atual == NULL || (atual->esq == NULL && atual->dir == NULL)){
        return 0; // Se o nó atual é nulo ou folha, retorna 0
    }

    if(atual->esq != NULL){ // Se há filho esquerdo, conta nós não folha na subárvore esquerda
        cont_esq = conta_nao_folha_rec(atual->esq);
    }

    if(atual->dir != NULL){ // Se há filho direito, conta nós não folha na subárvore direita
        cont_dir = conta_nao_folha_rec(atual->dir);
    }

    // Retorna a soma de nós não folha na subárvore esquerda, direita e o nó atual
    return cont_esq + cont_dir + 1;
}

// Conta o número de nós não folha na árvore
int conta_nao_folha(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return conta_nao_folha_rec(a->raiz); // Caso contrário, conta nós não folha recursivamente
}

// Encontra o primeiro número ímpar na árvore recursivamente
int acha_impar_rec(t_no *atual){
    if(atual == NULL){
        return 0; // Se o nó atual é nulo, retorna 0
    }
    if(atual->info % 2 != 0){
        return atual->info; // Se o valor do nó é ímpar, retorna o valor
    }
    // Caso contrário, continua procurando nos filhos esquerdo e direito
    int impar = acha_impar_rec(atual->esq);
    if(impar % 2 != 0){
        return impar;
    }
    return acha_impar_rec(atual->dir);
}

// Encontra o primeiro número ímpar na árvore
int acha_impar(t_abb *a){
    if(esta_vazia(a)){
        return 0; // Se a árvore está vazia, retorna 0
    }
    return acha_impar_rec(a->raiz); // Caso contrário, encontra o primeiro ímpar recursivamente
}

// Função auxiliar para comparar duas árvores recursivamente
int compara_rec(t_no *at1, t_no *at2){
    if(at1 == NULL && at2 == NULL){
        return 1; // Se ambos os nós são nulos, são iguais
    }
    if(at1 == NULL || at2 == NULL){
        return 0; // Se apenas um dos nós é nulo, são diferentes
    }
    // Compara os filhos esquerdo e direito de cada nó recursivamente
    int comp_esq = compara_rec(at1->esq, at2->esq);
    int comp_dir = compara_rec(at1->dir, at2->dir);

    // Retorna verdadeiro se ambos os filhos esquerdos e direitos forem iguais
    return (comp_esq == 1 && comp_dir == 1) ? 1 : 0;
}

// Compara duas árvores
int compara(t_abb *a1, t_abb *a2){
    if(esta_vazia(a1) && esta_vazia(a2)){
        return 1; // Se ambas as árvores estão vazias, são iguais
    }
    if(esta_vazia(a1) || esta_vazia(a2)){
        return 0; // Se apenas uma das árvores está vazia, são diferentes
    }
    return compara_rec(a1->raiz, a2->raiz); // Caso contrário, compara as raízes das árvores recursivamente
}
