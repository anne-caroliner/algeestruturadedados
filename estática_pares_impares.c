/*Implemente uma função que receba três listas estáticas (l1, l2, l3), sendo as duas últimas listas vazias. A função deverá colocar os itens pares da lista l1 na l2, e os ímpares, na l3.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int item[MAX_SIZE];
    int tam;
} Lista;


Lista* criar_lista()
{
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->tam = 0;
    return l;
}

int lista_vazia(Lista *l)
{
    return (l == NULL) || (l->tam == 0);
}

int lista_cheia(Lista *l)
{
    return (l != NULL) && (l->tam == MAX_SIZE);
}

int buscar(Lista *l, int chave)
{
    int i;
    if (!lista_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }
    return -1;
}

int inserir(Lista *l, int chave)
{
    if (!lista_cheia(l))
    {
        l->item[l->tam] = chave;
        l->tam++;
        return 1;
    }
    return 0;
}

int remover(Lista *l, int chave)
{
    int i, p = buscar(l, chave);
    if (p > -1)
    {
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];
        l->tam--;

        return 1;
    }

    return 0;
}

void imprimir_lista(Lista *l)
{
    int i;

    if (!lista_vazia(l))
    {
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
    else
        printf("-1\n");
}

int liberar_lista(Lista *l)
{
    if (l != NULL)
    {
        free(l);

        return 1;
    }

    return 0;
}
void separa(Lista *num1, Lista *par, Lista *impar)
{

    for(int i=0; i < num1->tam; i++)
    {
        if((num1->item[i]%2)==0 || num1->item[i] ==0 )
            inserir(par, num1->item[i]);
        else
            inserir(impar, num1->item[i]);
    }
}
int main(void)
{
    int num;
    Lista *numeros, *impares, *pares;
    numeros=criar_lista();
    impares=criar_lista();
    pares=criar_lista();
    for(int i=0; num != -1; i++)
    {
        scanf("%d", &num);
        if(num!= -1)
            inserir(numeros, num);
    }
    separa(numeros,pares,impares);
    printf("par: ");
    imprimir_lista(pares);
    printf("impar: ");
    imprimir_lista(impares);
    liberar_lista(numeros);
    liberar_lista(impares);
    liberar_lista(pares);
}
