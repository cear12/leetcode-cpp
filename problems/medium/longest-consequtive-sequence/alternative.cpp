#include "../../common/leetcode_common.h"

class Solution {
public:
    int longestConsecutive(std::vector<int> nums) {
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
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{100, 4, 200, 1, 3, 2}, 4},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
        {{1, 0, 1, 2}, 3},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.longestConsecutive(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
