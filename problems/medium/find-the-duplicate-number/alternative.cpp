// Метод с использованием "принципа Дирихле" (Pigeonhole principle)
// Мы не ищем по индексам, а по диапазону значений [1..n].

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Считаем, сколько чисел <= mid
            int count = 0;
            for (int num : nums)
                if (num <= mid)
                    ++count;

            // Если чисел больше, чем mid — дубликат в левой половине
            if (count > mid)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
// Время: O(N log N), память: O(1)
