#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int main (void)
{
    int letras = 0;
    int palavras = 1;
    int frases = 0;

    string texto = get_string("Texto:");
    for (int i = 0, n= strlen(texto); i < n; i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            letras++;
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            letras++;
        }
        else if (texto[i] == ' ')
        {
            palavras++;
        }
        else if (texto[i] == '.' || texto[i] == '?' || texto[i] == '!')
        {
            frases++;
        }
    }

    // L número médio de letras por 100 palavras
    float l = letras * 100.0 / palavras;

    //S o número médio de frases por 100 palavras
    float s = frases * 100 / palavras;

    float indice = 0.0588 * l - 0.296 * s - 15.8;
    printf ("%f\n", indice);
    int score = round(indice);
    printf ("%i\n", score);
    if (score <= 1)
    {
        printf("Nível menor ou igual a 1\n");
    }

    else if (score >= 16)
    {
        printf("Nível maior que 16\n");
    }
    else
    {
        printf("Nível %i\n", score);
    }

}

