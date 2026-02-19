// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int i = hash(word);
    node *tmp = table[i];

    while(tmp != NULL)
    {
        if (strcasecmp (word, tmp -> word) == 0)
        {
            return true;
        }
    tmp = tmp -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
     return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0 ; i < N ; i++)
    {
        table[i] = NULL;
    }
    char word[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    while(fscanf(file , "%s" , word) != EOF)
    {

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }
        int index = hash(word);
        strcpy(n -> word , word);
        n -> next = table[index];
        table[index] = n;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;

    for (int i = 0 ; i < N ; i++)
    {
        node *n = table[i];
        while(n != NULL)
        {
            count++;
            n = n -> next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for ( int i = 0 ; i < N ; i++)
    {
        node *n = table[i];

        while (n!= NULL)
        {
            n = table[i] -> next;
            free(table[i]);
            table[i] = n;
        }
    }
    return true;
}
