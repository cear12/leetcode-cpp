#include "../../common/leetcode_common.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Шаг 1: находим первую позицию pivot, где последовательность перестаёт быть невозрастающей
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Если вся последовательность невозрастающая — это последняя перестановка
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Шаг 2: ищем элемент справа, немного больший nums[pivot]
        for (int j = n - 1; j > pivot; --j) {
            if (nums[j] > nums[pivot]) {
                swap(nums[pivot], nums[j]);
                break;
            }
        }

        // Шаг 3: инвертируем список после pivot вручную
        int left = pivot + 1, right = n - 1;
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};


int main() {
    struct Case { vector<int> nums; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3}, {1, 3, 2}},
        {{3, 2, 1}, {1, 2, 3}},
        {{1, 1, 5}, {1, 5, 1}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        vector<int> nums = c.nums;
        sol.nextPermutation(nums);
        cout << "Input: nums = ";
        printVector(c.nums);
        cout << "\nOutput: ";
        printVector(nums);
        cout << " -- expected ";
        printVector(c.expected);
        cout << "\n";
        bool ok = nums == c.expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
