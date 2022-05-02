/*mplemente uma função que receba duas filas compostas por números naturais. A função deverá intercalar as duas filas. Em cada intercalação, o maior elemento deve ser enfileirado primeiro.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100

typedef struct
{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
} Fila;

Fila* criar_fila()
{
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f)
{

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}

int fila_vazia(Fila *f)
{
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}

int enfileirar(Fila *f, int chave)
{
    if (f == NULL)
        f = criar_fila();
    if (!fila_cheia(f))
    {

        if (f->ini < 0)
            f->ini = 0;


        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0;
}

int desenfileirar(Fila *f)
{
    int item = INT_MIN;

    if (!fila_vazia(f))
    {
        item = f->item[f->ini];
        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0)
        {
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}

void imprimir_fila(Fila *f)
{
    Fila aux = *f;
    int item;
    while (!fila_vazia(&aux))
    {
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

void liberar_fila(Fila *f)
{
    if (f != NULL)
        free(f);
}
Fila *intercala(Fila *f1, Fila *f2)
{
    Fila *aux;
    aux=criar_fila();
    {
        for(int i=0; !fila_vazia(f1) && !fila_vazia(f2); i++)
        {
            if(!fila_vazia(f1) && !fila_vazia(f2))
            {
                if(f1->item[f1->ini] >= f2->item[f2->ini])
                {
                    enfileirar(aux, desenfileirar(f1));
                    enfileirar(aux, desenfileirar(f2));
                }
                else
                {
                    enfileirar(aux, desenfileirar(f2));
                    enfileirar(aux, desenfileirar(f1));
                }
               
                if(fila_vazia(f1))
                {
                    for(int j=0; !fila_vazia(f2); j++)
                        enfileirar(aux, desenfileirar(f2));
                }
                else if (fila_vazia(f2))
                {
                    for(int j=0; !fila_vazia(f1); j++)
                        enfileirar(aux, desenfileirar(f1));
                }

            }
        }
    }
    return aux;
}

int main(void)
{
    Fila *f1,*f2,*f3;
    int z;
    f1=criar_fila();
    f2=criar_fila();
    f3=criar_fila();

    for(int i=0; z != -1; i++)
    {
        scanf("%d", &z);
        if(z != -1)
        {
            enfileirar(f1, z);
        }
    }
    z=0;


    for(int i=0; z != -1; i++)
    {
        scanf("%d", &z);
        if(z != -1)
        {
            enfileirar(f2, z);
        }
    }
    f3=intercala(f1,f2);
    imprimir_fila(f3);
    liberar_fila(f1);
    liberar_fila(f2);
    liberar_fila(f3);
}
