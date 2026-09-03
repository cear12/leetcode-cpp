#include "../../common/leetcode_common.h"

class Solution {
public:
    void Rotate(vector<int>& nums, int k) {
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
    struct Case { vector<int> nums_; int k_; vector<int> expected_; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
        {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        vector<int> nums = c.nums_;
        sol.Rotate(nums, c.k_);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << ", k = " << c.k_ << "\nOutput: ";
        PrintVector(nums);
        cout << " -- expected ";
        PrintVector(c.expected_);
        cout << "\n";
        bool ok = nums == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
