#include <vector>
#include <numeric>

using namespace std;

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
        if (grid.empty() || grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid.size();
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
