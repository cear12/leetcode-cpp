#include "../../common/leetcode_common.h"

class Solution {
public:
    bool WordBreak(string s, vector<string>& word_dict) {
        unordered_set<string> dict(word_dict.begin(), word_dict.end());
        queue<int> q; q.push(0);
        vector<bool> visited(s.size(), false);
        while (!q.empty()) {
            int start = q.front(); q.pop();
            if (visited[start]) continue;
            for (int end = start + 1; end <= static_cast<int>(s.size()); ++end) {
                if (dict.count(s.substr(start, end - start))) {
                    if (end == static_cast<int>(s.size())) return true;
                    q.push(end);
                }
            }
            visited[start] = true;
        }
        return false;
    }
};
// Временная сложность: O(n^2), память: O(n)

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
