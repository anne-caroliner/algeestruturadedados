/* Implemente uma função que calcule o produto entre dois números utilizando recursão.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int multiplica_rec(int a, int b){
    if(b==0 || a==0)
        return 0;
    else if(b==1)
        return a;
    else
        return a + multiplica_rec(a,b-1);
}

int main(void) {
    int x,y,z;
    scanf("%d %d", &x, &y);
    z=multiplica_rec(x,y);
    printf("%d", z);
}
