#include "../../common/leetcode_common.h"

// Жадный проход: отслеживаем максимальную достижимую позицию
class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i > maxReach) return false;
            maxReach = std::max(maxReach, i + nums[i]);
        }
        return true;
    }
};
// Временная сложность: O(n), один проход по массиву.
// Пространственная сложность: O(1), используется только maxReach.
int main() {
    struct Case { vector<int> nums; bool expected; };
    vector<Case> cases = {
        {{2, 3, 1, 1, 4}, true},
        {{3, 2, 1, 0, 4}, false},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        bool result = sol.canJump(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << boolalpha << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}

