#include "../../common/leetcode_common.h"

class Solution {
public:
    std::vector<int> TopKFrequent(std::vector<int>& nums, int k) {
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
    struct Case { vector<int> nums_; int k_; vector<int> expected_; };
    vector<Case> cases = {
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
        {{1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2, {1, 2}},
    };

    bool all_ok = true;
    Solution sol;
    for (auto c : cases) {
        auto result = sol.TopKFrequent(c.nums_, c.k_);
        vector<int> sorted_result = result;
        sort(sorted_result.begin(), sorted_result.end());
        vector<int> sorted_expected = c.expected_;
        sort(sorted_expected.begin(), sorted_expected.end());

        cout << "Input: nums = ";
        PrintVector(c.nums_);
        cout << ", k = " << c.k_ << "\nOutput: ";
        PrintVector(result);
        cout << " -- expected (any order) ";
        PrintVector(c.expected_);
        cout << "\n";
        bool ok = sorted_result == sorted_expected;
        all_ok = all_ok && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return all_ok ? 0 : 1;
}
