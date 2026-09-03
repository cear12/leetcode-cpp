#include "../../common/leetcode_common.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums; int k; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
        {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        vector<int> nums = c.nums;
        sol.rotate(nums, c.k);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << ", k = " << c.k << "\nOutput: ";
        printVector(nums);
        cout << " -- expected ";
        printVector(c.expected);
        cout << "\n";
        bool ok = nums == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
