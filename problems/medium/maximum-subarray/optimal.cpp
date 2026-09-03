#include "../../common/leetcode_common.h"

class Solution {
public:
    int MaxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            current = max(nums[i], current + nums[i]);
            max_sum = max(max_sum, current);
        }
        return max_sum;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums_; int expected_; };
    vector<Case> cases = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.MaxSubArray(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
