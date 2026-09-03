#include "../../common/leetcode_common.h"

namespace alternative
{

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {  // BUG FIX: was `grid.empty() || grid.empty()` (checked the same thing twice)
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();  // BUG FIX: was `grid.size()` -- used row count as the column bound,
                                  // which silently truncated non-square grids (or read out of bounds
                                  // when there were more rows than columns)
        int islands = 0;

        // Направления для движения: вверх, вправо, вниз, влево
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs(grid, i, j, m, n, directions);
                }
            }
        }

        return islands;
    }

private:
    void bfs(vector<vector<char>>& grid, int startI, int startJ, int m, int n,
             const vector<pair<int, int>>& directions) {
        queue<pair<int, int>> q;
        q.push({startI, startJ});
        grid[startI][startJ] = '0';  // Помечаем как посещенную

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            // Проверяем все 4 направления
            for (const auto& [di, dj] : directions) {
                int ni = i + di;
                int nj = j + dj;

                // Проверка границ и условия
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                    grid[ni][nj] = '0';  // Помечаем как посещенную
                    q.push({ni, nj});
                }
            }
        }
    }
};

} // alternative

/*
Временная сложность: O(M × N) - каждая ячейка посещается максимум один раз
Пространственная сложность: O(min(M, N)) - в худшем случае очередь содержит все ячейки границы острова

Преимущества:
- Избегает переполнения стека
- Итеративный подход более предсказуем по использованию памяти
- Хорошо работает с большими островами

Недостатки:
- Требует дополнительную память для очереди
- Немного более сложная реализация
*/

int main() {
    struct Case { vector<vector<char>> grid; int expected; };
    vector<Case> cases = {
        {{{'1','1','1','1','0'},
           {'1','1','0','1','0'},
           {'1','1','0','0','0'},
           {'0','0','0','0','0'}}, 1},
        {{{'1','1','0','0','0'},
           {'1','1','0','0','0'},
           {'0','0','1','0','0'},
           {'0','0','0','1','1'}}, 3},
        // Non-square grid (more columns than rows): regression test for a
        // real bug where the column bound was computed as grid.size()
        // (row count) instead of grid[0].size(), silently truncating the
        // scan and missing the isolated '1' at (1,2).
        {{{'1','0','0'},
           {'0','0','1'}}, 2},
    };

    bool allOk = true;
    alternative::Solution sol;
    for (auto c : cases) {
        vector<vector<char>> grid = c.grid;
        int result = sol.numIslands(grid);
        cout << "Input: grid = ";
        printVector2D(c.grid);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
