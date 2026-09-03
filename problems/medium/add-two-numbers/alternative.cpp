#include "../../common/leetcode_common.h"

class Solution {
    ListNode* Add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) return nullptr;
        int sum = (l1 ? l1->val_ : 0) + (l2 ? l2->val_ : 0) + carry;
        ListNode* node = new ListNode(sum % 10);
        node->next_ = Add(l1 ? l1->next_ : nullptr, l2 ? l2->next_ : nullptr, sum / 10);
        return node;
    }
public:
    ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
        return Add(l1, l2, 0);
    }
};
// Временная сложность: O(max(m,n))
// Пространственная сложность: O(max(m,n))

int main() {
    ListNode* l1 = BuildList({2, 4, 3});
    ListNode* l2 = BuildList({5, 6, 4});
    Solution sol;
    ListNode* result = sol.AddTwoNumbers(l1, l2);
    auto result_vec = ListToVector(result);

    cout << "Input: l1 = [2,4,3] (342), l2 = [5,6,4] (465)\n";
    cout << "Output: ";
    PrintVector(result_vec);
    cout << " -- expected [7,0,8] (807)\n";

    vector<int> expected = {7, 0, 8};
    bool ok = result_vec == expected;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
