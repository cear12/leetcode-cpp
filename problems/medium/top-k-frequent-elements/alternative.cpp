#include <vector>
#include <unordered_map>
#include <algorithm>

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
        for (int i = 0; i < k && i < v.size(); ++i)
            result.push_back(v[i].first);
        return result;
    }
};
// Временная сложность: O(nlogn)
// Пространственная сложность: O(n)
