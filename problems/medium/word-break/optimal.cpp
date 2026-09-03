#include "../../common/leetcode_common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// Временная сложность: O(n^2 * k) (n — длина строки, k — макс. длина слова)
// Пространственная сложность: O(n + m)

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
