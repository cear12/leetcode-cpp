#include "../../common/leetcode_common.h"

// Решение 1: Границы обхода
class Solution {
public:
    vector<int> SpiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
            ++top;
            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            --right;
            if (top <= bottom)
                for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
            --bottom;
            if (left <= right)
                for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
            ++left;
        }
        return res;
    }
};
// Временная сложность: O(m * n)
// Пространственная сложность: O(1), не считая ответа

int main() {
    struct Case { vector<vector<int>> matrix_; vector<int> expected_; };
    vector<Case> cases = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}},
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        vector<vector<int>> matrix = c.matrix_;
        auto result = sol.SpiralOrder(matrix);
        cout << "Input: matrix = ";
        PrintVector2D(c.matrix_);
        cout << "\nOutput: ";
        PrintVector(result);
        cout << " -- expected ";
        PrintVector(c.expected_);
        cout << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
