#include "../../common/leetcode_common.h"

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left(n + 1, 0), right(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            left[i] = nums[i - 1] == 1 ? left[i - 1] + 1 : 0;
        for (int i = n - 1; i >= 0; --i)
            right[i] = nums[i] == 1 ? right[i + 1] + 1 : 0;
        int result = 0;
        for (int i = 0; i < n; ++i)
            result = std::max(result, left[i] + right[i + 1]);
        return result;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{1, 1, 0, 1}, 3},
        {{0, 1, 1, 1, 0, 1, 1, 0, 1}, 5},
        {{1, 1, 1}, 2},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.longestSubarray(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
