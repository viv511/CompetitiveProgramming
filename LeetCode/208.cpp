// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
using namespace std;

class Trie {
private: 
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
            isEnd = false;
        }
    };
    
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode *curr = root;

        for (char c : word) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                curr->child[i] = new TrieNode();
            }

            curr = curr->child[i];
        }

        curr->isEnd = true;
    }
    
    bool search(const string& word) {
        TrieNode *curr = root;

        for (char c : word) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                return false;
            }
            curr = curr->child[i];
        }

        return curr->isEnd;
    }
    
    bool startsWith(const string& prefix) {
        TrieNode *curr = root;

        for (char c : prefix) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                return false;
            }
            curr = curr->child[i];
        }

        return true;
    } 
};