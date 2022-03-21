/*Crie uma struct para representar um número racional, ou seja, nessa estrutura deve haver os seguintes campos: numerador e denominador.

Em seguida, crie uma função que receba dois números racionais. A função deverá retornar um outro número racional resultante da divisão dos números fornecidos como entrada.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num, den;    
}racionais;

racionais result(racionais a, racionais b){
    racionais resto;
    resto.num=a.num*b.den;
    resto.den=a.den*b.num;
    return resto;
}
int main(void){
    racionais a;
    racionais resto;
    scanf("%d %d", &a.num, &a.den);
    racionais b;
    scanf("%d %d", &b.num, &b.den);
    resto=result(a,b);
    printf("%d %d", resto.num, resto.den);
        
    return 0;
}
