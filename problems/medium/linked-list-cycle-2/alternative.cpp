#include "../../common/leetcode_common.h"

class Solution {
 public:
  ListNode* DetectCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    while (head) {
      if (visited.count(head)) return head;
      visited.insert(head);
      head = head->next_;
    }
    return nullptr;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
  // Example 1: head = [3,2,0,-4], pos = 1 -- tail (-4) connects back to the
  // node holding 2 (index 1).
  ListNode* head = BuildList({3, 2, 0, -4});
  ListNode* cycle_entry = head->next_;  // node holding 2
  ListNode* tail = head;
  while (tail->next_) tail = tail->next_;
  tail->next_ = cycle_entry;

  Solution sol;
  ListNode* result = sol.DetectCycle(head);

  cout << "Input: head = [3,2,0,-4], pos = 1\n";
  cout << "Output: node with val " << (result ? result->val_ : -1)
       << " -- expected 2\n";
  bool ok1 = result == cycle_entry;
  cout << "[" << (ok1 ? "PASS" : "FAIL") << "]\n";

  // Example 3: head = [1], pos = -1 -- no cycle.
  ListNode* no_cycle_head = BuildList({1});
  ListNode* result2 = sol.DetectCycle(no_cycle_head);

  cout << "Input: head = [1], pos = -1\n";
  cout << "Output: " << (result2 ? "cycle found" : "no cycle")
       << " -- expected no cycle\n";
  bool ok2 = result2 == nullptr;
  cout << "[" << (ok2 ? "PASS" : "FAIL") << "]\n";

  return (ok1 && ok2) ? 0 : 1;
}
