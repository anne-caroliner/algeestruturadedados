/*Dada uma função que receba uma lista estática de contatos e uma string. Essa função deverá imprimir os contatos que contêm essa string no nome.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define TAM_MAX 100

typedef struct{
    char item[TAM_MAX][TAM_MAX];
    int tamanho;
}Lista;

Lista* cria_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tamanho = 0;

    return l;
}

int lista_vazia(Lista *l){
    return (l == NULL) || (l->tamanho == 0);
}

int lista_cheia(Lista *l){
    return (l != NULL) && (l->tamanho == TAM_MAX);
}

int busca(Lista *l, char chave[]){
    int i;
    if (!lista_vazia(l)){
        for (i = 0; i < l->tamanho; i++)
                if (strstr(l->item[i],chave)){
                printf("%s\n", l->item[i]);
                }
    }
    return -1;
}

int insere(Lista *l, char chave[]){
    if (!lista_cheia(l)){
        strcpy(l->item[l->tamanho], chave);
        l->tamanho++;
        return 1;
    }
    return 0;
}

int libera_lista(Lista *l){
    if (l != NULL){
        free(l);
        return 1;
    }
    return   0;
}

int main(void){
    int nome;
    char substr[100], aux[100];
    Lista *nomes;

    nomes=cria_lista();

    scanf("%s", substr);
    scanf("%d", &nome);

    for(int i=0; i<nome; i++){
        scanf("%s",aux);
        insere(nomes,aux);
    }
    busca(nomes, substr);
    libera_lista(nomes);
}

