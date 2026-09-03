#include "../../common/leetcode_common.h"

// Алгоритм "черепаха и заяц", аналог задачи с циклом в связном списке
// Идея: индексы массива используются как “указатели”.
// nums[i] указывает на следующий индекс.
// Повторяющийся элемент создаёт цикл.

class Solution {
 public:
  int FindDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Этап 1: поиск пересечения в "цикле"
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // Этап 2: нахождение входа в цикл (дубликата)
    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
  struct Case {
    vector<int> nums_;
    int expected_;
  };
  vector<Case> cases = {
      {{1, 3, 4, 2, 2}, 2},
      {{3, 1, 3, 4, 2}, 3},
      {{3, 3, 3, 3, 3}, 3},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.FindDuplicate(c.nums_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
