// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r"); // Open the dictionary file
    if (file == NULL)
    {
        return false;
    }
    
    char *word = malloc(LENGTH * sizeof(char)); // Make memory free for the max length of a word
    // Read strings from file
    while (fscanf(file, "%s", word) != EOF)
    {
        fscanf(file, "%s", word);

        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        // Hash word
        int place = hash(n->word);

        //Insert node into hash table
        if (table[place] == NULL)
        {
            return false;
        }
        else if (table[place]->next == NULL)
        {
            table[place] = n;
        }
        else
        {
            n->next = table[place]->next;
            table[place]->next = n;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
