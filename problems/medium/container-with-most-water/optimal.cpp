#include "../../common/leetcode_common.h"

class Solution {
 public:
  int MaxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
      int width = right - left;
      int current_height = min(height[left], height[right]);
      int current_area = width * current_height;

      max_water = max(max_water, current_area);

      // Двигаем указатель на меньшую стенку
      // Потому что если двигать указатель на большую стенку:
      // - ширина уменьшится
      // - высота не увеличится (ограничена меньшей стенкой)
      // - площадь точно не увеличится
      if (height[left] < height[right]) {
        left++;  // Ищем более высокую левую стенку
      } else {
        right--;  // Ищем более высокую правую стенку
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
