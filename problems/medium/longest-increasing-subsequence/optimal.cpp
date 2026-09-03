#include "../../common/leetcode_common.h"

class Solution {
 public:
  int LengthOfLis(vector<int>& nums) {
    vector<int> lis;  // lis[i] — минимальный возможный последний элемент
                      // возрастающей подпоследовательности длины i+1

    for (int num : nums) {
      // Находим позицию, где num может быть вставлен в lis (или заменить
      // существующий элемент). lower_bound возвращает первый элемент >= num.
      auto it = lower_bound(lis.begin(), lis.end(), num);

      if (it == lis.end()) {
        // Если все элементы в lis меньше num — расширяем LIS: добавляем num как
        // новый "верхний край".
        lis.push_back(num);
      } else {
        // Если найден элемент >= num — заменяем его на num.
        // Это сохраняет возможность построить более длинные LIS в будущем,
        // минимизируя последние элементы подпоследовательностей каждой длины.
        *it = num;
      }
    }
    // Размер lis — это длина самой длинной возрастающей подпоследовательности
    return lis.size();
  }
};

// Временная сложность: O(n log n)
// Пространственная сложность: O(n)

int main() {
  struct Case {
    vector<int> nums_;
    int expected_;
  };
  vector<Case> cases = {
      {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
      {{0, 1, 0, 3, 2, 3}, 4},
      {{7, 7, 7, 7, 7, 7, 7}, 1},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    int result = sol.LengthOfLis(c.nums_);
    cout << "Input: nums = ";
    PrintVector(c.nums_);
    cout << "\nOutput: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
