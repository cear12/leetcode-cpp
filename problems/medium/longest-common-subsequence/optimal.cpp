class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const auto text1Size = text1.size();
        const auto text2Size = text2.size();

        vector< vector< int > > dp( text1Size + 1, vector< int >( text2Size + 1, 0 ) );

        for( int i = 1; i <= text1Size; ++i )
        {
            for( int j = 1; j <= text2Size; ++j )
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
