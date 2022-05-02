/*Crie um TAD para números reais, onde i é a parte inteira e f é a parte fracionária, que pode ter valores entre 0 e 99, ou seja, o número real possui apenas duas casas decimais.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int i;
    int f;
} Reais;

Reais *criar(int i, int f)
{
    Reais *x = malloc(sizeof(Reais));
    x->i = i;
    x->f = f;

    return x;
}


Reais *soma(Reais *r1, Reais *r2)
{
    int x, y;
    x = r1->i + r2->i;
    if (r1->f + r2->f > 100)
    {
        y = (r1->f + r2->f) - 100;
        x++;
    }
    else
    {
        y = (r1->f + r2->f);
    }
    Reais *sm = criar(x, y);
    return sm;
}


Reais *subtracao(Reais *r1, Reais *r2)
{
    int x, y;
    x = (r1->i - r2->i);

    y = abs(r1->f - r2->f);

    Reais *restante = criar(x, y);
    return restante;
}

int arredondar(Reais *r1)
{
    int ar, x = r1->i;
    if (r1->f >= 50)
    {
        x++;
    }
    return x;
}

void imprimir(Reais *r1)
{
    float numero;
    numero = (float)r1->i + ((float)r1->f / 100);

    printf("%.2f\n", numero);
}
int main(void)
{
    Reais *numero1, *numero2;
    int x, y;

    scanf("%d %d", &x, &y);
    numero1 = criar(x, y);
    scanf("%d %d", &x, &y);
    numero2 = criar(x, y);
    imprimir(numero1);
    imprimir(numero2);
    imprimir(soma(numero1, numero2));
    imprimir(subtracao(numero1, numero2));
    printf("%d %d", arredondar(numero1), arredondar(numero2));
}
