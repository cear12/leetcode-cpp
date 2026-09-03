#include "../../common/leetcode_common.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // пропускаем дубликаты
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left; --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    auto result = sol.threeSum(nums);

    cout << "Input: nums = ";
    printVector(nums);
    cout << "\nOutput: ";
    printVector2D(result);
    cout << "\nExpected (any order): [[-1,-1,2],[-1,0,1]]\n";

    bool ok = result.size() == 2;
    cout << "[" << (ok ? "PASS" : "FAIL") << "] found " << result.size() << " triplet(s), expected 2\n";
    return ok ? 0 : 1;
}
