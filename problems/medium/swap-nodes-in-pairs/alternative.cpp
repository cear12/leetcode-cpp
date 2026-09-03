#include "../../common/leetcode_common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* nextNode = head->next;
        head->next = swapPairs(head->next->next);
        nextNode->next = head;
        return nextNode;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> values; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4}, {2, 1, 4, 3}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2, 3}, {2, 1, 3}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        ListNode* head = buildList(c.values);
        ListNode* result = sol.swapPairs(head);
        vector<int> resultVec = listToVector(result);
        cout << "Input: head = ";
        printVector(c.values);
        cout << "\nOutput: ";
        printVector(resultVec);
        cout << " -- expected ";
        printVector(c.expected);
        cout << "\n";
        bool ok = resultVec == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
