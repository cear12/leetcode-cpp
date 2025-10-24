class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int current = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            current = max(nums[i], current + nums[i]);
            maxSum = max(maxSum, current);
        }
        return maxSum;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
