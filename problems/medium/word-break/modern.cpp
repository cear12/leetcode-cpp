#include <unordered_set>
#include <string_view>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> dict;
        for (const auto& w : wordDict) dict.emplace(w);
        vector<bool> dp(s.size()+1);
        dp[ 0 ] = true;
        for (size_t i = 1; i <= s.size(); ++i)
            for (size_t j = 0; j < i; ++j)
                if (dp[j] && dict.count(string_view(s.data()+j, i-j))) {
                    dp[i] = true;
                    break;
                }
        return dp[s.size()];
    }
};
