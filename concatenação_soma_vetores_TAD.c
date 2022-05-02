/*Crie um TAD para processamento de vetores com a seguinte estrutura e operações, onde v é o vetor e n é a quantidade de elementos contidos no vetor.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct
{
    int *v;
    int n;
    int q;
} Vetor;

Vetor *inicia(int n)
{
    Vetor *vet = malloc(sizeof(Vetor));
    vet->v = malloc(n * sizeof(int));
    vet->n = n;
    vet->q = 0;
    return vet;
}

int insere(Vetor *v, int x)
{
    if (v->q < v->n)
    {
        v->v[v->q] = x;
        v->q++;
        return 1;
    }
    return 0;
}

Vetor *concatena(Vetor *v1, Vetor *v2)
{
    int i;
    Vetor *v3 = inicia(v1->q + v2->q);

    for (i = 0; i < v1->q; i++)
        insere(v3, v1->v[i]);

    for (i = 0; i < v2->q; i++)
        insere(v3, v2->v[i]);

    return v3;
}

Vetor *soma(Vetor *v1, Vetor *v2)
{
    int i;
    Vetor *v3 = inicia(v1->q > v2->q ? v1->q : v2->q);

    for (i = 0; (i < v1->q) && (i < v2->q); i++)
        insere(v3, v1->v[i] + v2->v[i]);

    for (i = v2->q; i < v1->q; i++)
        insere(v3, v1->v[i]);

    for (i = v1->q; i < v2->q; i++)
        insere(v3, v2->v[i]);

    return v3;
}

int main(void)
{
    Vetor *vt1, *vt2, *vt3, *somav;
    int z, aux;
    scanf("%d", &z);
    
    vt1 = inicia(z);
    for (int i = 0; i < z; i++)
    {
        scanf("%d", &aux);
        insere(vt1, aux);
    }
    scanf("%d", &z);
    
    vt2 = inicia(z);
    for (int i = 0; i < z; i++)
    {
        scanf("%d", &aux);
        insere(vt2, aux);
    }

    vt3 = inicia(vt1->q + vt2->q);
    vt3 = concatena(vt1, vt2);

    for (int i = 0; i < vt3->q; i++)
    {
        printf("%d ", vt3->v[i]);
    }
    printf("\n");


    somav = inicia(vt1->q > vt2->q ? vt1->q : vt2->q);
    somav = soma(vt1, vt2);
    for (int i = 0; i < somav->q; i++)
    {
        printf("%d ", somav->v[i]);
    }
}
