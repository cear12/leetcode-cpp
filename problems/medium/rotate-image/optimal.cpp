#include "../../common/leetcode_common.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Транспонируем матрицу (отражаем относительно главной диагонали)
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);

        // Разворачиваем каждую строку для поворота
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
// Время: O(n^2)
// Память: O(1)
int main() {
    struct Case { vector<vector<int>> matrix; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
        {{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
         {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        vector<vector<int>> matrix = c.matrix;
        sol.rotate(matrix);
        cout << "Input: matrix = ";
        printVector2D(c.matrix);
        cout << "\nOutput: ";
        printVector2D(matrix);
        cout << " -- expected ";
        printVector2D(c.expected);
        cout << "\n";
        bool ok = matrix == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
