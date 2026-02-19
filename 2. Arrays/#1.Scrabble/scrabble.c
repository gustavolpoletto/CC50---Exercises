#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int compute_score(string word);

int main(void)
{
    // Solicitar ao usuário duas palavras
        string a = get_string ("Palavra 1: ");
        string b = get_string ("Palavra 2: ");

    // Deixar tudo Maiúsculo

    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] =  a[i] - 32;
        }
        else
        {
            a[i]= a[i];
        }
    }

    for (int t = 0, m = strlen(b); t < m; t++)
    {
        if (b[t] >= 'a' && b[t] <= 'z')
        {
           b[t] = b[t] - 32;
        }
        else
        {
            b[t] = b[t];
        }
    }
    printf("%s, %s\n", a, b);
    // Calcular os pontos de cada palavra
    int pontos1 = compute_score(a);
    printf ("%i\n", pontos1);
    int pontos2 = compute_score(b);
    printf ("%i\n", pontos2);

    // Imprimir o vencedor
    if (pontos1 > pontos2)
    {
        printf ("Jogador 1 venceu\n");
    }
    else if (pontos1 < pontos2)
    {
        printf ("Jogador 2 venceu\n");
    }
    else
    {
        printf ("Empate\n");
    }
}

int compute_score(string word)
{
    // Computa e devolve os pontos de cada palavra
    int total = 0 ;
    for (int x = 0, z = strlen(word); x < z; x++)
    {
        int p = POINTS[word[x] - 'A'];
        total = total + p;

    }
    return total;
}


