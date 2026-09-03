#include "../../common/leetcode_common.h"

// Time: O(mn), Space: O(mn)

class Solution {
 public:
  int MinDistance(string word1, string word2) {
    size_t m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    iota(dp[0].begin(), dp[0].end(), 0);
    for (size_t i = 1; i <= m; ++i) {
      dp[i][0] = i;
      for (size_t j = 1; j <= n; ++j)
        dp[i][j] =
            word1[i - 1] == word2[j - 1]
                ? dp[i - 1][j - 1]
                : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    }
    return dp[m][n];
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
