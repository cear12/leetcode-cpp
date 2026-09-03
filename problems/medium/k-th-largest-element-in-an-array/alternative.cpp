#include "../../common/leetcode_common.h"

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// Временная сложность: O(nlogn)
// Пространственная сложность: O(1) 

int main() {
    struct Case { vector<int> nums; int k; int expected; };
    vector<Case> cases = {
        {{3, 2, 1, 5, 6, 4}, 2, 5},
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},
    };

    bool allOk = true;
    for (auto c : cases) {
        vector<int> nums = c.nums;
        Solution sol;
        int result = sol.findKthLargest(nums, c.k);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << ", k = " << c.k << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
