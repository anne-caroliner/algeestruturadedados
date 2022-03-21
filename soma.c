/*Implemente um programa que receba dois números inteiros. A função deverá retornar a soma dos números.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int soma (int a, int b)
{
    return a+b;
}
int main(void) 
{
  int a,b;
    scanf("%d %d", &a, &b);
    printf("%d", soma(a,b));
    
}
