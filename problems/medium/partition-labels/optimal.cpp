#include "../../common/leetcode_common.h"

// Greedy: record the last index each character occurs at, then grow a
// window until it reaches the farthest "last occurrence" seen so far among
// the characters inside it -- that's exactly where a partition can close.
class Solution {
 public:
  vector<int> PartitionLabels(const string& s) {
    vector<int> last(26);
    for (int i = 0; i < static_cast<int>(s.size()); ++i) last[s[i] - 'a'] = i;

    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      end = max(end, last[s[i] - 'a']);
      if (i == end) {
        result.push_back(end - start + 1);
        start = i + 1;
      }
    }
    return result;
  }
};
// Временная сложность: O(n) -- один проход по строке.
// Пространственная сложность: O(1) -- фиксированный массив из 26 латинских
// букв.

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
