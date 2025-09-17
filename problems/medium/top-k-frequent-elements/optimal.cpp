#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, count] : freq)
            buckets[count].push_back(num);
        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i)
            for (int num : buckets[i])
                if (result.size() < k) result.push_back(num);
        return result;
    }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)
