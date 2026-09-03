#include "../../common/leetcode_common.h"

class Solution {
 public:
  vector<int> DailyTemperatures(vector<int>& temperatures) {
    std::vector<int> result(temperatures.size(), 0);
    std::stack<int> st;
    for (int i = temperatures.size() - 1; i >= 0; i--) {
      while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
        st.pop();
      }
      if (!st.empty()) {
        result[i] = st.top() - i;
      }
      st.push(i);
    }
    return result;
  }
};
// Временная сложность: O(n)
// Пространственная сложность: O(n)

int main() {
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution sol;
  auto result = sol.DailyTemperatures(temperatures);

  cout << "Input: temperatures = ";
  PrintVector(temperatures);
  cout << "\nOutput: ";
  PrintVector(result);
  vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  cout << " -- expected ";
  PrintVector(expected);
  cout << "\n";

  bool ok = result == expected;
  cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  return ok ? 0 : 1;
}
