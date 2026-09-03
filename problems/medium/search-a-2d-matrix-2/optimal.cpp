#include "../../common/leetcode_common.h"

// O(m + n) time, O(1) space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) --j;
            else ++i;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    struct Case { int target; bool expected; };
    vector<Case> cases = {
        {5, true},
        {20, false},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        bool result = sol.searchMatrix(matrix, c.target);
        cout << "Input: target = " << c.target
             << "\nOutput: " << boolalpha << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
