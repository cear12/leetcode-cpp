#include "../../common/leetcode_common.h"

// Эффективное in-place решение, использующее первую строку и столбец в качестве маркеров
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();      // Количество строк
    int n = matrix[0].size();   // Количество столбцов
    bool col0 = false;          // Нужно ли обнулять первый столбец

    // Первый проход: отмечаем строки и столбцы, которые нужно обнулить
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) col0 = true;   // Есть ли ноль в первом столбце
        for (int j = 1; j < n; ++j)
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Отметить строку для обнуления
                matrix[0][j] = 0; // Отметить столбец для обнуления
            }
    }
    // Второй проход: идём в обратном порядке, обнуляем по маркерам
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 1; --j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0) matrix[i][0] = 0;
    }
}
/*
Временная сложность: O(m*n)
Пространственная сложность: O(1)
*/

int main() {
    struct Case { vector<vector<int>> matrix; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
        {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}, {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}},
    };

    bool allOk = true;
    for (auto c : cases) {
        vector<vector<int>> matrix = c.matrix;
        setZeroes(matrix);
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
