#include "../../common/leetcode_common.h"

// DFS (медленнее, но наглядно)
class Solution {
  int m_, n_;
  vector<pair<int, int>> dirs_{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 public:
  int OrangesRotting(vector<vector<int>>& grid) {
    m_ = grid.size();
    n_ = grid[0].size();  // BUG FIX: was `grid.size()` -- see number-of-islands
                          // for the same row/column mixup on non-square grids
    int max_time = 0;
    for (int i = 0; i < m_; ++i)
      for (int j = 0; j < n_; ++j)
        if (grid[i][j] == 2) Dfs(grid, i, j, 0, max_time);
    for (int i = 0; i < m_; ++i)
      for (int j = 0; j < n_; ++j)
        if (grid[i][j] == 1) return -1;
    return max_time;
  }

 private:
  void Dfs(vector<vector<int>>& g, int x, int y, int time, int& max_time) {
    max_time = max(max_time, time);
    for (auto [dx, dy] : dirs_) {
      int nx = x + dx, ny = y + dy;
      if (nx >= 0 && nx < m_ && ny >= 0 && ny < n_ && g[nx][ny] == 1) {
        g[nx][ny] = 2;
        Dfs(g, nx, ny, time + 1, max_time);
      }
    }
  }
};
// Время: O((m·n)²)  Память: O(m·n)

int main() {
  struct Case {
    vector<vector<int>> grid_;
    int expected_;
  };
  vector<Case> cases = {
      {{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4},
      {{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1},
      {{{0, 2}}, 0},
      // Non-square grid (1 row, 3 columns): regression test for the same
      // row/column mixup bug fixed in number-of-islands -- the column
      // bound used to be computed as grid.size() (row count = 1) instead
      // of grid[0].size() (col count = 3), so the two fresh oranges past
      // column 0 were never scanned.
      {{{2, 1, 1}}, 2},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    vector<vector<int>> grid = c.grid_;
    int result = sol.OrangesRotting(grid);
    cout << "Input: grid = ";
    PrintVector2D(c.grid_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
