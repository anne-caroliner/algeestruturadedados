/**/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void altera(int *a, int *b, int *c)
{
    *c=abs(*a-*b);
    *b=*b-*c;
    *a=*a+*c;
}
int main(void) 
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    altera(&a, &b, &c);
    printf("A=%d B=%d C=%d", a, b, c);
   
}
