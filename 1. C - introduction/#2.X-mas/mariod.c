#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Pegar número de 1 a 8
    int n;
    do
    {
        n = get_int("Número: ");
    }
    while (n < 4);

    // Imprimir pirâmide
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
            for (a = 1; a < i; a++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    for (int t = 2; t < n; t++)
    {
        printf(" ");
    }
    printf("| |");
     printf("\n");
}
