#include "../../common/leetcode_common.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        int length = 0;
        ListNode* curr = head;
        // Считаем длину списка
        while (curr) {
            ++length;
            curr = curr->next;
        }
        curr = &dummy;
        // Доходим до узла перед удаляемым
        for (int i = 0; i < length - n; ++i)
            curr = curr->next;
        curr->next = curr->next->next;
        return dummy.next;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> values; int n; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
        {{1}, 1, {}},
        {{1, 2}, 1, {1}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        ListNode* head = buildList(c.values);
        ListNode* result = sol.removeNthFromEnd(head, c.n);
        vector<int> resultVec = listToVector(result);
        cout << "Input: head = ";
        printVector(c.values);
        cout << ", n = " << c.n << "\nOutput: ";
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
