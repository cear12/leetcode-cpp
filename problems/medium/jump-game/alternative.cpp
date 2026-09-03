#include "../../common/leetcode_common.h"

// Проход с конца: сдвигаем "цель" до достижимых позиций
class Solution {
public:
    bool CanJump(const std::vector<int>& nums) {
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
    struct Case { vector<int> nums_; bool expected_; };
    vector<Case> cases = {
        {{2, 3, 1, 1, 4}, true},
        {{3, 2, 1, 0, 4}, false},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        bool result = sol.CanJump(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << boolalpha << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}

