#include "../../common/leetcode_common.h"

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        std::vector<std::pair<int, int>> v;
        for (const auto& p : freq)
            v.emplace_back(p.first, p.second);
        std::sort(v.begin(), v.end(),
                  [](auto& a, auto& b) { return a.second > b.second; });
        std::vector<int> result;
        for (int i = 0; i < k && i < static_cast<int>(v.size()); ++i)
            result.push_back(v[i].first);
        return result;
    }
};
// Временная сложность: O(nlogn)
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
