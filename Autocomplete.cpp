#include <iostream>
#include <vector>
#include <string>
#include "Autocomplete.h"

using namespace std;

TrieNode* TrieNode::getNewNode(void)
{

    TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void TrieNode::insert(TrieNode* root, std::string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {

        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool TrieNode::search(TrieNode* root, std::string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

bool TrieNode::isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* TrieNode::remove(TrieNode* root, std::string key, int depth)
{
    if (!root)
        return nullptr;

    if (depth == key.size()) {

        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    return root;
}

void TrieNode::findWords(TrieNode* root, std::string word, std::vector<std::string>& words)
{
    if (root->isEndOfWord)
        words.push_back(word);

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            // child node character value
            char child = 'a' + i;
            findWords(root->children[i], word + child, words);
        }
}

string TrieNode::writeWords(TrieNode* root, std::string& word)
{
    std::vector<std::string>words;
    words.clear();
    autoComplete(root, word, words);
    if (!autoComplete(root, word, words))
        return " ";

    for (int i = 0; i < words.size(); i++)
    {
        std::cout << i << " : " << words[i] << std::endl;
    }
    int choise = 0;
    std::cout << "choose word to autocomplete" << std::endl;
    std::cin >> choise;

    return words[choise];

}
int TrieNode::autoComplete(TrieNode* root, const std::string& word, std::vector<std::string>& words)
{
    
    TrieNode* current = root;
    for (int i = 0; i < word.length(); i++)
    {
        int ind = word[i] - 'a';

        if (!current->children[ind]) {
            cout << "no words find" << endl;
            return 0;
        }

        current = current->children[ind];
    }
    if (isEmpty(current)) {
        cout << "no more words find" << endl;
        return 0;
    }
    findWords(current, word, words);
    return 1;

}