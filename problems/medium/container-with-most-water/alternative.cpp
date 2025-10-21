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
