#include "../../common/leetcode_common.h"

class Solution {
public:
    int FindMaxConsecutiveOnes(vector<int>& nums) {
        int prev = -1, curr = 0, res = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] == 0) {
                curr = i - prev;
                prev = i;
            } else {
                ++curr;
            }
            res = max(res, curr);
        }
        return res > static_cast<int>(nums.size()) ? static_cast<int>(nums.size()) : res;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums_; int expected_; };
    vector<Case> cases = {
        {{1, 0, 1, 1, 0}, 4},
        {{1, 0, 1, 1, 0, 1}, 4},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.FindMaxConsecutiveOnes(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
