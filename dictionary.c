// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

//count variable
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //hash word to obatain a hash value
    int hashed = hash(word);

    //Access linked list at that index
    node *n = table[hashed];
    if (n == NULL)
    {
        return 1;
    }

    //Traverse linked list looking for new word
    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
    {
        return true;
    }
    n = n -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int num = 0;
    //loop through each word
    for (int i = 0; i < strlen(word); i++)
     {
        // num += toupper(word[i] - 'A');
        //capitalise each word and multiply by
        num += toupper(word[i] * 26) * num;
     }
     num = num % N;
    return num;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open dictionary file
    FILE *file = fopen(dictionary, "r");
    //check null
    if (dictionary == NULL)
    {
        printf("Could not open%s\n", dictionary);
        return 1;
    }
    char buffer[LENGTH + 1];

    //read strings from file into buffer
    while (fscanf(file, "%s", buffer) != EOF)
    {
        //allocate space and create new node for each word
        node *n = malloc(sizeof(node));
        //check for NULL
        if (n == NULL)
        {
            return 1;
        }
        //copy word into node using strcpy
        strcpy(n->word, buffer);
        n->next = NULL;

        //Use the hash function to hash words
        int hashed = hash(buffer);

        //set node pointer to current head
        n->next = table[hashed];
        //then set head to point to the new node
        table[hashed] = n;
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //loop over hash tables
    for (int i = 0; i < N; i++)
    {
        //set cursor to first item in node
        node *cursor = table[i];

         //keep moving cursor until you get to NULL
        while(cursor != NULL)
        {
            //assign temporary node
            node *tmp = cursor;
            cursor = cursor->next;
            //free up memory
            free(tmp);
        }
        if (cursor == NULL)
        {
            if (i == N - 1)
            {
                return true;
            }
        }
    }
    return false;
}
