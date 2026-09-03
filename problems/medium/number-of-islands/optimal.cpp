#include "../../common/leetcode_common.h"

namespace optimal {

class Solution {
 public:
  int NumIslands(vector<vector<char>>& grid) {
    if (grid.empty() ||
        grid[0].empty()) {  // BUG FIX: was `grid.empty() || grid.empty()`
                            // (checked the same thing twice)
      return 0;
    }

    int m = grid.size();
    int n = grid[0].size();  // BUG FIX: was `grid.size()` -- used row count as
                             // the column bound, which silently truncated
                             // non-square grids (or read out of bounds when
                             // there were more rows than columns)
    int islands = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          islands++;
          Dfs(grid, i, j, m, n);
        }
      }
    }

    return islands;
  }

 private:
  void Dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    // Проверка границ и условия остановки
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
      return;
    }

    // Помечаем ячейку как посещенную
    grid[i][j] = '0';

    // Рекурсивно обходим все 4 направления
    Dfs(grid, i + 1, j, m, n);  // вниз
    Dfs(grid, i - 1, j, m, n);  // вверх
    Dfs(grid, i, j + 1, m, n);  // вправо
    Dfs(grid, i, j - 1, m, n);  // влево
  }
};

}  // namespace optimal

/*
Временная сложность: O(M × N) - в худшем случае посещаем каждую ячейку один раз
Пространственная сложность: O(M × N) - для стека рекурсии в худшем случае (весь
остров)

Преимущества:
- Простая и интуитивная реализация
- Минимальное использование дополнительной памяти
- Изменяет исходную матрицу для экономии памяти

Недостатки:
- Может привести к переполнению стека при глубокой рекурсии
- Изменяет исходные данные
*/

int main() {
  struct Case {
    vector<vector<char>> grid_;
    int expected_;
  };
  vector<Case> cases = {
      {{{'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}},
       1},
      {{{'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}},
       3},
      // Non-square grid (more columns than rows): regression test for a
      // real bug where the column bound was computed as grid.size()
      // (row count) instead of grid[0].size(), silently truncating the
      // scan and missing the isolated '1' at (1,2).
      {{{'1', '0', '0'}, {'0', '0', '1'}}, 2},
  };

  bool all_ok = true;
  optimal::Solution sol;
  for (auto c : cases) {
    vector<vector<char>> grid = c.grid_;
    int result = sol.NumIslands(grid);
    cout << "Input: grid = ";
    PrintVector2D(c.grid_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
