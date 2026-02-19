#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card = get_long("N° Cartão: ");

    int a = card % 10;
    int b = card % 100 / 10 * 2;
    int b1 = b / 10;
    int b2 = b % 10;
    int c = card % 1000 / 100;
    int d = card % 10000 / 1000 * 2;
    int d1 = d / 10;
    int d2 = d % 10;
    int e = card % 100000 / 10000;
    int f = card % 1000000 / 100000 * 2;
    int f1 = f / 10;
    int f2 = f % 10;
    int g = card % 10000000 / 1000000;
    int h = card % 100000000 / 10000000 * 2;
    int h1 = h / 10;
    int h2 = h % 10;
    int i = card % 1000000000 / 100000000;
    int j = card % 10000000000 / 1000000000 * 2;
    int j1 = j / 10;
    int j2 = j % 10;
    int k = card % 100000000000 / 10000000000;
    int l = card % 1000000000000 / 100000000000 * 2;
    int l1 = l / 10;
    int l2 = l % 10;
    int m = card % 10000000000000 / 1000000000000;
    int n = card % 100000000000000 / 10000000000000 * 2;
    int n1 = n / 10;
    int n2 = n % 10;
    int o = card % 1000000000000000 / 100000000000000;
    int p = card % 10000000000000000 / 1000000000000000 * 2;
    int p1 = p / 10;
    int p2 = p % 10;

    int w = a + b1 + b2 + c + d1 + d2 + e + f1 + f2 + g + h1 + h2 + i + j1 + j2 + k + l1 + l2 + m +
            n1 + n2 + o + p1 + p2;

        if ( (w % 10 == 0 && o==0 && p/2 == 3 && m/2 ==4 )|| (w % 10 == 0 && o==0 && o == 3 && n/2 ==7))
          {  printf ("American Express \n");}

        else if ( (w % 10 == 0 && p/2==5 && o == 1)|| (w % 10 == 0 && p/2==5 && o==2) || (w % 10 == 0 && p/2==5 && o==3) || (w % 10 == 0 && p/2==5 && o==4) || (w % 10 == 0 && p/2==5 && o==5) )
            {printf ("Master Card \n");}

        else if ( (w % 10 == 0 && p/2==4) ||(w % 10 == 0 && p==0 && o==0 && n==0 && m==4))
            {printf ("Visa \n");}

        else
            printf (" Cartão Inválido \n");

}
