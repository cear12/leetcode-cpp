#include "../../common/leetcode_common.h"

class Solution {
 public:
  ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      int sum = (l1 ? l1->val_ : 0) + (l2 ? l2->val_ : 0) + carry;
      carry = sum / 10;
      curr->next_ = new ListNode(sum % 10);
      curr = curr->next_;
      if (l1) l1 = l1->next_;
      if (l2) l2 = l2->next_;
    }
    return dummy.next_;
  }
};
// Временная сложность: O(max(m,n))
// Пространственная сложность: O(max(m,n))

int main() {
  ListNode* l1 = BuildList({2, 4, 3});
  ListNode* l2 = BuildList({5, 6, 4});
  Solution sol;
  ListNode* result = sol.AddTwoNumbers(l1, l2);
  auto result_vec = ListToVector(result);

  cout << "Input: l1 = [2,4,3] (342), l2 = [5,6,4] (465)\n";
  cout << "Output: ";
  PrintVector(result_vec);
  cout << " -- expected [7,0,8] (807)\n";

  vector<int> expected = {7, 0, 8};
  bool ok = result_vec == expected;
  cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  return ok ? 0 : 1;
}
