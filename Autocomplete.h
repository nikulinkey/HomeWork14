#pragma once
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

public:
TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
void findWords(TrieNode*, string, std::vector<string>&);
void writeWords(TrieNode*, string&);
void autoComplete(TrieNode*, string&, std::vector<string>&);
};