#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int maxlen = 0;
        for (int x : s) {
            if (!s.count(x - 1)) {
                int y = x + 1;
                while (s.count(y)) ++y;
                maxlen = std::max(maxlen, y - x);
            }
        }
        return maxlen;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)
