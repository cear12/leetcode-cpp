#include "../../common/leetcode_common.h"

class Solution {
 public:
  ListNode* RemoveNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next_ = head;
    int length = 0;
    ListNode* curr = head;
    // Считаем длину списка
    while (curr) {
      ++length;
      curr = curr->next_;
    }
    curr = &dummy;
    // Доходим до узла перед удаляемым
    for (int i = 0; i < length - n; ++i) curr = curr->next_;
    curr->next_ = curr->next_->next_;
    return dummy.next_;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
  struct Case {
    vector<int> values_;
    int n_;
    vector<int> expected_;
  };
  vector<Case> cases = {
      {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
      {{1}, 1, {}},
      {{1, 2}, 1, {1}},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    ListNode* head = BuildList(c.values_);
    ListNode* result = sol.RemoveNthFromEnd(head, c.n_);
    vector<int> result_vec = ListToVector(result);
    cout << "Input: head = ";
    PrintVector(c.values_);
    cout << ", n = " << c.n_ << "\nOutput: ";
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
