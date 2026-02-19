#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main (int argc, string argv[])
{
    if(argc != 2)
    {
    printf("Código: ./subs key\n");
    return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("A chave deve conter 26 caracteres distintos\n");
    }

    for(int i=0, n = strlen(argv[1]); i < n; i++)
    {
        if(isdigit(argv[1][i]))
        {
            printf("A chave deve conter apenas letras\n");
            return 1;
        }
    }

    for(int i=0, n = strlen(argv[1]); i < n; i++)
    {
        if(islower(argv[1][i]))
        {
            argv[1][i] = argv[1][i] - 32;
        }
    }

    string frase = get_string("Frase: ");

    for(int i=0, n = strlen(frase); i < n; i++)
    {
        if (islower(frase[i]))
        {
            int a = frase[i] - 'a';
            frase[i] = argv[1][a] + 32;
        }
        else if (isupper(frase[i]))
        {
            int a = frase[i] - 'A';
            frase[i] = argv[1][a];
        }
    }
    printf ("%s\n", frase);
    return 0;
}
