/*Implemente uma função que receba uma string que represente uma expressão matemática na notação posfixa. A função deverá retornar o resultado da expressão.*/
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

void sinal(char oper, Pilha *x){
    int aux;
    switch (oper)   {
    case '+':
        empilhar(x,(desempilhar(x)+desempilhar(x)));
        break;
    case '-':
        aux= desempilhar(x);
        empilhar(x,(desempilhar(x)-aux));
        break;
    case '/':
        aux=desempilhar(x);
        empilhar(x,(desempilhar(x)/aux));
        break;
    case '*':
        empilhar(x,(desempilhar(x)*desempilhar(x)));
        break;
    }
}


int sol_poxfix(char str[])
{
    Pilha *pAux;
    int ax;
    pAux=criar_pilha();
    for(int i=0; str[i]!= '\0'; i++)
    {
        if(((int)str[i] - '0')>= 0 && ((int)str[i]-'0')<=9){
            empilhar(pAux,((int)str[i]-'0'));
        }
        else
            sinal(str[i], pAux);
    }
    ax=desempilhar(pAux);
    liberar_pilha(pAux);
    return ax;
}

int main(void)
{
    char expr[TAM_MAX];
    scanf("%s", expr);
    printf("%d",sol_poxfix(expr));
}
