class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Шаг 1: находим первую позицию i справа, где nums[i] < nums[i + 1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        // Шаг 2: если нашли такую позицию i, ищем ближайший справа элемент j, который больше nums[i]
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }

        // Шаг 3: переворачиваем "хвост" справа от позиции i
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
