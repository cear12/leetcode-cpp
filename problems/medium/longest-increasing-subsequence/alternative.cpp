#include "../../common/leetcode_common.h"

class Solution {
public:
    int LengthOfLis(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_len = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
// Временная сложность: O(n²)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> nums_; int expected_; };
    vector<Case> cases = {
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.LengthOfLis(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
