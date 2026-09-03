#include "../../common/leetcode_common.h"

struct TrieNode {
    TrieNode* children_[26];
    bool is_word_;
    TrieNode() : is_word_(false) {
        for (auto &c : children_) c = nullptr;
    }
};

// O(n) per operation, O(k * n) space (k — alphabet size)
class Trie {
private:
    TrieNode* root_;
public:
    Trie() { root_ = new TrieNode(); }

    void Insert(string word) {
        TrieNode* node = root_;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children_[i]) node->children_[i] = new TrieNode();
            node = node->children_[i];
        }
        node->is_word_ = true;
    }

    bool Search(string word) {
        TrieNode* node = root_;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children_[i]) return false;
            node = node->children_[i];
        }
        return node->is_word_;
    }

    bool StartsWith(string prefix) {
        TrieNode* node = root_;
        for (char ch : prefix) {
            int i = ch - 'a';
            if (!node->children_[i]) return false;
            node = node->children_[i];
        }
        return true;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n - буквы алфавита)

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

