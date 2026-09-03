#include "../../common/leetcode_common.h"

class Solution {
 public:
  int LongestOnes(std::vector<int>& nums, int k) {
    int n = nums.size(), max_len = 0;
    for (int i = 0; i < n; ++i) {
      int flips = 0, len = 0;
      for (int j = i; j < n && flips <= k; ++j) {
        if (nums[j] == 0) ++flips;
        if (flips > k) break;
        ++len;
      }
      max_len = std::max(max_len, len);
    }
    return max_len;
  }
};
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

int main() {
  struct Case {
    vector<int> nums_;
    int k_;
    int expected_;
  };
  vector<Case> cases = {
      {{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6},
      {{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.LongestOnes(c.nums_, c.k_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << ", k = " << c.k_ << "\nOutput: " << result << " -- expected "
         << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
