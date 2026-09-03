#include "../../common/leetcode_common.h"

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int flips = 0, len = 0;
            for (int j = i; j < n && flips <= k; ++j) {
                if (nums[j] == 0) ++flips;
                if (flips > k) break;
                ++len;
            }
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums; int k; int expected; };
    vector<Case> cases = {
        {{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6},
        {{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.longestOnes(c.nums, c.k);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << ", k = " << c.k << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
