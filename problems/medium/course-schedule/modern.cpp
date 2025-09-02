#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites)
            adj[p[1]].push_back(p);
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
