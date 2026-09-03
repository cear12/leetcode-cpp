#include "../../common/leetcode_common.h"

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

int main() {
    // Build [[7,null],[13,0],[11,4],[10,2],[1,0]]: 5 nodes, values 7,13,11,10,1,
    // random pointers by index (-1 = null).
    vector<int> values = {7, 13, 11, 10, 1};
    vector<int> randomIndex = {-1, 0, 4, 2, 0};

    vector<Node*> orig;
    for (int v : values) orig.push_back(new Node(v));
    for (size_t i = 0; i + 1 < orig.size(); ++i) orig[i]->next = orig[i + 1];
    for (size_t i = 0; i < orig.size(); ++i) {
        if (randomIndex[i] >= 0) orig[i]->random = orig[randomIndex[i]];
    }

    Solution sol;
    Node* copyHead = sol.copyRandomList(orig[0]);

    cout << "Input: [[7,null],[13,0],[11,4],[10,2],[1,0]]\n";

    // Walk the copy, recording each copied node in order, and cross-check
    // it against the original list at the same position.
    vector<Node*> copyList;
    for (Node* n = copyHead; n != nullptr; n = n->next) copyList.push_back(n);

    unordered_set<Node*> originalNodeSet(orig.begin(), orig.end());

    bool ok = copyList.size() == orig.size();
    cout << "Output: [";
    for (size_t i = 0; ok && i < copyList.size(); ++i) {
        bool valueMatches = copyList[i]->val == values[i];
        bool isSeparateNode = !originalNodeSet.count(copyList[i]);  // must be a brand-new node
        bool randomIsCorrect =
            randomIndex[i] < 0 ? copyList[i]->random == nullptr : copyList[i]->random == copyList[randomIndex[i]];

        ok = ok && valueMatches && isSeparateNode && randomIsCorrect;

        cout << copyList[i]->val;
        if (i + 1 < copyList.size()) cout << ", ";
    }
    cout << "]\n";

    cout << "[" << (ok ? "PASS" : "FAIL")
         << "] values and random-pointer structure match, and the copy shares no nodes with the original\n";
    return ok ? 0 : 1;
}
