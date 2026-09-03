#include <unordered_set>

// O(n) time, O(n) space
ListNode* detectCycle(ListNode* head) {
    std::unordered_set<ListNode*> visited;
    while (head) {
        if (visited.count(head))
            return head;
        visited.insert(head);
        head = head->next;
    }
    return nullptr;
}
// Временная сложность: O(n)
// Пространственная сложность: O(n)
