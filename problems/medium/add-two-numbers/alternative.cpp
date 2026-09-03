#include "../../common/leetcode_common.h"

class Solution {
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && carry == 0) return nullptr;
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        ListNode* node = new ListNode(sum % 10);
        node->next = add(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);
        return node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
// Временная сложность: O(max(m,n))
// Пространственная сложность: O(max(m,n))

int main() {
    ListNode* l1 = buildList({2, 4, 3});
    ListNode* l2 = buildList({5, 6, 4});
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    auto resultVec = listToVector(result);

    cout << "Input: l1 = [2,4,3] (342), l2 = [5,6,4] (465)\n";
    cout << "Output: ";
    printVector(resultVec);
    cout << " -- expected [7,0,8] (807)\n";

    vector<int> expected = {7, 0, 8};
    bool ok = resultVec == expected;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
