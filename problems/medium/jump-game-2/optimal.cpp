#include "../../common/leetcode_common.h"

// Эффективное решение: Жадный проход
class Solution {
public:
    int Jump(const std::vector<int>& nums) {
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
    struct Case { vector<int> nums_; int expected_; };
    vector<Case> cases = {
        {{2, 3, 1, 1, 4}, 2},
        {{2, 3, 0, 1, 4}, 2},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.Jump(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}

