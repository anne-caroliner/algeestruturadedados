/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.

(a) Permita ao usuário entrar com os dados de n alunos. (b) Encontre o aluno com maior nota da primeira prova. (c) Encontre o aluno com maior média geral. (d) Encontre o aluno com menor média geral (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando a média 6 para aprovação.*/


#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    int cod;
    char nome[255];
    float notas[3];
    float media;
} aluno_t;

void calculaMedia(aluno_t aluno[], int n)
{
    float media = 0.0;
    for (int i = 0; i < 3; i++)
    {
        media += aluno[n].notas[i];
    }
    media = media / 3.0;
    aluno[n].media = media;
}

int encontraMaiorMedia(aluno_t aluno[], int n)
{
    int maiorMedia = 0;
    for (int i = 1; i < n; i++)
    {
        if (aluno[maiorMedia].media < aluno[i].media)
        {
            maiorMedia = i;
        }
    }
    return maiorMedia;
}

int encontraMenorMedia(aluno_t aluno[], int n)
{
    int menorMedia = 0;
    for (int i = 1; i < n; i++)
    {
        if (aluno[menorMedia].media > aluno[i].media)
        {
            menorMedia = i;
        }
    }
    return menorMedia;
}

int encontraMaiorP1(aluno_t aluno[], int n)
{
    int maiorP1 = 0;
    for (int i = 1; i < n; i++)
    {
        if ( aluno[maiorP1].notas[0]< aluno[i].notas[0])
        {
            maiorP1 = i;
        }
    }
    return maiorP1;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    aluno_t aluno[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aluno[i].cod);
        scanf("%s", aluno[i].nome);
        scanf("%f %f %f", &aluno[i].notas[0], &aluno[i].notas[1], &aluno[i].notas[2]);
        calculaMedia(aluno, i);
    }

    for (int i = 0; i < n; i++)
    { 
        if (aluno[i].media >= 6.0)
        {
            printf("Aprovado!\n");
        }
        else
        {
            printf("Reprovado!\n");
        }
    }
    printf("O aluno com maior media e: %d %s %.1f", aluno[encontraMaiorMedia(aluno, n)].cod, aluno[encontraMaiorMedia(aluno, n)].nome, aluno[encontraMaiorMedia(aluno, n)].media);
    printf("\nO aluno com menor media e: %d %s %.1f", aluno[encontraMenorMedia(aluno, n)].cod, aluno[encontraMenorMedia(aluno, n)].nome, aluno[encontraMenorMedia(aluno, n)].media);
    printf("\nO aluno com maior P1 e: %d %s %.1f\n", aluno[encontraMaiorP1(aluno, n)].cod, aluno[encontraMaiorP1(aluno, n)].nome, aluno[encontraMaiorP1(aluno, n)].notas[0]);
}
