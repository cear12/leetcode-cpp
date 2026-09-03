#include "../../common/leetcode_common.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis; // lis[i] — минимальный возможный последний элемент возрастающей подпоследовательности длины i+1

        for (int num : nums) {
            // Находим позицию, где num может быть вставлен в lis (или заменить существующий элемент).
            // lower_bound возвращает первый элемент >= num.
            auto it = lower_bound(lis.begin(), lis.end(), num);

            if (it == lis.end()) {
                // Если все элементы в lis меньше num — расширяем LIS: добавляем num как новый "верхний край".
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
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.lengthOfLIS(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
