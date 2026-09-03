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
  ListNode* SwapPairs(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    while (head && head->next_) {
      ListNode* first = head;
      ListNode* second = head->next_;

      prev->next_ = second;
      first->next_ = second->next_;
      second->next_ = first;

      prev = first;
      head = first->next_;
    }
    return dummy.next_;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
  struct Case {
    vector<int> values_;
    vector<int> expected_;
  };
  vector<Case> cases = {
      {{1, 2, 3, 4}, {2, 1, 4, 3}},
      {{}, {}},
      {{1}, {1}},
      {{1, 2, 3}, {2, 1, 3}},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    ListNode* head = BuildList(c.values_);
    ListNode* result = sol.SwapPairs(head);
    vector<int> result_vec = ListToVector(result);
    cout << "Input: head = ";
    PrintVector(c.values_);
    cout << "\nOutput: ";
    PrintVector(result_vec);
    cout << " -- expected ";
    PrintVector(c.expected_);
    cout << "\n";
    bool ok = result_vec == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
