#include <unordered_map>

struct TrieNode {
    unordered_map<char, TrieNode*> next;
    bool isWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->next[c]) return false;
            node = node->next[c];
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->next[c]) return false;
            node = node->next[c];
        }
        return true;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)
