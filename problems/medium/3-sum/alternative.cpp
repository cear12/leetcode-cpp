class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
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
