#include "../../common/leetcode_common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            head = first->next;
        }
        return dummy.next;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

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
