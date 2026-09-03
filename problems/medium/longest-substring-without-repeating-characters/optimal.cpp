#include "../../common/leetcode_common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Словарь для хранения последней позиции каждого символа
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0; // Левая граница окна
        
        // Правая граница окна расширяется с каждой итерацией
        for (int right = 0; right < static_cast<int>(s.length()); right++) {
            char currentChar = s[right];
            
            // Если символ уже встречался в текущем окне
            if (charIndex.find(currentChar) != charIndex.end() && 
                charIndex[currentChar] >= left) {
                // Сдвигаем левую границу за последнее вхождение символа
                left = charIndex[currentChar] + 1;
            }
            
            // Обновляем позицию текущего символа
            charIndex[currentChar] = right;
            
            // Обновляем максимальную длину
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(min(m,n)) где m — размер алфавита

int main() {
    struct Case { string s; int expected; };
    vector<Case> cases = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
    };

    bool allOk = true;
    Solution sol;
    for (const auto& c : cases) {
        int result = sol.lengthOfLongestSubstring(c.s);
        cout << "Input: s = \"" << c.s << "\"\n";
        cout << "Output: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
