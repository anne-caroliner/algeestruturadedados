/*Implemente uma função recursiva que receba dois números naturais: a e n. A função deverá calcular a potência de a em relação à n (a^n, ou "a" elevada à "n") multiplicações sucessivas.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potencia_rec(int a, int b){
    if(b==0)
        return 1;
    else if(b==1)
        return a*b;
    else
        return a*potencia_rec(a,b-1);
}

int main(void) {
    int x,y;
    scanf("%d %d", &x, &y);
    x=potencia_rec(x,y);
    printf("%d", x);
}
