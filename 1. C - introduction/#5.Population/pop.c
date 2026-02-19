#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int f;
    int n;
    int a = 0;

    do{
        n = get_int("População Inicial: ");
    }
    while (n < 1);

    do{
       f = get_int("População Final: ");
    }
    while (f < n);

    do{
        n = n + (n / 3) - (n / 4);
        a++;
    }
    while (n < f);
    printf("Foram necessários %i anos\n", a);
}
