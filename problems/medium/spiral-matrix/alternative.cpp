#include "../../common/leetcode_common.h"

// Решение 2: Вектор направлений + матрица посещённых
class Solution {
 public:
  vector<int> SpiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visite(m, vector<bool>(n, false));
    vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
    int r = 0, c = 0, di = 0;
    vector<int> ans;
    for (int k = 0; k < m * n; ++k) {
      ans.push_back(matrix[r][c]);
      visite[r][c] = true;
      int nr = r + dr[di], nc = c + dc[di];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visite[nr][nc]) {
        r = nr;
        c = nc;
      } else {
        di = (di + 1) % 4;
        r += dr[di];
        c += dc[di];
      }
    }
    return ans;
  }
};
// Временная сложность: O(m * n)
// Пространственная сложность: O(m * n)

int main() {
  struct Case {
    vector<vector<int>> matrix_;
    vector<int> expected_;
  };
  vector<Case> cases = {
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}},
      {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
       {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
  };

  bool all_ok = true;
  Solution sol;
  for (auto c : cases) {
    vector<vector<int>> matrix = c.matrix_;
    auto result = sol.SpiralOrder(matrix);
    cout << "Input: matrix = ";
    PrintVector2D(c.matrix_);
    cout << "\nOutput: ";
    PrintVector(result);
    cout << " -- expected ";
    PrintVector(c.expected_);
    cout << "\n";
    bool ok = result == c.expected_;
    all_ok = all_ok && ok;
    cout << "[" << (ok ? "PASS" : "FAIL") << "]\n";
  }
  return all_ok ? 0 : 1;
}
