#include "../../common/leetcode_common.h"

class Solution {
public:
    int SubarraySum(const std::vector<int>& nums, int k) {
        int ans = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (size_t j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) ++ans;
            }
        }
        return ans;
    }
};
// Временная сложность: O(n2)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums_; int k_; int expected_; };
    vector<Case> cases = {
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.SubarraySum(c.nums_, c.k_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << ", k = " << c.k_ << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
