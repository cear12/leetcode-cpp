#include "../../common/leetcode_common.h"

class Solution {
public:
    int CoinChange(vector<int>& coins, int amount) {
        vector<int> dp( amount + 1, INT_MAX ); 

        dp[ 0 ] = 0;

        for( int i = 1; i <= amount; ++i )
        {
            for( auto&& coin : coins )
            {
                if( i - coin >= 0 && dp[ i - coin ] != INT_MAX )
                {
                    dp[ i ] = std::min( dp[ i ], dp[ i - coin ] + 1 );
                }
            }
        }

        return dp[ amount ] == INT_MAX ? -1 : dp[ amount ];  
    }
};
// Временная сложность: O(amount * k), где k — количество монет
// Пространственная сложность: O(amount)

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution sol;
    int result = sol.CoinChange(coins, amount);

    cout << "Input: coins = [1,2,5], amount = 11\n";
    cout << "Output: " << result << " -- expected 3\n";

    bool ok = result == 3;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
