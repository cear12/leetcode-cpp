#include "../../common/leetcode_common.h"

class Solution {
 public:
  vector<int> ProductExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1), right(n, 1), result(n);

    for (int i = 1; i < n; ++i) left[i] = left[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; --i) right[i] = right[i + 1] * nums[i + 1];

    for (int i = 0; i < n; ++i) result[i] = left[i] * right[i];

    return result;
  }
};  // Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
  struct Case {
    vector<int> nums_;
    vector<int> expected_;
  };
  vector<Case> cases = {
      {{1, 2, 3, 4}, {24, 12, 8, 6}},
      {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    auto result = sol.ProductExceptSelf(c.nums_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << "\nOutput: ";
    PrintVector(result);
    cout << " -- expected ";
    PrintVector(c.expected_);
    cout << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
