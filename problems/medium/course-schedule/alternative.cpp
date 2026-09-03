#include "../../common/leetcode_common.h"

// DFS (поиск цикла)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites)
            adj[p[1]].push_back(p[0]);
        vector<int> state(numCourses, 0); // 0: WHITE, 1: GRAY, 2: BLACK
        for (int i = 0; i < numCourses; ++i)
            if (state[i] == 0 && hasCycle(adj, state, i)) return false;
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& state, int curr) {
        state[curr] = 1;
        for (int next : adj[curr]) {
            if (state[next] == 1) return true;
            if (state[next] == 0 && hasCycle(adj, state, next)) return true;
        }
        state[curr] = 2;
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
