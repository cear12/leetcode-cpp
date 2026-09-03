#include "../../common/leetcode_common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
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
