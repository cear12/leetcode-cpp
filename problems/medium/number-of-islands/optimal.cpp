#include <vector>

using namespace std;

namespace optimal
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

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Проверка границ и условия остановки
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }

        // Помечаем ячейку как посещенную
        grid[i][j] = '0';

        // Рекурсивно обходим все 4 направления
        dfs(grid, i + 1, j, m, n);  // вниз
        dfs(grid, i - 1, j, m, n);  // вверх
        dfs(grid, i, j + 1, m, n);  // вправо
        dfs(grid, i, j - 1, m, n);  // влево
    }
};

} // optimal

/*
Временная сложность: O(M × N) - в худшем случае посещаем каждую ячейку один раз
Пространственная сложность: O(M × N) - для стека рекурсии в худшем случае (весь остров)

Преимущества:
- Простая и интуитивная реализация
- Минимальное использование дополнительной памяти
- Изменяет исходную матрицу для экономии памяти

Недостатки:
- Может привести к переполнению стека при глубокой рекурсии
- Изменяет исходные данные
*/
