#include "../../common/leetcode_common.h"

class Solution {
 public:
  std::vector<std::vector<std::string>> GroupAnagrams(
      std::vector<std::string>& strs) {
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

// Group order and within-group order are unspecified by the problem, so
// comparison canonicalizes both: sort strings within each group, then sort
// the list of groups by their (now-sorted) first element.
vector<vector<string>> Canonicalize(vector<vector<string>> groups) {
  for (auto& g : groups) sort(g.begin(), g.end());
  sort(groups.begin(), groups.end(),
       [](const vector<string>& a, const vector<string>& b) {
         return a[0] < b[0];
       });
  return groups;
}

int main() {
  struct Case {
    vector<string> strs_;
    vector<vector<string>> expected_;
  };
  vector<Case> cases = {
      {{"eat", "tea", "tan", "ate", "nat", "bat"},
       {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
      {{"a"}, {{"a"}}},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    auto result = Canonicalize(sol.GroupAnagrams(c.strs_));
    auto expected = Canonicalize(c.expected_);
    cout << "Input: strs = ";
    PrintVector(c.strs_);
    cout << "\nOutput: ";
    PrintVector2D(result);
    cout << " -- expected (any order) ";
    PrintVector2D(expected);
    cout << "\n";
    bool ok = result == expected;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
