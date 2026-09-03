#include "../../common/leetcode_common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.maxSubArray(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
