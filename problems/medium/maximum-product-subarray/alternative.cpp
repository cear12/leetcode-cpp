#include "../../common/leetcode_common.h"

// Time: O(n), Space: O(1)

class Solution {
 public:
  int MaxProduct(vector<int>& nums) {
    int ans = nums[0], left = 1, right = 1, n = nums.size();
    for (int i = 0; i < n; ++i) {
      left = (left == 0 ? 1 : left) * nums[i];
      right = (right == 0 ? 1 : right) * nums[n - 1 - i];
      ans = max(ans, max(left, right));
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
