#include "../../common/leetcode_common.h"

// Bottom-up merge sort via the classic slow/fast-pointer split: find the
// middle, recursively sort each half, merge. O(log n) recursion depth
// instead of true O(1) space, but no extra containers beyond the pointers
// themselves -- the list is sorted in place, only rewired.
class Solution {
 public:
  ListNode* SortList(ListNode* head) {
    if (!head || !head->next_) return head;

    ListNode* slow = head;
    ListNode* fast = head->next_;
    while (fast && fast->next_) {
      slow = slow->next_;
      fast = fast->next_->next_;
    }
    ListNode* mid = slow->next_;
    slow->next_ = nullptr;

    ListNode* left = SortList(head);
    ListNode* right = SortList(mid);
    return Merge(left, right);
  }

 private:
  ListNode* Merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
      if (l1->val_ < l2->val_) {
        tail->next_ = l1;
        l1 = l1->next_;
      } else {
        tail->next_ = l2;
        l2 = l2->next_;
      }
      tail = tail->next_;
    }
    tail->next_ = l1 ? l1 : l2;
    return dummy.next_;
  }
};
// Временная сложность: O(n log n)
// Пространственная сложность: O(log n) -- глубина рекурсии.

int main() {
  Solution sol;

  ListNode* head1 = BuildList({4, 2, 1, 3});
  auto result1 = ListToVector(sol.SortList(head1));
  cout << "Input: head = [4,2,1,3]\n";
  cout << "Output: ";
  PrintVector(result1);
  cout << " -- expected [1, 2, 3, 4]\n";
  vector<int> expected1 = {1, 2, 3, 4};
  bool ok1 = result1 == expected1;
  cout << "[" << (ok1 ? "PASS" : "FAIL") << "]\n";

  ListNode* head2 = BuildList({-1, 5, 3, 4, 0});
  auto result2 = ListToVector(sol.SortList(head2));
  cout << "Input: head = [-1,5,3,4,0]\n";
  cout << "Output: ";
  PrintVector(result2);
  cout << " -- expected [-1, 0, 3, 4, 5]\n";
  vector<int> expected2 = {-1, 0, 3, 4, 5};
  bool ok2 = result2 == expected2;
  cout << "[" << (ok2 ? "PASS" : "FAIL") << "]\n";

  ListNode* head3 = BuildList({});
  auto result3 = ListToVector(sol.SortList(head3));
  cout << "Input: head = []\n";
  cout << "Output: ";
  PrintVector(result3);
  cout << " -- expected []\n";
  bool ok3 = result3.empty();
  cout << "[" << (ok3 ? "PASS" : "FAIL") << "]\n";

  return (ok1 && ok2 && ok3) ? 0 : 1;
}
