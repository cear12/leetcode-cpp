class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Вставляем копии узлов в оригинальный список: A->A'->B->B'
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // 2. Проставляем random для копий
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 3. Отделяем копию от оригинала
        Node* dummy = new Node(0);
        Node* copyCur = dummy, *origCur = head;
        while (origCur) {
            copyCur->next = origCur->next;
            origCur->next = origCur->next->next;
            origCur = origCur->next;
            copyCur = copyCur->next;
        }
        return dummy->next;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
