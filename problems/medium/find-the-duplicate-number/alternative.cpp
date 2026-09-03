#include "../../common/leetcode_common.h"

// Метод с использованием "принципа Дирихле" (Pigeonhole principle)
// Мы не ищем по индексам, а по диапазону значений [1..n].

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Считаем, сколько чисел <= mid
            int count = 0;
            for (int num : nums)
                if (num <= mid)
                    ++count;

            // Если чисел больше, чем mid — дубликат в левой половине
            if (count > mid)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
// Время: O(N log N), память: O(1)

int main() {
    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{1, 3, 4, 2, 2}, 2},
        {{3, 1, 3, 4, 2}, 3},
        {{3, 3, 3, 3, 3}, 3},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        int result = sol.findDuplicate(c.nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: " << result << " -- expected " << c.expected << "\n";
        bool ok = result == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}

