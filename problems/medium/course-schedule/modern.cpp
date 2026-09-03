#include "../../common/leetcode_common.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // BUG FIX: this pushed the whole pair `p` (a vector<int>) instead of
        // just the prerequisite course id p[0] -- p[1] "unlocks" p[0], so the
        // adjacency list edge is p[1] -> p[0].
        for (auto& p : prerequisites)
            adj[p[1]].push_back(p[0]);
        vector<int> state(numCourses, 0);
        stack<int> s;
        for (int i = 0; i < numCourses; ++i)
            if (dfs(i, adj, state)) return false;
        return true;
    }
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;
        if (state[node] == 2) return false;
        state[node] = 1;
        for (int next : adj[node])
            if (dfs(next, adj, state)) return true;
        state[node] = 2;
        return false;
    }
};
// Время: O(N+E), Память: O(N+E)

int main() {
    Solution sol1;
    vector<vector<int>> prereq1 = {{1, 0}};
    bool result1 = sol1.canFinish(2, prereq1);
    cout << "Input: numCourses = 2, prerequisites = [[1,0]]\n";
    cout << "Output: " << boolalpha << result1 << " -- expected true\n";

    Solution sol2;
    vector<vector<int>> prereq2 = {{1, 0}, {0, 1}};
    bool result2 = sol2.canFinish(2, prereq2);
    cout << "Input: numCourses = 2, prerequisites = [[1,0],[0,1]]\n";
    cout << "Output: " << result2 << " -- expected false\n";

    bool ok = result1 == true && result2 == false;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
