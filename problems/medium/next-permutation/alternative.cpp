class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Шаг 1: находим первую позицию pivot, где последовательность перестаёт быть невозрастающей
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Если вся последовательность невозрастающая — это последняя перестановка
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Шаг 2: ищем элемент справа, немного больший nums[pivot]
        for (int j = n - 1; j > pivot; --j) {
            if (nums[j] > nums[pivot]) {
                swap(nums[pivot], nums[j]);
                break;
            }
        }

        // Шаг 3: инвертируем список после pivot вручную
        int left = pivot + 1, right = n - 1;
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};

