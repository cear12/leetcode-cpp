class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left(n + 1, 0), right(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            left[i] = nums[i - 1] == 1 ? left[i - 1] + 1 : 0;
        for (int i = n - 1; i >= 0; --i)
            right[i] = nums[i] == 1 ? right[i + 1] + 1 : 0;
        int result = 0;
        for (int i = 0; i < n; ++i)
            result = std::max(result, left[i] + right[i + 1]);
        return result;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)
