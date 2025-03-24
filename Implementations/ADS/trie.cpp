/*
Trie (Prefix Tree) is an advanced data structure used to store strings efficiently.
It is particularly useful for problems involving prefix searches, autocomplete systems, 
and dictionary implementations. Each node in a Trie represents a single character, 
and edges represent the connection between characters. A path from the root to a node 
represents a prefix or a complete string.

Complexity:
    - Insertion: O(L), where L is the length of the string being inserted.
    - Search: O(L), where L is the length of the string being searched.
    - Space: Can be high due to the storage of nodes for each character, 
        but can be optimized using techniques like compression (e.g., Ternary Search Trie).
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }

    ~Trie() {
        clear(root);
    }

private:
    void clear(TrieNode* node) {
        for (auto& pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha;
    cout << "Search 'apple': " << trie.search("apple") << endl;
    cout << "Search 'app': " << trie.search("app") << endl;
    cout << "Search 'bat': " << trie.search("bat") << endl;
    cout << "Search 'batman': " << trie.search("batman") << endl;
    cout << "Starts with 'ap': " << trie.startsWith("ap") << endl;
    cout << "Starts with 'ba': " << trie.startsWith("ba") << endl;
    cout << "Starts with 'cat': " << trie.startsWith("cat") << endl;

    return 0;
}