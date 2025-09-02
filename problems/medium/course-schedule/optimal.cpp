#include <vector>
#include <queue>

using namespace std;

// BFS (топологическая сортировка — Kahn’s Algorithm)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            ++indegree[pre[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) q.push(i);

        int finished = 0;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            ++finished;
            for (int next : graph[course])
                if (--indegree[next] == 0)
                    q.push(next);
        }
        return finished == numCourses; // если обработали все - граф ацикличен
    }
};
// Время: O(N+E), Память: O(N+E)
