#include "../../common/leetcode_common.h"

// Time: O(mn), Space: O(n)

class Solution {
 public:
  int MinDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<int> dp(n + 1);
    for (int j = 0; j <= n; ++j) dp[j] = j;
    for (int i = 1; i <= m; ++i) {
      int prev = dp[0];  // dp[i-1][j-1]
      dp[0] = i;
      for (int j = 1; j <= n; ++j) {
        int temp = dp[j];  // dp[i-1][j]
        if (word1[i - 1] == word2[j - 1])
          dp[j] = prev;
        else
          dp[j] = 1 + min({dp[j - 1], temp, prev});
        prev = temp;
      }
    }
    return dp[n];
  }
};

int main() {
  struct Case {
    string word1_;
    string word2_;
    int expected_;
  };
  vector<Case> cases = {
      {"horse", "ros", 3},
      {"intention", "execution", 5},
  };

  bool all_ok = true;
  Solution sol;
  for (const auto& c : cases) {
    int result = sol.MinDistance(c.word1_, c.word2_);
    cout << "Input: word1 = \"" << c.word1_ << "\", word2 = \"" << c.word2_
         << "\"\n";
    cout << "Output: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
