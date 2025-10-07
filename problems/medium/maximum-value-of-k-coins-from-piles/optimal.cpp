class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        // dp[i][j] = максимальная ценность при использовании первых i куч и взятии j монет
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // Обрабатываем каждую кучу
        for (int i = 1; i <= n; i++) {
            // Вычисляем префиксные суммы для текущей кучи
            // prefix[j] = сумма первых j монет в куче piles[i-1]
            vector<int> prefix(piles[i-1].size() + 1, 0);
            for (int j = 1; j <= piles[i-1].size(); j++) {
                prefix[j] = prefix[j-1] + piles[i-1][j-1];
            }
            
            // Для каждого количества монет j
            for (int j = 0; j <= k; j++) {
                // Пробуем взять take монет из текущей кучи (от 0 до min(размер_кучи, j))
                for (int take = 0; take < prefix.size() && take <= j; take++) {
                    // Обновляем максимум:
                    // dp[i-1][j-take] - оптимальный результат без текущей кучи с (j-take) монетами
                    // prefix[take] - ценность take монет из текущей кучи
                    dp[i][j] = max(dp[i][j], dp[i-1][j-take] + prefix[take]);
                }
            }
        }
        
        return dp[n][k];
    }
};
