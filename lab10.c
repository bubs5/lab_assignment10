#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct Trie
{
    struct Trie* children[ALPHABET_SIZE];
    int count;
};

void insert(struct Trie **ppTrie, char *word) 
{
    struct Trie* curr = *ppTrie;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = (struct Trie*)malloc(sizeof(struct Trie));
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                curr->children[index]->children[j] = NULL;
            }
            curr->children[index]->count = 0;
        }
        curr = curr->children[index];
    }
    curr->count++;
}
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    struct Trie* curr = pTrie;
    for (int i = 0; word[i] != '\0'; i++) 
    {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) 
        {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->count;
}
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    if (pTrie == NULL) 
    {
        return NULL;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        if (pTrie->children[i] != NULL) 
        {
            deallocateTrie(pTrie->children[i]);
        }
    }
    free(pTrie);
    return NULL;
};

int main(void)
{
   struct Trie* trie = (struct Trie*)malloc(sizeof(struct Trie));
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        trie->children[i] = NULL;
    }
    trie->count = 0;
    int numWords;
    scanf("%d", &numWords);

    char word[100];
    for (int i = 0; i < numWords; i++) 
    {
        scanf("%s", word);
        insert(&trie, word);
    }

    char* pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) 
    {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }

    trie = deallocateTrie(trie);
    if (trie != NULL) 
    {
        printf("There is an error in this program\n");
    }

    return 0;struct Trie* trie = (struct Trie*)malloc(sizeof(struct Trie));
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        trie->children[i] = NULL;
    }

    trie->count = 0;
    int numWords;
    scanf("%d", &numWords);

    // read and insert each word into the trie data structure
    char word[100];
    for (int i = 0; i < numWords; i++) {
        scanf("%s", word);
        insert(&trie, word);
    }

    // search for each test word and print the number of occurrences
    char* pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }

    // deallocate the trie data structure
    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }

    return 0;
}
