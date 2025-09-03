// Time: O(mn), Space: O(n)

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);
        for (int j = 0; j <= n; ++j) dp[j] = j;
        for (int i = 1; i <= m; ++i) {
            int prev = dp[0]; // dp[i-1][j-1]
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; // dp[i-1][j]
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
