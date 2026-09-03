#include "../../common/leetcode_common.h"

class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> cnt{{0, 1}};
        int sum = 0, ans = 0;
        for (auto x : nums) {
            sum += x;
            ans += cnt[sum - k];
            cnt[sum]++;
        }
        return ans;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> nums; int k; int expected; };
    vector<Case> cases = {
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.subarraySum(c.nums, c.k);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << ", k = " << c.k << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
