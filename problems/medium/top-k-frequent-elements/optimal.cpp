#include "../../common/leetcode_common.h"

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, count] : freq)
            buckets[count].push_back(num);
        std::vector<int> result;
        for (int i = static_cast<int>(buckets.size()) - 1; i >= 0 && static_cast<int>(result.size()) < k; --i)
            for (int num : buckets[i])
                if (static_cast<int>(result.size()) < k) result.push_back(num);
        return result;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
    struct Case { vector<int> nums; int k; vector<int> expected; };
    vector<Case> cases = {
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
        {{1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2, {1, 2}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        auto result = sol.topKFrequent(c.nums, c.k);
        vector<int> sortedResult = result;
        sort(sortedResult.begin(), sortedResult.end());
        vector<int> sortedExpected = c.expected;
        sort(sortedExpected.begin(), sortedExpected.end());

        cout << "Input: nums = ";
        printVector(c.nums);
        cout << ", k = " << c.k << "\nOutput: ";
        printVector(result);
        cout << " -- expected (any order) ";
        printVector(c.expected);
        cout << "\n";
        bool ok = sortedResult == sortedExpected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}
