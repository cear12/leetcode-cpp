#include <deque>

#include "../../common/leetcode_common.h"

// BFS с std::deque
class Solution {
 public:
  int OrangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(),
        n = grid[0]
                .size();  // BUG FIX: was `grid.size()` -- see number-of-islands
                          // for the same row/column mixup on non-square grids
    deque<pair<int, int>> dq;
    int fresh = 0, time = 0;
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 2)
          dq.push_back({i, j});
        else if (grid[i][j] == 1)
          fresh++;
      }
    while (!dq.empty() && fresh) {
      int sz = dq.size();
      while (sz--) {
        auto [x, y] = dq.front();
        dq.pop_front();
        for (auto [dx, dy] : dirs) {
          int nx = x + dx, ny = y + dy;
          if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
            grid[nx][ny] = 2;
            fresh--;
            dq.push_back({nx, ny});
          }
        }
      }
      ++time;
    }
    return fresh ? -1 : time;
  }
};
// Время: O(m·n)  Память: O(m·n)

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
