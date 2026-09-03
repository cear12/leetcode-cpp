#include "../../common/leetcode_common.h"

class Solution {
 public:
  int LongestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int maxlen = 0;
    for (int x : s) {
      if (!s.count(x - 1)) {
        int y = x + 1;
        while (s.count(y)) ++y;
        maxlen = std::max(maxlen, y - x);
      }
    }
    return maxlen;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
  struct Case {
    vector<int> nums_;
    int expected_;
  };
  vector<Case> cases = {
      {{100, 4, 200, 1, 3, 2}, 4},
      {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
      {{1, 0, 1, 2}, 3},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.LongestConsecutive(c.nums_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
