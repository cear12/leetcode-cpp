#include "../../common/leetcode_common.h"

class Solution {
public:
    void NextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Шаг 1: находим первую позицию i справа, где nums[i] < nums[i + 1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        // Шаг 2: если нашли такую позицию i, ищем ближайший справа элемент j, который больше nums[i]
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        // Шаг 3: переворачиваем "хвост" справа от позиции i
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums_; vector<int> expected_; };
    vector<Case> cases = {
        {{1, 2, 3}, {1, 3, 2}},
        {{3, 2, 1}, {1, 2, 3}},
        {{1, 1, 5}, {1, 5, 1}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        vector<int> nums = c.nums_;
        sol.NextPermutation(nums);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: ";
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
