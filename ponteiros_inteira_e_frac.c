/*Implemente uma função que receba três variáveis: duas do tipo float e uma do tipo int. A função deverá retornar a parte inteira (int) e a fracionária (float) de um número do real.*/

#include <stdio.h>
#include <math.h>
#include <string.h>

void frac(float n, int * in, float * fr)
{
    *in=(int)n;
    *fr=n-*in;
}
int main ()
{
    int n, in;
    float fr, aux;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &aux);
        frac(aux, &in, &fr);
        printf("N=%.3f I=%d F=%.3f\n", aux, in, fr);
    }
}
