#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pegar número de 1 a 8
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1 || n > 8);

    // Imprimir escada
    for (int i = 1; i <= n; i++)
    {
        for (int a = 0; a < i; a++)
        {
            for (a = n; a > i; a--)
            {
                printf(" ");
            }
            for (a = 0; a < i; a++)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
