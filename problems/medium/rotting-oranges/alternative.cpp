#include <vector>

using namespace std;

// DFS (медленнее, но наглядно)
class Solution {
    int m, n;
    vector<pair<int, int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(); n = grid.size();
        int maxTime = 0;
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if (grid[i][j]==2)
                    dfs(grid, i, j, 0, maxTime);
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j)
                if (grid[i][j]==1) return -1;
        return maxTime;
    }
private:
    void dfs(vector<vector<int>>& g, int x, int y, int time, int& maxTime) {
        maxTime = max(maxTime, time);
        for (auto [dx,dy] : dirs) {
            int nx = x+dx, ny = y+dy;
            if (nx>=0 && nx<m && ny>=0 && ny<n && g[nx][ny]==1) {
                g[nx][ny]=2;
                dfs(g, nx, ny, time+1, maxTime);
            }
        }
    }
};
// Время: O((m·n)²)  Память: O(m·n)
