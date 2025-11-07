class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev = -1, curr = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                curr = i - prev;
                prev = i;
            } else {
                ++curr;
            }
            res = max(res, curr);
        }
        return res > nums.size() ? nums.size() : res;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
