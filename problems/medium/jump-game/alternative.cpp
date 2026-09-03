#include "../../common/leetcode_common.h"

// Проход с конца: сдвигаем "цель" до достижимых позиций
class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= goal) goal = i;
        }
        return goal == 0;
    }
};
// Временная сложность: O(n) 
// Пространственная сложность: O(1) 
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

