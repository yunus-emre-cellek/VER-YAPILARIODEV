#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode* root, char* word) {
    TrieNode* current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }

        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

int search(TrieNode* root, char* word) {
    TrieNode* current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            return 0;
        }

        current = current->children[index];
    }

    return current->isEndOfWord;
}

int main() {
    TrieNode* root = createNode();

    insert(root, "cat");
    insert(root, "car");
    insert(root, "care");

    if (search(root, "car")) {
        printf("Kelime bulundu\n");
    }
    else {
        printf("Kelime bulunamadi\n");
    }

    return 0;
}