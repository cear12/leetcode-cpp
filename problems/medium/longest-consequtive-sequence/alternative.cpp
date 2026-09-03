#include "../../common/leetcode_common.h"

class Solution {
public:
    int LongestConsecutive(std::vector<int> nums) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());
        int maxlen = 1, cur = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] == nums[i-1] + 1) ++cur;
            else cur = 1;
            maxlen = std::max(maxlen, cur);
        }
        return maxlen;
    }
};

// Временная сложность: O(nlogn)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums_; int expected_; };
    vector<Case> cases = {
        {{100, 4, 200, 1, 3, 2}, 4},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
        {{1, 0, 1, 2}, 3},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.LongestConsecutive(c.nums_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
        bool ok = result == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
