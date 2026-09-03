#include "../../common/leetcode_common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
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
