/*Utilizando uma pilha estática, escreva uma função que receba um número inteiro positivo no formato decimal e o converta para o formato binário. A função deverá retornar a pilha com os dígitos do número binário.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100


typedef struct
{
    int item[TAM_MAX];
    int topo;
} Pilha;

Pilha* criar_pilha()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}
int pilha_cheia(Pilha *p)
{
    if (p == NULL)
        return -1;
    else if (p->topo == (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

int pilha_vazia(Pilha *p)
{
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}
int empilhar(Pilha *p, int item)
{
    if (p == NULL)
        p = criar_pilha();
    if (!pilha_cheia(p))
    {
        p->topo++;
        p->item[p->topo] = item;

        return 1;
    }
    return 0;
}

int desempilhar (Pilha *p)
{
    int item = INT_MIN;

    if (!pilha_vazia(p))
    {
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

void imprimir_pilha(Pilha *p)
{
    Pilha aux = *p;
    int item;
    while (!pilha_vazia(&aux))
    {
        item = desempilhar(&aux);

        printf("%d", item);
    }
}

void liberar_pilha(Pilha *p)
{
    if (p != NULL)
        free(p);
}
int obter_posicao_topo(Pilha *p)
{
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

Pilha *converte(Pilha *numero,int z)
{
    for(int i=0; z>=1; i++)
    {
        empilhar(numero, (z%2));
        z=z/2;
    }
    return numero;
}


int main(void)
{
    int y;
    Pilha *binario;
    scanf("%d", &y);
    binario = criar_pilha();
    converte(binario, y);
    imprimir_pilha(binario);
    liberar_pilha(binario);
}

