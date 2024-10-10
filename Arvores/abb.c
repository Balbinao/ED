#include "abb.h"

void inicializa_abb(t_abb *a){
    a->raiz = NULL;
}

int esta_vazia(t_abb *a) {
    return a->raiz == NULL;
}

void insere_rec (t_no * novo, t_no *atual){
    if(novo->info <=atual->info){ //gancho vai pra esquerda
        if(atual->esq == NULL){ //gancho da esquerda esta livre
            atual->esq = novo;
        }else{ //continua procurando
            insere_rec(novo, atual->esq);
        }

    }else{//Gancho vai pra direita
        if(atual->dir == NULL){//se o gancho da direita esta livre
            atual->dir = novo;
        }else{//continua procurando
            insere_rec(novo, atual->dir);
        }
    }
}

void insere (int i, t_abb *a){
    t_no * novo = constroi_no(i);
    if(esta_vazia(a)){
        a->raiz = novo;
    }else{
        insere_rec(novo, a->raiz);
    }
}

void exibe_ordem_desc_rec(t_no *atual){
    if(atual != NULL){
        exibe_ordem_desc_rec(atual->dir);
        mostra_no(atual);
        exibe_ordem_desc_rec(atual->esq);
    }
}
void exibe_em_ordem_rec(t_no *atual){
    if(atual != NULL){
        exibe_em_ordem_rec(atual->esq);
        mostra_no(atual);
        exibe_em_ordem_rec(atual->dir);
    }
}

//r - esq - dir = pre order
void exibe_em_pre_ordem_rec(t_no *atual){
    if(atual != NULL){
        mostra_no(atual);
        exibe_em_pre_ordem_rec(atual->esq);
        exibe_em_pre_ordem_rec(atual->dir);
    }
}
void exibe_em_ordem(t_abb *a){
    if(esta_vazia(a)){
        printf("Arvore vazia.");
    }else{
        exibe_em_ordem_rec(a->raiz);
    }
}

void exibe_em_pre_ordem (t_abb *a){
    if(esta_vazia(a)){
        printf("Esta vazia");
    }else{
        exibe_em_pre_ordem_rec(a->raiz);
    }
}

void exibe_ordem_desc(t_abb *a){
    if(esta_vazia(a)){
        printf("Esta vazia");
    }else{
        exibe_ordem_desc_rec(a->raiz);
    }
}
int altura_arvore_rec(t_no *atual){
    int nivel_dir = 0, nivel_esq = 0;

    if(atual->esq == NULL && atual->dir == NULL){ //É uma folha
        return 0;
    }if(atual->esq != NULL){
        nivel_esq = altura_arvore_rec(atual->esq);
    }if(atual->dir != NULL){
        nivel_dir = altura_arvore_rec(atual->dir);
    }
    return nivel_dir > nivel_esq ? nivel_dir + 1 : nivel_esq + 1;
}

int altura_arvore(t_abb *a){
    if(esta_vazia(a)){
        return 0;
    }
    return altura_arvore_rec(a->raiz);
    
}
int maior_num(t_abb *a){
    if(esta_vazia(a)){
        return 0;
    }else{
        t_no *atual = a->raiz;
        while(atual->dir != NULL){
            atual = atual->dir;
        }
        return atual->info;
    }
}


int conta_rec(t_no * atual){
    //atual == raiz ex 1
    //raiz cont_dir = 0;
    //raiz cont_esq = 0;
    int cont_dir = 0;
    int cont_esq = 0;
    //raiz tem esq
    if(atual->esq != NULL){
        //raiz cont_esq = 4
        cont_esq = conta_rec(atual->esq);
    }
    //raiz tem dir
    if(atual->dir != NULL){
        //raiz cont_dir = 2
        cont_dir = conta_rec(atual->dir);

    }
    //raiz 4 + 1 + 2 = 7
    return cont_esq + 1 + cont_dir;
}
int conta_nos(t_abb * a){
    //chamou conta_nos
    if (esta_vazia(a)) return 0;
    //não está vazia!
    return conta_rec(a->raiz);
    //chama o metodo conta_rec que retorna ??

}


int conta_nao_rec (t_no * atual){
    int cont_dir = 0;
    int cont_esq = 0;

    if(atual->esq != NULL){

        cont_esq = conta_nao_rec(atual->esq);
    }

    if(atual->dir != NULL){

        cont_dir = conta_nao_rec(atual->dir);

    }
    //SE FOR UMA FOLHA
    //RETORNA 0
    if(atual->dir == NULL && atual->esq == NULL){
        return 0;
    }
    return cont_esq + 1 + cont_dir;
}

int conta_nao_folha(t_abb * a){
    if(esta_vazia(a)) return 0;
    return (conta_nao_rec(a->raiz));
}

int acha_impar_rec(t_no * atual){
    //raiz não é impar
    //Pelé É IMPAR
    if(atual->info % 2 != 0){
        return atual->info; //RETORNA PELÉ (5)
    }
    int impar = 0;
    //impar da raiz = 0
    //raiz tem esquerda
    if(atual->esq != NULL){
        //raiz impar = 5
        impar = acha_impar_rec(atual->esq);
    }
    if(impar % 2 != 0){
        return impar;
    }
    if(atual->dir != NULL){
        impar = acha_impar_rec(atual->dir);
    }
    return impar;
}

int acha_impar(t_abb * a){
    if(esta_vazia(a)) return 0;
    //NÃO ESTÁ VAZIA
    return(acha_impar_rec(a->raiz));
    //COMECA NA RAIZ
}

int acha_maior_rec(t_no * atual){
    int dir;
    int esq = dir = 0;
    if(atual->dir == NULL && atual->esq == NULL){
        return atual->info;
    }
    if(atual->esq != NULL){
        esq = acha_maior_rec(atual->esq);
    }
    if(atual->dir != NULL){
        dir = acha_maior_rec(atual->dir);
    }
    if(dir > esq){
        if(dir > atual->info){
            return dir;
        }
    }
    else{
        if(esq > atual->info){
            return esq;
        }
    }
    return atual->info;

}


int acha_maior(t_abb * a){
    if(esta_vazia(a)) return 0;
    return acha_maior_rec(a->raiz);
}

int compara_rec(t_no *at1, t_no *at2){
    int comp_esq = 0, comp_dir = 0;

    //raiz
    if(at1->esq == NULL && at2->esq == NULL){
        comp_esq = 1;
    } 
    if(at1->dir == NULL && at2->dir == NULL){
        comp_dir = 1;
    } 
    if(at1->esq != NULL && at2->esq != NULL){
        comp_esq = compara_rec(at1->esq, at2->esq);
    }
    if(at1->dir != NULL && at2->dir != NULL){
        comp_dir = compara_rec(at1->dir, at2->dir);
    }
    return (comp_dir == comp_esq && comp_dir == 1)? 1 : 0;
}

int compara(t_abb *a1 , t_abb *a2){
    //a1 não está vazia
    if(esta_vazia(a1)){
        if(esta_vazia(a2)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        //a2 não está vazia
        if(esta_vazia(a2)){
            return 0;
        }
        else{
            //retorna a comparação de a1 e a2
            return compara_rec(a1->raiz, a2->raiz);
        }
    }
}
