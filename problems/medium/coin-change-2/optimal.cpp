#include "../../common/leetcode_common.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i] = количество способов получить сумму i
        vector<int> dp(amount + 1, 0);
        
        // База: есть 1 способ получить сумму 0 (не брать никаких монет)
        dp[0] = 1;
        
        // ВАЖНО: сначала перебираем монеты, потом суммы
        // Это гарантирует, что мы не учитываем порядок монет
        // (избегаем дублирования комбинаций типа {1,2} и {2,1})
        for (int coin : coins) {
            // Для каждой монеты обновляем все возможные суммы
            for (int i = coin; i <= amount; i++) {
                // dp[i] += dp[i - coin] означает:
                // к текущему количеству способов получить сумму i
                // добавляем количество способов получить сумму (i - coin)
                // (так как мы можем добавить текущую монету)
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};


int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    Solution sol;
    int result = sol.change(amount, coins);

    cout << "Input: amount = 5, coins = [1,2,5]\n";
    cout << "Output: " << result << " -- expected 4\n";

    bool ok = result == 4;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
