#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc , string argv[])
{
    if (argc != 2)
    {
        printf ("./caeser key\n");
        return 1;
    }

    for(int i=0, n = strlen(argv[1]); i < n ; i++)
        {
            if (isalpha (argv[1][i]))
            {
                printf("./caeser key");
                return 1;
            }

        }

    int key = atoi(argv[1]);

    string frase = get_string("Frase:");

    for(int i=0, n = strlen(frase); i < n ; i++)
    {
        if (isupper(frase[i]))
        {
            frase[i] = (frase[i] - 'A' + key)%26 + 'A';
        }
        else if (islower(frase[i]))
        {
            frase[i] = (frase[i] - 'a' + key)%26 + 'a';
        }
        else
        {
            frase[i] = frase[i];
        }
    }

    printf("ciphertext: %s\n", frase);
    return 0;
}
