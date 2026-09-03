#include "../../common/leetcode_common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        int leftProd = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = leftProd;
            leftProd *= nums[i];
        }

        int rightProd = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= rightProd;
            rightProd *= nums[i];
        }

        return answer;
    }
};
// Время: O(n)
// Память: O(1)

// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4}, {24, 12, 8, 6}},
        {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        auto result = sol.productExceptSelf(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: ";
        printVector(result);
        cout << " -- expected ";
        printVector(c.expected);
        cout << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
