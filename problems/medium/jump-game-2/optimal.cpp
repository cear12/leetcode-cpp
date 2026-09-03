#include "../../common/leetcode_common.h"

// Эффективное решение: Жадный проход
class Solution {
public:
    int jump(const std::vector<int>& nums) {
        int res = 0, farthest = 0, end = 0;
        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == end) {
                ++res;
                end = farthest;
            }
        }
        return res;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

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

