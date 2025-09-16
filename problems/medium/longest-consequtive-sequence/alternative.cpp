#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int> nums) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());
        int maxlen = 1, cur = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] == nums[i-1] + 1) ++cur;
            else cur = 1;
            maxlen = std::max(maxlen, cur);
        }
        return maxlen;
    }
};

// Временная сложность: O(nlogn)
// Пространственная сложность: O(1)
