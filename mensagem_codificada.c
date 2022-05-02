/* implemente uma função que receba uma string (alfabeto) e um vetor de números inteiros (mensagem codificada) alocado dinamicamente. A função deverá retornar uma string resultante da decodificação da mensagem utilizando o alfabeto.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *descodifica(char *msg1, int *nums, int tamanho)
{
    char *frase = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        frase[i] = msg1[nums[i] - 1];
    }
    return frase;
}

int main(void)
{
    char str[255], *msg;
    int *codigo, aux, tamvet = 0;
    codigo = (int *)malloc(100 * sizeof(int));
    scanf("%s", str);
    for (int i = 0; aux != -1; i++)
    {
        scanf("%d", &aux);

        codigo[i] = aux;
        tamvet++;
    }
    msg = descodifica(str, codigo, tamvet - 1);

    printf("%s", msg);
}
