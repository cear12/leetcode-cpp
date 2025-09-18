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
