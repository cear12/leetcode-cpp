#include <queue>
#include <unordered_set>
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> q; q.push(0);
        vector<bool> visited(s.size(), false);
        while (!q.empty()) {
            int start = q.front(); q.pop();
            if (visited[start]) continue;
            for (int end = start + 1; end <= s.size(); ++end) {
                if (dict.count(s.substr(start, end - start))) {
                    if (end == s.size()) return true;
                    q.push(end);
                }
            }
            visited[start] = true;
        }
        return false;
    }
};
// Временная сложность: O(n^2), память: O(n)
