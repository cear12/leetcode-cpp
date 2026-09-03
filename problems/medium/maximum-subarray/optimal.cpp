#include "../../common/leetcode_common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int current = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            current = max(nums[i], current + nums[i]);
            maxSum = max(maxSum, current);
        }
        return maxSum;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

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
