#include "../../common/leetcode_common.h"

// Альтернативное решение: хэш-таблица для соответствия оригинал ↔ копия
class Node {
public:
    int val_;
    Node* next_;
    Node* random_;
    Node(int val) : val_(val), next_(nullptr), random_(nullptr) {}
};
class Solution {
public:
    Node* CopyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> mp;
        Node* cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val_);
            cur = cur->next_;
        }
        cur = head;
        while (cur) {
            mp[cur]->next_ = mp[cur->next_];
            mp[cur]->random_ = mp[cur->random_];
            cur = cur->next_;
        }
        return mp[head];
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n) 

int main() {
    // Build [[7,null],[13,0],[11,4],[10,2],[1,0]]: 5 nodes, values 7,13,11,10,1,
    // random pointers by index (-1 = null).
    vector<int> values = {7, 13, 11, 10, 1};
    vector<int> random_index = {-1, 0, 4, 2, 0};

    vector<Node*> orig;
    for (int v : values) orig.push_back(new Node(v));
    for (size_t i = 0; i + 1 < orig.size(); ++i) orig[i]->next_ = orig[i + 1];
    for (size_t i = 0; i < orig.size(); ++i) {
        if (random_index[i] >= 0) orig[i]->random_ = orig[random_index[i]];
    }

    Solution sol;
    Node* copy_head = sol.CopyRandomList(orig[0]);

    cout << "Input: [[7,null],[13,0],[11,4],[10,2],[1,0]]\n";

    // Walk the copy, recording each copied node in order, and cross-check
    // it against the original list at the same position.
    vector<Node*> copy_list;
    for (Node* n = copy_head; n != nullptr; n = n->next_) copy_list.push_back(n);

    unordered_set<Node*> original_node_set(orig.begin(), orig.end());

    bool ok = copy_list.size() == orig.size();
    cout << "Output: [";
    for (size_t i = 0; ok && i < copy_list.size(); ++i) {
        bool value_matches = copy_list[i]->val_ == values[i];
        bool is_separate_node = !original_node_set.count(copy_list[i]);  // must be a brand-new node
        bool random_is_correct =
            random_index[i] < 0 ? copy_list[i]->random_ == nullptr : copy_list[i]->random_ == copy_list[random_index[i]];

        ok = ok && value_matches && is_separate_node && random_is_correct;

        cout << copy_list[i]->val_;
        if (i + 1 < copy_list.size()) cout << ", ";
    }
    cout << "]\n";

    cout << "[" << (ok ? "PASS" : "FAIL")
         << "] values and random-pointer structure match, and the copy shares no nodes with the original\n";
    return ok ? 0 : 1;
}
