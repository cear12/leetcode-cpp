class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int flips = 0, len = 0;
            for (int j = i; j < n && flips <= k; ++j) {
                if (nums[j] == 0) ++flips;
                if (flips > k) break;
                ++len;
            }
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};
// Временная сложность: O(n^2)
// Пространственная сложность: O(1)
