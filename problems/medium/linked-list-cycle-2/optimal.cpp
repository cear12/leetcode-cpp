#include "../../common/leetcode_common.h"

class Solution {
 public:
  // Floyd's cycle detection: slow/fast pointers meet inside the cycle if one
  // exists; restarting one pointer from head then walking both one step at a
  // time finds the entry node -- a standard property of the algorithm.
  ListNode* DetectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next_) {
      slow = slow->next_;
      fast = fast->next_->next_;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next_;
          fast = fast->next_;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

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
