// Эффективное решение: Жадный проход
class Solution {
public:
    int jump(const std::vector<int>& nums) {
        int res = 0, farthest = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);
            if (i == end) {
                ++res;
                end = farthest;
            }
        }
        return res;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
