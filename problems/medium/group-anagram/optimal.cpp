#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto& [_, group] : groups) result.push_back(std::move(group));
        return result;
    }
};

// Временная сложность: O(n⋅klogk)
// Пространственная сложность: O(nk)
