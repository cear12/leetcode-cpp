struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
