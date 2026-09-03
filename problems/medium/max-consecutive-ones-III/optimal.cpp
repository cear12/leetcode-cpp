#include "../../common/leetcode_common.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio( 0 );
        std::cin.tie( 0 );

        int result = 0;
        int start = 0;
        int zeroes = 0;

        for( int i = 0; i < static_cast<int>(nums.size()); ++i )
        {
            zeroes += !nums[ i ];

            while( zeroes > k )
            {
                zeroes -= !nums[ start++ ];
            }

            result = std::max( result, i - start + 1 );
        }

        return result;       
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    struct Case { vector<int> nums; int k; int expected; };
    vector<Case> cases = {
        {{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6},
        {{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.longestOnes(c.nums, c.k);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << ", k = " << c.k << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
