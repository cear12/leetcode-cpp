// Time: O(mn), Space: O(mn)

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        iota(dp[0].begin(), dp[0].end(), 0);
        for (size_t i = 1; i <= m; ++i) {
            dp[i][0] = i;
            for (size_t j = 1; j <= n; ++j)
                dp[i][j] = word1[i - 1] == word2[j - 1]
                    ? dp[i - 1][j - 1]
                    : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
        return dp[m][n];
    }
};
