#include "../../common/leetcode_common.h"

struct TrieNode {
    unordered_map<char, TrieNode*> next_;
    bool is_word_ = false;
};

class Trie {
private:
    TrieNode* root_;
public:
    Trie() { root_ = new TrieNode(); }

    void Insert(string word) {
        TrieNode* node = root_;
        for (char c : word) {
            if (!node->next_[c]) node->next_[c] = new TrieNode();
            node = node->next_[c];
        }
        node->is_word_ = true;
    }

    bool Search(string word) {
        TrieNode* node = root_;
        for (char c : word) {
            if (!node->next_[c]) return false;
            node = node->next_[c];
        }
        return node->is_word_;
    }

    bool StartsWith(string prefix) {
        TrieNode* node = root_;
        for (char c : prefix) {
            if (!node->next_[c]) return false;
            node = node->next_[c];
        }
        return true;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    cout << "Input: Insert(\"apple\"), Search(\"apple\"), Search(\"app\"), "
         << "StartsWith(\"app\"), Insert(\"app\"), Search(\"app\")\n";

    Trie trie;
    trie.Insert("apple");

    bool r1 = trie.Search("apple");
    bool r2 = trie.Search("app");
    bool r3 = trie.StartsWith("app");
    trie.Insert("app");
    bool r4 = trie.Search("app");

    cout << "Output: " << boolalpha << r1 << ", " << r2 << ", " << r3 << ", " << r4
         << " -- expected true, false, true, true\n";

    bool ok = r1 == true && r2 == false && r3 == true && r4 == true;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}

