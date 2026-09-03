#include "../../common/leetcode_common.h"

namespace modern
{

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int components;

public:
    UnionFind(int n) : parent(n), rank(n, 0), components(0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Сжатие пути
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            components--;
            // Объединение по рангу
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    void addComponent() {
        components++;
    }

    int getComponents() {
        return components;
    }
};

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
        UnionFind uf(m * n);

        // Направления: вправо и вниз (достаточно для связывания всех компонентов)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}};

        // Сначала добавляем все острова как отдельные компоненты
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    uf.addComponent();
                }
            }
        }

        // Объединяем смежные острова
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int currentId = i * n + j;

                    for (const auto& [di, dj] : directions) {
                        int ni = i + di;
                        int nj = j + dj;

                        if (ni < m && nj < n && grid[ni][nj] == '1') {
                            int neighborId = ni * n + nj;
                            uf.unite(currentId, neighborId);
                        }
                    }
                }
            }
        }

        return uf.getComponents();
    }
};

} // modern

/*
Временная сложность: O(M × N × α(M × N)) ≈ O(M × N) - α - обратная функция Аккермана
Пространственная сложность: O(M × N) - для структуры Union-Find

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
    modern::Solution sol;
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
