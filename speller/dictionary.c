// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

int flag = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];
    int index;
    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(temp->word, word);
        }

        index = hash(temp->word);
        temp->next = hashtable[index];
        hashtable[index] = temp;

    }

    // Close dictionary
    fclose(file);
    flag = 1;
    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (flag)
    {
        int count = 0;
        for (int i = 0; i <   26; i++)
        {
            node *cursor = hashtable[i];
            while (cursor != NULL)
            {
                count++;
                cursor = cursor->next;
            }
        }
        return count;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = hashtable[hash(word)];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int b = 0;
    for (int i = 0; i < 26; i++)
    {
        node *temp = hashtable[i];

        while (temp != NULL)
        {
            node *xyz = temp;
            temp = temp->next;
            free(xyz);
        }
        b = 1;
    }
    if (b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
