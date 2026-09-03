#include "../../common/leetcode_common.h"

class Solution {
 public:
  int LongestSubarray(vector<int>& nums) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int result = 0;
    int start = 0;
    int zeroes = 0;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      zeroes += !nums[i];

      while (zeroes > 1) {
        zeroes -= !nums[start++];
      }

      result = std::max(result, i - start);
    }

    return result;
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
      {{1, 1, 0, 1}, 3},
      {{0, 1, 1, 1, 0, 1, 1, 0, 1}, 5},
      {{1, 1, 1}, 2},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.LongestSubarray(c.nums_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
