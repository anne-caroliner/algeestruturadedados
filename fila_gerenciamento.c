/*Implemente uma função que receba uma fila estática e um número inteiro como parâmetros e faça o gerenciamento.*/
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

int organiza(Fila *x,int num)
{
    int car, i = 0,aux=0;
    int tam_inicial;
    tam_inicial = x->tam;

    while(i != 1){
        car = desenfileirar(x);
        if(car != num){
            aux++;
            enfileirar(x, car);
            if(aux == tam_inicial) 
        break;
        }
        else if(car == num){
            i = 1;
        }
    }

    imprimir_fila(x);

    printf("%d\n", aux);
    
    if(i == 1){
        printf("sucesso");
    }
    else{
        printf("falha");
    }
    return 0;
}

int main(void)
{  
    Fila *estacionamento;
    estacionamento=criar_fila();
    int z;
    for(int i=0; z != -1; i++)
    {
        scanf("%d", &z);
        if(z != -1)
        {
            enfileirar(estacionamento, z);
        }
    }
    scanf("%d", &z);
    organiza(estacionamento,z);
}
