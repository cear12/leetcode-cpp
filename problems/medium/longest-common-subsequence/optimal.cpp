#include "../../common/leetcode_common.h"

class Solution {
 public:
  int LongestCommonSubsequence(string text1, string text2) {
    const auto kText1Size = text1.size();
    const auto kText2Size = text2.size();

    vector<vector<int> > dp(kText1Size + 1, vector<int>(kText2Size + 1, 0));

    for (int i = 1; i <= static_cast<int>(kText1Size); ++i) {
      for (int j = 1; j <= static_cast<int>(kText2Size); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[kText1Size][kText2Size];
  }
};
// Время: O(m*n)
// Память: O(m*n)

int main() {
  struct Case {
    string text1_;
    string text2_;
    int expected_;
  };
  vector<Case> cases = {
      {"abcde", "ace", 3},
      {"abc", "abc", 3},
      {"abc", "def", 0},
  };

  bool all_ok = true;
  Solution sol;
  for (const auto& c : cases) {
    int result = sol.LongestCommonSubsequence(c.text1_, c.text2_);
    cout << "Input: text1 = \"" << c.text1_ << "\", text2 = \"" << c.text2_
         << "\"\n";
    cout << "Output: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
