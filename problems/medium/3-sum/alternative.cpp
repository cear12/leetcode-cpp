#include "../../common/leetcode_common.h"

#include <set>  // not pulled in by the common header; this file needs std::set specifically

class Solution {
public:
    vector<vector<int>> ThreeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0)
                        triplets.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
        return vector<vector<int>>(triplets.begin(), triplets.end());
    }
};
// Временная сложность: O(n^3)
// Пространственная сложность: O(n)

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    auto result = sol.ThreeSum(nums);

    cout << "Input: nums = ";
    PrintVector(nums);
    cout << "\nOutput: ";
    PrintVector2D(result);
    cout << "\nExpected (any order): [[-1,-1,2],[-1,0,1]]\n";

    bool ok = result.size() == 2;
    cout << "[" << (ok ? "PASS" : "FAIL") << "] found " << result.size() << " triplet(s), expected 2\n";
    return ok ? 0 : 1;
}
