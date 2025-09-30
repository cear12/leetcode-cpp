#include <vector>
using namespace std;

// Используются дополнительные массивы для запоминания строк и столбцов с нулями
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> row(m, false), col(n, false);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] == 0)
                row[i] = col[j] = true;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (row[i] || col[j])
                matrix[i][j] = 0;
}
/*
Временная сложность: O(m*n)
Пространственная сложность: O(m+n)
*/