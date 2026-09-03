#include "../../common/leetcode_common.h"

class Solution {
public:
    void Rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer, last = n - 1 - layer;
            for (int i = first; i < last; ++i) {
                int offset = i - first;
                int top = matrix[first][i];
                matrix[first][i] = matrix[last - offset][first];
                matrix[last - offset][first] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = top;
            }
        }
    }
};
// Время: O(n^2)
// Память: O(1)

int main() {
    struct Case { vector<vector<int>> matrix_; vector<vector<int>> expected_; };
    vector<Case> cases = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
        {{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
         {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        vector<vector<int>> matrix = c.matrix_;
        sol.Rotate(matrix);
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
