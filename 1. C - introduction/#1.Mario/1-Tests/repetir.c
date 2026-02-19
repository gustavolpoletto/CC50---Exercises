#include <stdio.h>
#include <cs50.h>

int main (void)
{
int i = get_int ("repetições:");
    {
        for (int n=0; n < i; n++)
        {
            printf("#");
        }
        printf ("\n");
    }
}
