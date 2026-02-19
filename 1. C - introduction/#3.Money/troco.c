#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    int t = 0;

   do
   {
    n = get_float ("troco: ");
   }
   while (n<0);

   int p = round(n*100);

    while (p>=25)
        {
                printf("uma moeda de 25 \n");
                p = p-25;
                t++;
        }
     while (p>=10)
            {
                p = p-10;
                printf("uma moeda de 10 \n");
                t++;
            }
     while (p>=5)

            {
                p = p-5;
                printf("uma moeda de 5 \n");
                t++;
            }


    while (p>=1)

            {
                p = p-1;
                printf("uma moeda de 1 \n");
                t++;
            }

    printf("total de moedas: %i \n", t);
}
