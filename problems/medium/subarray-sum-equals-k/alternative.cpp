#include <vector>

class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k) {
        int ans = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (size_t j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) ++ans;
            }
        }
        return ans;
    }
};
// Временная сложность: O(n2)
// Пространственная сложность: O(1)
