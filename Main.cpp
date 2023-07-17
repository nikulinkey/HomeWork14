#include <iostream>
#include <string>
#include "Autocomplete.h"

int main()
{
    TrieNode* root = new TrieNode();
    root->getNewNode();
    root->insert(root, "hello");
    root->insert(root, "hellsing");
    root->insert(root, "hell");
    root->insert(root, "helicopter");
    root->insert(root, "help");
    root->insert(root, "helps");
    root->insert(root, "helping");
    root->insert(root, "friend");
    root->insert(root, "fried");
    root->insert(root, "freek");
    root->insert(root, "freekly");
    root->insert(root, "friday");
    root->insert(root, "fridge");
    root->insert(root, "free");

    bool chatworks = true;
    std::vector<string> messages;
    while (chatworks)
    {
        string message;
        std::cout << "write message, or 'end' to stop chat" << std::endl;
        std::cin >> message;
        if (message == "end")
        {
            chatworks = false;
            break;
        }
        message = root->writeWords(root, message);
        messages.push_back(message);
        std::cout << "send message? y/n" << endl;
        char choise = 'n';
        std::cin >> choise;
        if (choise == 'y')
        {
            std::cout << "User: ";
            for (int i = 0; i < messages.size(); i++)
            {
                cout << messages[i] << " ";
            }
            std::cout << endl;
            messages.clear();
        }
    }
}