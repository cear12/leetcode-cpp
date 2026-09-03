#include "../../common/leetcode_common.h"

namespace modern {

class UnionFind {
 private:
  vector<int> parent_;
  vector<int> rank_;
  int components_;

 public:
  UnionFind(int n) : parent_(n), rank_(n, 0), components_(0) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int Find(int x) {
    if (parent_[x] != x) {
      parent_[x] = Find(parent_[x]);  // Сжатие пути
    }
    return parent_[x];
  }

  void Unite(int x, int y) {
    int root_x = Find(x);
    int root_y = Find(y);

    if (root_x != root_y) {
      components_--;
      // Объединение по рангу
      if (rank_[root_x] < rank_[root_y]) {
        parent_[root_x] = root_y;
      } else if (rank_[root_x] > rank_[root_y]) {
        parent_[root_y] = root_x;
      } else {
        parent_[root_y] = root_x;
        rank_[root_x]++;
      }
    }
  }

  void AddComponent() { components_++; }

  int GetComponents() { return components_; }
};

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
    UnionFind uf(m * n);

    // Направления: вправо и вниз (достаточно для связывания всех компонентов)
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}};

    // Сначала добавляем все острова как отдельные компоненты
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          uf.AddComponent();
        }
      }
    }

    // Объединяем смежные острова
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          int current_id = i * n + j;

          for (const auto& [di, dj] : directions) {
            int ni = i + di;
            int nj = j + dj;

            if (ni < m && nj < n && grid[ni][nj] == '1') {
              int neighbor_id = ni * n + nj;
              uf.Unite(current_id, neighbor_id);
            }
          }
        }
      }
    }

    return uf.GetComponents();
  }
};

}  // namespace modern

/*
Временная сложность: O(M × N × α(M × N)) ≈ O(M × N) - α - обратная функция
Аккермана Пространственная сложность: O(M × N) - для структуры Union-Find

Преимущества:
- Использует эффективную структуру данных Union-Find
- Демонстрирует продвинутые алгоритмические концепции
- Подходит для задач с динамическими запросами на связность

Недостатки:
- Более сложная реализация
- Больше памяти для хранения структуры
- Избыточен для данной конкретной задачи
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
  modern::Solution sol;
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
