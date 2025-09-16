#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& s : strs) {
            int cnt[26] = {0};
            for (char c : s) ++cnt[c - 'a'];
            std::ostringstream os;
            for (int i = 0; i < 26; ++i) {
                os << cnt[i] << '#';
            }
            groups[os.str()].push_back(s);
        }
        std::vector<std::vector<std::string>> res;
        for (auto& [_, group] : groups) res.push_back(std::move(group));
        return res;
    }
};

// Временная сложность: O(nk)
// Пространственная сложность: O(nk)
