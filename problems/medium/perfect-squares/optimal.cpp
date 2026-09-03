#include "../../common/leetcode_common.h"

class Solution {
 public:
  int NumSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;  // BUG FIX: was `dp = 0` (assigning an int to the whole vector
                // -- doesn't compile)
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};
// Временная сложность: O(n * sqrt(n))
// Пространственная сложность: O(n)

int main() {
  struct Case {
    int n_;
    int expected_;
  };
  vector<Case> cases = {
      {12, 3},
      {13, 2},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.NumSquares(c.n_);
    cout << "Input: n = " << c.n_ << "\nOutput: " << result << " -- expected "
         << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
