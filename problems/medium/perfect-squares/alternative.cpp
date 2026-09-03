#include "../../common/leetcode_common.h"

class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(n); visited[n] = true;
        int level = 0;
        while (!q.empty()) {
            int sz = q.size(); level++;
            for (int i = 0; i < sz; ++i) {
                int num = q.front(); q.pop();
                for (int j = 1; j * j <= num; ++j) {
                    int next = num - j*j;
                    if (next == 0) return level;
                    if (!visited[next]) {
                        q.push(next); visited[next] = true;
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    struct Case { int n; int expected; };
    vector<Case> cases = {
        {12, 3},
        {13, 2},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.numSquares(c.n);
        cout << "Input: n = " << c.n << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
