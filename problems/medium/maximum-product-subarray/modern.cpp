#include "../../common/leetcode_common.h"

// Time: O(n), Space: O(n)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDP(n), minDP(n);
        maxDP[0] = minDP[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            maxDP[i] = max({nums[i], nums[i] * maxDP[i - 1], nums[i] * minDP[i - 1]});
            minDP[i] = min({nums[i], nums[i] * maxDP[i - 1], nums[i] * minDP[i - 1]});
            ans = max(ans, maxDP[i]);
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
