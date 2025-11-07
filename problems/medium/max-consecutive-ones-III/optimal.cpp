class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio( 0 );
        std::cin.tie( 0 );

        int result = 0;
        int start = 0;
        int zeroes = 0;

        for( int i = 0; i < nums.size(); ++i )
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
