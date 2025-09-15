// Жадный проход: отслеживаем максимальную достижимую позицию
class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) return false;
            maxReach = std::max(maxReach, i + nums[i]);
        }
        return true;
    }
};
// Временная сложность: O(n), один проход по массиву.
// Пространственная сложность: O(1), используется только maxReach.