#include "../../common/leetcode_common.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, zeros = 0, maxlen = 0;
        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            if (nums[right] == 0) ++zeros;
            while (zeros > 1)
                if (nums[left++] == 0)
                    --zeros;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
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
