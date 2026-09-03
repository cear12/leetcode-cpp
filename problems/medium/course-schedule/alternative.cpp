#include "../../common/leetcode_common.h"

// DFS (поиск цикла)
class Solution {
 public:
  bool CanFinish(int num_courses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(num_courses);
    for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);
    vector<int> state(num_courses, 0);  // 0: WHITE, 1: GRAY, 2: BLACK
    for (int i = 0; i < num_courses; ++i)
      if (state[i] == 0 && HasCycle(adj, state, i)) return false;
    return true;
  }

 private:
  bool HasCycle(vector<vector<int>>& adj, vector<int>& state, int curr) {
    state[curr] = 1;
    for (int next : adj[curr]) {
      if (state[next] == 1) return true;
      if (state[next] == 0 && HasCycle(adj, state, next)) return true;
    }
    state[curr] = 2;
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
