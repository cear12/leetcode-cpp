#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> cnt{{0, 1}};
        int sum = 0, ans = 0;
        for (auto x : nums) {
            sum += x;
            ans += cnt[sum - k];
            cnt[sum]++;
        }
        return ans;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)
