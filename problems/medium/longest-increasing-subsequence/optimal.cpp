#include <vector>
#include <algorithm>

using namespace std;

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
