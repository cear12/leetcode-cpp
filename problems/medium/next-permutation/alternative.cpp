#include "../../common/leetcode_common.h"

class Solution {
public:
    void NextPermutation(vector<int>& nums) {
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
    struct Case { vector<int> nums_; vector<int> expected_; };
    vector<Case> cases = {
        {{1, 2, 3}, {1, 3, 2}},
        {{3, 2, 1}, {1, 2, 3}},
        {{1, 1, 5}, {1, 5, 1}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        vector<int> nums = c.nums_;
        sol.NextPermutation(nums);
        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << "\nOutput: ";
        PrintVector(nums);
        cout << " -- expected ";
        PrintVector(c.expected_);
        cout << "\n";
        bool ok = nums == c.expected_;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
