#include "../../common/leetcode_common.h"

class Solution {
public:
    bool CanFinish(int num_courses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(num_courses);
        // BUG FIX: this pushed the whole pair `p` (a vector<int>) instead of
        // just the prerequisite course id p[0] -- p[1] "unlocks" p[0], so the
        // adjacency list edge is p[1] -> p[0].
        for (auto& p : prerequisites)
            adj[p[1]].push_back(p[0]);
        vector<int> state(num_courses, 0);
        stack<int> s;
        for (int i = 0; i < num_courses; ++i)
            if (Dfs(i, adj, state)) return false;
        return true;
    }
private:
    bool Dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;
        if (state[node] == 2) return false;
        state[node] = 1;
        for (int next : adj[node])
            if (Dfs(next, adj, state)) return true;
        state[node] = 2;
        return false;
    }
};
// Время: O(N+E), Память: O(N+E)

int main() {
    Solution sol1;
    vector<vector<int>> prereq1 = {{1, 0}};
    bool result1 = sol1.CanFinish(2, prereq1);
    cout << "Input: num_courses = 2, prerequisites = [[1,0]]\n";
    cout << "Output: " << boolalpha << result1 << " -- expected true\n";

    Solution sol2;
    vector<vector<int>> prereq2 = {{1, 0}, {0, 1}};
    bool result2 = sol2.CanFinish(2, prereq2);
    cout << "Input: num_courses = 2, prerequisites = [[1,0],[0,1]]\n";
    cout << "Output: " << result2 << " -- expected false\n";

    bool ok = result1 == true && result2 == false;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
