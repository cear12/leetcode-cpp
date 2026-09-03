#include "../../common/leetcode_common.h"

class Solution {
public:
    int FindKthLargest(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// Временная сложность: O(nlogn)
// Пространственная сложность: O(1) 

int main() {
    struct Case { vector<int> nums_; int k_; int expected_; };
    vector<Case> cases = {
        {{3, 2, 1, 5, 6, 4}, 2, 5},
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},
    };

    bool all_ok = true;
    for (auto c : cases) {
        vector<int> nums = c.nums_;
        Solution sol;
        int result = sol.FindKthLargest(nums, c.k_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << ", k = " << c.k_ << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
