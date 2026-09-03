#include "../../common/leetcode_common.h"

class Solution {
 public:
  int LengthOfLongestSubstring(string s) {
    // Словарь для хранения последней позиции каждого символа
    unordered_map<char, int> char_index;
    int max_length = 0;
    int left = 0;  // Левая граница окна

    // Правая граница окна расширяется с каждой итерацией
    for (int right = 0; right < static_cast<int>(s.length()); right++) {
      char current_char = s[right];

      // Если символ уже встречался в текущем окне
      if (char_index.find(current_char) != char_index.end() &&
          char_index[current_char] >= left) {
        // Сдвигаем левую границу за последнее вхождение символа
        left = char_index[current_char] + 1;
      }

      // Обновляем позицию текущего символа
      char_index[current_char] = right;

      // Обновляем максимальную длину
      max_length = max(max_length, right - left + 1);
    }

    return max_length;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(min(m,n)) где m — размер алфавита

int main() {
  struct Case {
    string s_;
    int expected_;
  };
  vector<Case> cases = {
      {"abcabcbb", 3},
      {"bbbbb", 1},
      {"pwwkew", 3},
  };

  bool all_ok = true;
  Solution sol;
  for (const auto& c : cases) {
    int result = sol.LengthOfLongestSubstring(c.s_);
    cout << "Input: s = \"" << c.s_ << "\"\n";
    cout << "Output: " << result << " -- expected " << c.expected_ << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
