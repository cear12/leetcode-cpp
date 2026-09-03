#include "../../common/leetcode_common.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const auto text1Size = text1.size();
        const auto text2Size = text2.size();

        vector< vector< int > > dp( text1Size + 1, vector< int >( text2Size + 1, 0 ) );

        for( int i = 1; i <= static_cast<int>(text1Size); ++i )
        {
            for( int j = 1; j <= static_cast<int>(text2Size); ++j )
            {
                if( text1[ i - 1 ] == text2[ j - 1 ] )
                {
                    dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] + 1;
                }
                else
                {
                    dp[ i ][ j ] = std::max( dp[ i ][ j - 1 ], dp[ i - 1 ][ j ] );
                }
            }   
        }

        return dp[ text1Size ][ text2Size ];       
    }
};
// Время: O(m*n)
// Память: O(m*n)

int main() {
    struct Case { string text1; string text2; int expected; };
    vector<Case> cases = {
        {"abcde", "ace", 3},
        {"abc", "abc", 3},
        {"abc", "def", 0},
    };

    bool allOk = true;
    Solution sol;
    for (const auto& c : cases) {
        int result = sol.longestCommonSubsequence(c.text1, c.text2);
        cout << "Input: text1 = \"" << c.text1 << "\", text2 = \"" << c.text2 << "\"\n";
        cout << "Output: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
