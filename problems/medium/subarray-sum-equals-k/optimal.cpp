#include "../../common/leetcode_common.h"

class Solution {
 public:
  int SubarraySum(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> cnt{{0, 1}};
    int sum = 0, ans = 0;
    for (auto x : nums) {
      sum += x;
      ans += cnt[sum - k];
      cnt[sum]++;
    }
    return ans;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
  struct Case {
    vector<int> nums_;
    int k_;
    int expected_;
  };
  vector<Case> cases = {
      {{1, 1, 1}, 2, 2},
      {{1, 2, 3}, 3, 2},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.SubarraySum(c.nums_, c.k_);
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
