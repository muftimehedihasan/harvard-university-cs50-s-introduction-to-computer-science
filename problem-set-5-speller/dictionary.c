#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose a large prime number for better distribution (26 may not be ideal)
const unsigned int N = 101;

// Hash table
node *table[N];

// Function prototypes (moved outside the struct for better organization)
unsigned int hash(const char *word);
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

// Hash function considering the entire word and using modulo
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    int c;
    while ((c = *word++) != '\0') {
        hash_value = (hash_value * 31 + c) % N; // Modulo by the number of buckets
    }
    return hash_value;
}

// Check if a word exists in the dictionary (iterates through linked list)
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *current = table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Load dictionary words into memory (allocates memory and handles collisions)
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) == 1) {
        // Convert to lowercase for case-insensitive search
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        unsigned int index = hash(word);
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            return false; // Memory allocation failed
        }
        strcpy(new_node->word, word);
        new_node->next = table[index];
        table[index] = new_node;
    }

    fclose(file);
    return true;
}

// Returns the number of words in the dictionary (iterates through all lists)
unsigned int size(void)
{
    unsigned int word_count = 0;
    for (int i = 0; i < N; i++) {
        node *current = table[i];
        while (current != NULL) {
            word_count++;
            current = current->next;
        }
    }
    return word_count;
}

// Unload dictionary and free allocated memory (recursive to free linked lists)
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        node *current = table[i];
        while (current != NULL) {
            node *temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}

