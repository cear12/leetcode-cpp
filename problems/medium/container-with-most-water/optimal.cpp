class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;
            
            maxWater = max(maxWater, currentArea);
            
            // Двигаем указатель на меньшую стенку
            // Потому что если двигать указатель на большую стенку:
            // - ширина уменьшится
            // - высота не увеличится (ограничена меньшей стенкой)
            // - площадь точно не увеличится
            if (height[left] < height[right]) {
                left++;   // Ищем более высокую левую стенку
            } else {
                right--;  // Ищем более высокую правую стенку
            }
        }
        
        return maxWater;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(1)
