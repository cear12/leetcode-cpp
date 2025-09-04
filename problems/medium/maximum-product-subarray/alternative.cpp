// Time: O(n), Space: O(1)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], left = 1, right = 1, n = nums.size();
        for (int i = 0; i < n; ++i) {
            left = (left == 0 ? 1 : left) * nums[i];
            right = (right == 0 ? 1 : right) * nums[n - 1 - i];
            ans = max(ans, max(left, right));
        }
        return ans;
    }
};
