#include "../../common/leetcode_common.h"

// Time: O(n), Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], maxProd = nums[0], minProd = nums[0];
        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] < 0) swap(maxProd, minProd);
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};

int main() {
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{2, 3, -2, 4}, 6},
        {{-2, 0, -1}, 0},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.maxProduct(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
