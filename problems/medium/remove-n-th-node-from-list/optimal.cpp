struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        // Двигаем fast на n шагов вперед
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        // Двигаем оба, пока fast не станет последним
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // Удаляем целевой узел
        slow->next = slow->next->next;
        return dummy.next;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
