#include "../../common/leetcode_common.h"

class Solution {
public:
    int MaxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            int width = right - left;
            int min_height = min(height[left], height[right]);
            max_water = max(max_water, width * min_height);
            
            // Пропускаем все линии, которые короче или равны текущей
            // Они точно не улучшат результат при уменьшающейся ширине
            if (height[left] < height[right]) {
                int current_left = height[left];
                // Двигаем левый указатель пока не найдём более высокую линию
                while (left < right && height[left] <= current_left) {
                    left++;
                }
            } else {
                int current_right = height[right];
                // Двигаем правый указатель пока не найдём более высокую линию
                while (left < right && height[right] <= current_right) {
                    right--;
                }
            }
        }
        
        return max_water;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    int result = sol.MaxArea(height);

    cout << "Input: height = ";
    PrintVector(height);
    cout << "\nOutput: " << result << " -- expected 49\n";

    bool ok = result == 49;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    return ok ? 0 : 1;
}
