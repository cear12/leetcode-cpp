// Альтернативное решение: Динамическое программирование
class Solution {
public:
    int jump(const std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (j + nums[j] >= i && dp[j] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};
// Временная сложность: O(n2)
// Пространственная сложность: O(n)
