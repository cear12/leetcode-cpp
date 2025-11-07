class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, zeros = 0, maxlen = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zeros;
            while (zeros > 1)
                if (nums[left++] == 0)
                    --zeros;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
