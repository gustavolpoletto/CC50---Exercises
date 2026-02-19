#include <stdio.h>
#include <cs50.h>

int main (void)
{
int l = get_int ("Linhas:");
int c = get_int ("Colunas:");
    {
     for (int n=0; n < l; n++)

        {
            for (int a=0; a<c; a++)
            {
                printf("#");
            }
            printf ("\n");
        }
        printf("\n");
    }
}
