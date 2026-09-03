#include "../../common/leetcode_common.h"

// Жадный проход: отслеживаем максимальную достижимую позицию
class Solution {
public:
    bool CanJump(const std::vector<int>& nums) {
        int max_reach = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i > max_reach) return false;
            max_reach = std::max(max_reach, i + nums[i]);
        }
        return true;
    }
};
// Временная сложность: O(n), один проход по массиву.
// Пространственная сложность: O(1), используется только max_reach.
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

