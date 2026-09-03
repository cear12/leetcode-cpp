#include "../../common/leetcode_common.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // Сортируем по убыванию - самые ценные монеты в начале
        sort(piles.rbegin(), piles.rend());
        
        int result = 0;
        int n = piles.size() / 3;  // количество раундов игры
        
        // Стратегия: Боб всегда берёт максимальную монету
        // Мы должны взять вторую по величине из оставшихся
        // Алиса получает минимальную
        
        // Берём каждую вторую монету из первых 2n элементов
        // Пример: [9,8,7,6,5,1] -> берём 8, 6 (индексы 1, 3)
        for (int i = 1; i < 2 * n; i += 2) {
            result += piles[i];  // Это наши монеты (вторые по величине в каждом раунде)
        }
        
        return result;
    }
};
int main() {
    struct Case { vector<int> piles; int expected; };
    vector<Case> cases = {
        {{2, 4, 1, 2, 7, 8}, 9},
        {{2, 4, 5}, 4},
        {{9, 8, 7, 6, 5, 1, 2, 3, 4}, 18},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.maxCoins(c.piles);
        cout << "Input: piles = ";
        printVector(c.piles);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
