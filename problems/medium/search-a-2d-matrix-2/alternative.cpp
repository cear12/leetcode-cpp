#include "../../common/leetcode_common.h"

// O(m log n) time, O(1) space
class Solution {
public:
    bool SearchMatrix(vector<vector<int>>& matrix, int target) {
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
    struct Case { int target_; bool expected_; };
    vector<Case> cases = {
        {5, true},
        {20, false},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        bool result = sol.SearchMatrix(matrix, c.target_);
        cout << "Input: target = " << c.target_
             << "\nOutput: " << boolalpha << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
