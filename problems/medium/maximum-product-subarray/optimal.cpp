#include "../../common/leetcode_common.h"

// Time: O(n), Space: O(1)

class Solution {
public:
    int MaxProduct(vector<int>& nums) {
        int ans = nums[0], max_prod = nums[0], min_prod = nums[0];
        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] < 0) swap(max_prod, min_prod);
            max_prod = max(nums[i], max_prod * nums[i]);
            min_prod = min(nums[i], min_prod * nums[i]);
            ans = max(ans, max_prod);
        }
        return ans;
    }
};

int main() {
    struct Case { vector<int> nums_; int expected_; };
    vector<Case> cases = {
        {{2, 3, -2, 4}, 6},
        {{-2, 0, -1}, 0},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.MaxProduct(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
