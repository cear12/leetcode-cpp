#include <vector>
#include <queue>

using namespace std;

namespace alternative
{

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid.size();
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
