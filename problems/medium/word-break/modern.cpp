#include "../../common/leetcode_common.h"

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

int main() {
    struct Case { string s; vector<string> wordDict; bool expected; };
    vector<Case> cases = {
        {"leetcode", {"leet", "code"}, true},
        {"applepenapple", {"apple", "pen"}, true},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        vector<string> wordDict = c.wordDict;
        bool result = sol.wordBreak(c.s, wordDict);
        cout << "Input: s = \"" << c.s << "\", wordDict = ";
        printVector(c.wordDict);
        cout << "\nOutput: " << boolalpha << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
