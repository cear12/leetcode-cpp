// Time: O(n), Space: O(n)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDP(n), minDP(n);
        maxDP[0] = minDP[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            maxDP[i] = max({nums[i], nums[i] * maxDP[i - 1], nums[i] * minDP[i - 1]});
            minDP[i] = min({nums[i], nums[i] * maxDP[i - 1], nums[i] * minDP[i - 1]});
            ans = max(ans, maxDP[i]);
        }
        return ans;
    }
};
