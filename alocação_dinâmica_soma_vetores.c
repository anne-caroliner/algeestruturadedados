/*Implemente uma função que receba dois vetores de números inteiros. A função deverá retornar um vetor resultante da soma dos vetores entrada.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* soma(int *v1, int n1, int *v2, int n2)
{

    int i, maior, menor;
    int *v3 = NULL;
    
    if(n1 > n2)
    {
        maior = n1;
        menor = n2;
    }else
    {
        maior = n2;
        menor = n1;
    }
    
    v3 = malloc(sizeof(int)* maior);
    
    for (i = 0; i < menor; i++)
        v3[i] = v1[i] +v2[i];
    
    for (i = n2; i < n1; i++)
        v3[i] = v1[i];
    
    for (i=n1; i < n2; i++)
        v3[i] = v2[i];
    
    return v3;
    
}
int main(void)
{
    int *vetor1, *vetor2, *vetor3, maiorvet, n1, n2, auxiliar;

    scanf ("%d", &n1);
    vetor1=malloc(n1 * sizeof(int));
    for (int j = 0; j < n1; j++)
    {
        scanf("%d", &auxiliar);
        vetor1[j] = auxiliar;
    }
    scanf ("%d", &n2);
    vetor2=malloc(n2 * sizeof(int));
    for (int j = 0; j < n2; j++)
    {
        scanf("%d", &auxiliar);
        vetor2[j] = auxiliar;
    }
    vetor3=soma(vetor1, n1, vetor2, n2);
    if(n1>n2)
        maiorvet=n1;
    else
        maiorvet=n2;
    
    for (int i = 0; i < maiorvet; i++)
    {
        printf("%d ", vetor3[i]);
    }

}
