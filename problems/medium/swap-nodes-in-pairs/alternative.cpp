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
