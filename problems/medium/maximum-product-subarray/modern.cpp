#include "../../common/leetcode_common.h"

// Time: O(n), Space: O(n)

class Solution {
 public:
  int MaxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> max_dp(n), min_dp(n);
    max_dp[0] = min_dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; ++i) {
      max_dp[i] =
          max({nums[i], nums[i] * max_dp[i - 1], nums[i] * min_dp[i - 1]});
      min_dp[i] =
          min({nums[i], nums[i] * max_dp[i - 1], nums[i] * min_dp[i - 1]});
      ans = max(ans, max_dp[i]);
    }
    return ans;
  }
};

int main() {
  struct Case {
    vector<int> nums_;
    int expected_;
  };
  vector<Case> cases = {
      {{2, 3, -2, 4}, 6},
      {{-2, 0, -1}, 0},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.MaxProduct(c.nums_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
