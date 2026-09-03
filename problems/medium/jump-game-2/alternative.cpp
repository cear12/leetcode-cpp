#include "../../common/leetcode_common.h"

// Альтернативное решение: Динамическое программирование
class Solution {
public:
    int jump(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i && dp[j] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};
// Временная сложность: O(n2)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{2, 3, 1, 1, 4}, 2},
        {{2, 3, 0, 1, 4}, 2},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.jump(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}

