// Проход с конца: сдвигаем "цель" до достижимых позиций
class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= goal) goal = i;
        }
        return goal == 0;
    }
};
// Временная сложность: O(n) 
// Пространственная сложность: O(1) 