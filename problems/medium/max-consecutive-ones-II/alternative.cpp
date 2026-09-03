#include "../../common/leetcode_common.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
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
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{1, 0, 1, 1, 0}, 4},
        {{1, 0, 1, 1, 0, 1}, 4},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.findMaxConsecutiveOnes(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
