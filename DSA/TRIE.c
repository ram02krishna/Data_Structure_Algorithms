#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26 // Number of letters in the English alphabet

// Define a Trie node
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE]; // Array of pointers to child nodes
    bool isEndOfWord;                         // Flag to mark the end of a word
} TrieNode;

// Function to create a new Trie node
TrieNode *createNode()
{
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a word into the Trie
void insert(TrieNode *root, const char *word)
{
    TrieNode *current = root;

    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a'; // Calculate index for character
        if (!current->children[index]) //OR if(current->children[index] == NULL)
        {
            current->children[index] = createNode(); // Create node if not present
        }
        current = current->children[index];
    }

    // Mark the last node as the end of a word
    current->isEndOfWord = true;
}

// Function to search for a word in the Trie
bool search(TrieNode *root, const char *word)
{
    TrieNode *current = root;

    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a'; // Calculate index for character
        if (!current->children[index])
        {
            return false; // word not found
        }
        current = current->children[index];
    }

    // Return true if the last node is the end of a word
    return current != NULL && current->isEndOfWord;
}

// Function to check if a node has any children
bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            return false; // At least one child exists
        }
    }
    return true; // No children
}

// Recursive function to delete a word from the Trie
TrieNode *deleteWord(TrieNode *root, const char *word, int depth)
{
    // Base case: if root is NULL
    if (!root)
    {
        return NULL;
    }

    // If the end of the word is reached
    if (depth == strlen(word))
    {
        // Unmark the current node as end of word
        if (root->isEndOfWord)
        {
            root->isEndOfWord = false;
        }

        // If the node has no children, delete it
        if (isEmpty(root))
        {
            free(root);
            root = NULL;
        }

        return root;
    }

    // Recur for the child node corresponding to the current character
    int index = word[depth] - 'a';
    root->children[index] = deleteWord(root->children[index], word, depth + 1);

    // If the current node has no children and is not the end of another word, delete it
    if (isEmpty(root) && !root->isEndOfWord)
    {
        free(root);
        root = NULL;
    }

    return root;
}

// Driver function to test the Trie
int main()
{
    // Input words (only 'a' through 'z' and lowercase)
    const char *words[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane"};
    int n = sizeof(words) / sizeof(words[0]);

    // Initialize the root node
    TrieNode *root = createNode();

    // Insert words into the Trie
    for (int i = 0; i < n; i++)
    {
        insert(root, words[i]);
    }

    // Search for words in the Trie
    printf("Search for 'the': %s\n", search(root, "the") ? "Found" : "Not Found");
    printf("Search for 'these': %s\n", search(root, "these") ? "Found" : "Not Found");

    // Delete a word (pass depth as 0)
    root = deleteWord(root, "heroplane", 0);

    // Search for words after deletion
    printf("Search for 'hero': %s\n", search(root, "hero") ? "Found" : "Not Found");
    printf("Search for 'heroplane': %s\n", search(root, "heroplane") ? "Found" : "Not Found");

    return 0;
}
