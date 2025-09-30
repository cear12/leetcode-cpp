// Решение 2: Вектор направлений + матрица посещённых
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
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
                r = nr; c = nc;
            } else {
                di = (di + 1) % 4;
                r += dr[di]; c += dc[di];
            }
        }
        return ans;
    }
};
// Временная сложность: O(m * n)
// Пространственная сложность: O(m * n)
