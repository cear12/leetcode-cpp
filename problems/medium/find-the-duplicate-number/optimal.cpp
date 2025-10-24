// Алгоритм "черепаха и заяц", аналог задачи с циклом в связном списке
// Идея: индексы массива используются как “указатели”.
// nums[i] указывает на следующий индекс.
// Повторяющийся элемент создаёт цикл.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Этап 1: поиск пересечения в "цикле"
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Этап 2: нахождение входа в цикл (дубликата)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
