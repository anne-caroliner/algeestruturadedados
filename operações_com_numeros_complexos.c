/*Implemente uma função que receba um ponteiro do tipo complexo e duas variáveis estáticas do tipo float que represente as partes real e imaginária de um número complexo. A partir das varáveis do tipo float, os campos das estrutura devem ser atualizados.
Em seguida, imprima os campos do "complexo" no seguinte formato: real sinal img i.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float real, img, mod;
}complexo;

void atualizar_complexo(complexo *c, float real, float img){
    c->real=real;
    c->img=img;
    c->mod=sqrt(real * real + img * img);
}

int main(void) {
    complexo ponteiro;
    float real, img;
    scanf("%f %f", &real, &img);
    atualizar_complexo(&ponteiro,real,img);
    printf("%.1f",ponteiro.real);
    if(ponteiro.img>=0)
        printf("+");
    printf("%.1fi", ponteiro.img);
    printf("\n%.1f", ponteiro.mod);
}
