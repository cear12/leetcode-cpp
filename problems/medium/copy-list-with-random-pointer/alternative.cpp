// Альтернативное решение: хэш-таблица для соответствия оригинал ↔ копия
#include <unordered_map>
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> mp;
        Node* cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n) 
