#include "../../common/leetcode_common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            maxWater = max(maxWater, width * minHeight);
            
            // Пропускаем все линии, которые короче или равны текущей
            // Они точно не улучшат результат при уменьшающейся ширине
            if (height[left] < height[right]) {
                int currentLeft = height[left];
                // Двигаем левый указатель пока не найдём более высокую линию
                while (left < right && height[left] <= currentLeft) {
                    left++;
                }
            } else {
                int currentRight = height[right];
                // Двигаем правый указатель пока не найдём более высокую линию
                while (left < right && height[right] <= currentRight) {
                    right--;
                }
            }
        }
        
        return maxWater;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    int result = sol.maxArea(height);

    cout << "Input: height = ";
    printVector(height);
    cout << "\nOutput: " << result << " -- expected 49\n";

    bool ok = result == 49;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
