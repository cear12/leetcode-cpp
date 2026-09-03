#include "../../common/leetcode_common.h"

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

int main() {
    cout << "Input: insert(\"apple\"), search(\"apple\"), search(\"app\"), "
         << "startsWith(\"app\"), insert(\"app\"), search(\"app\")\n";

    Trie trie;
    trie.insert("apple");

    bool r1 = trie.search("apple");
    bool r2 = trie.search("app");
    bool r3 = trie.startsWith("app");
    trie.insert("app");
    bool r4 = trie.search("app");

    cout << "Output: " << boolalpha << r1 << ", " << r2 << ", " << r3 << ", " << r4
         << " -- expected true, false, true, true\n";

    bool ok = r1 == true && r2 == false && r3 == true && r4 == true;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}

