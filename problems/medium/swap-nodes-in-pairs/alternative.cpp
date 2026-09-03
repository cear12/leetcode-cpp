#include "../../common/leetcode_common.h"

class Solution {
public:
    ListNode* SwapPairs(ListNode* head) {
        if (!head || !head->next_) return head;
        ListNode* next_node = head->next_;
        head->next_ = SwapPairs(head->next_->next_);
        next_node->next_ = head;
        return next_node;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> values_; vector<int> expected_; };
    vector<Case> cases = {
        {{1, 2, 3, 4}, {2, 1, 4, 3}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2, 3}, {2, 1, 3}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        ListNode* head = BuildList(c.values_);
        ListNode* result = sol.SwapPairs(head);
        vector<int> result_vec = ListToVector(result);
        cout << "Input: head = ";
        PrintVector(c.values_);
        cout << "\nOutput: ";
        PrintVector(result_vec);
        cout << " -- expected ";
        PrintVector(c.expected_);
        cout << "\n";
        bool ok = result_vec == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
