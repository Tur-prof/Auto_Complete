#pragma once
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

// Структура узла дерева 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, std::string);
std::vector<std::string> searchForWordsByPrefix(TrieNode*, std::string&);
void writeInVector(TrieNode*, char[], int, std::vector<std::string>&);
void writeInTrie(TrieNode*);
