#include "../../common/leetcode_common.h"

class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int maxlen = 0;
        for (int x : s) {
            if (!s.count(x - 1)) {
                int y = x + 1;
                while (s.count(y)) ++y;
                maxlen = std::max(maxlen, y - x);
            }
        }
        return maxlen;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

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
