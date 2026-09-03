#include "../../common/leetcode_common.h"

// Используются дополнительные массивы для запоминания строк и столбцов с нулями
void SetZeroes(vector<vector<int>>& matrix) {
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
int main() {
    struct Case { vector<vector<int>> matrix_; vector<vector<int>> expected_; };
    vector<Case> cases = {
        {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
        {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}},
    };

    bool all_ok = true;
    for (auto c : cases) {
        vector<vector<int>> matrix = c.matrix_;
        SetZeroes(matrix);
        cout << "Input: matrix = ";
        PrintVector2D(c.matrix_);
        cout << "\nOutput: ";
        PrintVector2D(matrix);
        cout << " -- expected ";
        PrintVector2D(c.expected_);
        cout << "\n";
        bool ok = matrix == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
