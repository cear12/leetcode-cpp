class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        std::ios_base::sync_with_stdio( 0 );
        std::cin.tie( 0 );

        int result = 0;
        int start = 0;
        int zeroes = 0;

        for( int i = 0; i < nums.size(); ++i )
        {
            zeroes += !nums[ i ];

            while( zeroes > 1 )
            {
                zeroes -= !nums[ start++ ];
            }

            result = std::max( result, i - start );
        }

        return result;        
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
