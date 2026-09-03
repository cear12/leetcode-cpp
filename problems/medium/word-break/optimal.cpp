#include "../../common/leetcode_common.h"

class Solution {
public:
    bool WordBreak(string s, vector<string>& word_dict) {
        unordered_set<string> dict(word_dict.begin(), word_dict.end());
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
    struct Case { string s_; vector<string> word_dict_; bool expected_; };
    vector<Case> cases = {
        {"leetcode", {"leet", "code"}, true},
        {"applepenapple", {"apple", "pen"}, true},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        vector<string> word_dict = c.word_dict_;
        bool result = sol.WordBreak(c.s_, word_dict);
        cout << "Input: s = \"" << c.s_ << "\", wordDict = ";
        PrintVector(c.word_dict_);
        cout << "\nOutput: " << boolalpha << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
