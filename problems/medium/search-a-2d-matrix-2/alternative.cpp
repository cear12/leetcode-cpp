#include "../../common/leetcode_common.h"

// O(m log n) time, O(1) space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            int l = 0, r = row.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (row[mid] == target) return true;
                else if (row[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
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
