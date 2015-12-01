/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"

#define SIZE 28

typedef struct node;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    
    FILE * inptr =fopen(dictionary, "r");
     if (inptr == NULL)
     {
        printf("Could read textfile %s.\n", text);
        return false;
     }
    
    tree = malloc(sizeof(node));
    node* cursor = NULL;
    
    for (int c = fgetc(inptr); c != EOF; c = fgetc(inptr))
     {
     
     }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}


typedef struct node {
 
    bool is_word;
    struct node* children[SIZE];
} node;
