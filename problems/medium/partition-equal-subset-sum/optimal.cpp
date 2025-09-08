#include <vector>
using namespace std;

#include <vector>
using namespace std;

class Solution {
public:
    // Главная функция: возвращает true, если nums можно разбить на два подмножества с равной суммой
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // Считаем сумму всех элементов
        for (int x : nums) sum += x;

        // Если сумма нечётная, расколоть на две равные части невозможно
        if (sum % 2 != 0) return false;

        int target = sum / 2; // Целевая сумма для каждого подмножества

        // dp[j]: можно ли собрать сумму j из элементов массива (true/false)
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Сумму 0 можно собрать всегда (пустым множеством)

        // Перебираем все числа в nums
        for (int num : nums) {
            // Важно: перебираем суммы вниз, чтобы использовать каждый элемент только один раз!
            for (int j = target; j >= num; --j) {
                // Если сумму (j - num) можно собрать, то и сумму j можно собрать (добавив num)
                dp[j] = dp[j] || dp[j - num];
            }
        }
        // Итог: можем ли собрать точно половину всей суммы?
        return dp[target];
    }
};

// Временная сложность: O(n * target), где n — размер массива, target — половина суммы
// Пространственная сложность: O(target)
