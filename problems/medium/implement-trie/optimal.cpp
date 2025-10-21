struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto &c : children) c = nullptr;
    }
};

// O(n) per operation, O(k * n) space (k — alphabet size)
class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children[i]) node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int i = ch - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return true;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n - буквы алфавита)
