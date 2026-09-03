#include "../../common/leetcode_common.h"

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

// Group order and within-group order are unspecified by the problem, so
// comparison canonicalizes both: sort strings within each group, then sort
// the list of groups by their (now-sorted) first element.
vector<vector<string>> canonicalize(vector<vector<string>> groups) {
    for (auto& g : groups) sort(g.begin(), g.end());
    sort(groups.begin(), groups.end(),
         [](const vector<string>& a, const vector<string>& b) { return a[0] < b[0]; });
    return groups;
}

int main() {
    struct Case { vector<string> strs; vector<vector<string>> expected; };
    vector<Case> cases = {
        {{"eat", "tea", "tan", "ate", "nat", "bat"},
         {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
        {{"a"}, {{"a"}}},
    };

    bool allOk = true;
    Solution sol;
    for (auto c : cases) {
        auto result = canonicalize(sol.groupAnagrams(c.strs));
        auto expected = canonicalize(c.expected);
        cout << "Input: strs = ";
        printVector(c.strs);
        cout << "\nOutput: ";
        printVector2D(result);
        cout << " -- expected (any order) ";
        printVector2D(expected);
        cout << "\n";
        bool ok = result == expected;
        allOk = allOk && ok;
        cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
    }
    return allOk ? 0 : 1;
}

