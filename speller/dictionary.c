// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 416;

//functions for future use
unsigned int word_counter = 0; // variable to keep track of words.
unsigned int hash_value;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hash word with hash function
    hash_value = hash(word);
    // access linked list associated with number
    node *cursor = table[hash_value];
    // go throug corresponding linked list from hash table index
        while(cursor != 0)
        {
            if(strcasecmp(word, cursor->word) == 0)
            {
                return true;
            }
            // point to next node
            cursor = cursor->next;
        }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Read strings from file
    char tmp_word[LENGTH+1];
    while(fscanf(source, "%s", tmp_word) != EOF)
    {

        // create new node
        node *new_word = malloc(sizeof(node));
        if(new_word == NULL)
        {
            return NULL;
        }
        strcpy(new_word->word, tmp_word);

        //hash the word
        hash_value = hash(tmp_word);
        // Insert node into hash table
        new_word->next = table[hash_value];
        //first element in linked list/table index = new_word;
        table[hash_value] = new_word;

        word_counter ++;

    }

    // close dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // count the size as the dictionary is loaded show here when called.
    if (word_counter > 0)
    {
        return word_counter;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    // loop through hash table
    for (int i = 0; i < N; i++)
    {
        // point cursor to head of linked list
        node *cursor = table[i];
        // loop through list
        while(cursor)
        {
            // set temp to cursor
            node *tmp = cursor;
            // move cursor to next element
            cursor = cursor->next;
            // free up momory in tmp
            free(tmp);
        }

    }
    return true;
}
