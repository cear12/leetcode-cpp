#include "../../common/leetcode_common.h"

// BFS (топологическая сортировка — Kahn’s Algorithm)
class Solution {
 public:
  bool CanFinish(int num_courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(num_courses);
    vector<int> indegree(num_courses, 0);
    for (auto& pre : prerequisites) {
      graph[pre[1]].push_back(pre[0]);
      ++indegree[pre[0]];
    }
    queue<int> q;
    for (int i = 0; i < num_courses; ++i)
      if (indegree[i] == 0) q.push(i);

    int finished = 0;
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      ++finished;
      for (int next : graph[course])
        if (--indegree[next] == 0) q.push(next);
    }
    return finished == num_courses;  // если обработали все - граф ацикличен
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
