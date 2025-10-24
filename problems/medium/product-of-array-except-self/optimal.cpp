class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        int leftProd = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = leftProd;
            leftProd *= nums[i];
        }

        int rightProd = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= rightProd;
            rightProd *= nums[i];
        }

        return answer;
    }
};
// Время: O(n)
// Память: O(1)

// Временная сложность: O(n)
// Пространственная сложность: O(1)
