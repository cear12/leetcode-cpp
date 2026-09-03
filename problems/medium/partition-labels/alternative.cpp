#include "../../common/leetcode_common.h"

// Same greedy idea as optimal.cpp, but keyed by an unordered_map<char, int>
// instead of a fixed 26-entry array -- a more general (if slightly slower)
// way to track each character's last index.
class Solution {
 public:
  vector<int> PartitionLabels(const string& s) {
    unordered_map<char, int> last;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) last[s[i]] = i;

    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      end = max(end, last[s[i]]);
      if (i == end) {
        result.push_back(end - start + 1);
        start = i + 1;
      }
    }
    return result;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(k), где k -- количество уникальных символов.

int main() {
  Solution sol;

  string s1 = "ababcbacadefegdehijhklij";
  auto result1 = sol.PartitionLabels(s1);
  cout << "Input: s = \"" << s1 << "\"\n";
  cout << "Output: ";
  PrintVector(result1);
  cout << " -- expected [9, 7, 8]\n";
  vector<int> expected1 = {9, 7, 8};
  bool ok1 = result1 == expected1;
  cout << "[" << (ok1 ? "PASS" : "FAIL") << "]\n";

  string s2 = "eccbbbbdec";
  auto result2 = sol.PartitionLabels(s2);
  cout << "Input: s = \"" << s2 << "\"\n";
  cout << "Output: ";
  PrintVector(result2);
  cout << " -- expected [10]\n";
  vector<int> expected2 = {10};
  bool ok2 = result2 == expected2;
  cout << "[" << (ok2 ? "PASS" : "FAIL") << "]\n";

  return (ok1 && ok2) ? 0 : 1;
}
