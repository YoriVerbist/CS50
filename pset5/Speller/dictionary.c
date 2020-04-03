// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Keep track of the total numbers in the dictionary
unsigned long words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int place = hash(word);
    node *tmp = table[place];

    // Check if there are entries in the linked list
    if (tmp->next == NULL)
    {
        return false;
    }
    // As long there are nodes in the linked list keep going
    while (tmp->next != NULL)
    {
        tmp = tmp->next; // Update the pointer to the next element in the linked list
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // From: https://github.com/curiouskiwi/cs50x-help/blob/master/hash.c

    uint32_t hash = 0;
    while (*word)
    {
        hash = (*word | 0x20);
        word++;
    }

    // return a value between 0 and 65535
    return (int)((hash >> 16) ^ (hash & 0xffff));
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
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
