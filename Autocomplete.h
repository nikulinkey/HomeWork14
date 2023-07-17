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
void insert(TrieNode*, std::string);
bool search(TrieNode*, std::string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, std::string, int depth = 0);
void findWords(TrieNode*, std::string, std::vector<std::string>&);
string writeWords(TrieNode*, std::string&);
int autoComplete(TrieNode*, const std::string&, std::vector<std::string>&);
};